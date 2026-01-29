#!/usr/bin/bash

testDir="unit"
resultDir="result"
buildDir="build"
compiler="cargo"

colorSucces="\033[32m\033[1m"
colorFailed="\033[31m\033[1m"
colorReset="\033[0m"

mkdir --parents "$resultDir"
mkdir --parents "$buildDir"

ntest=0
ntestOk=0
exitCode=0

for test in "$testDir"/*
do
    testOk=1
    unitnameFull=${test%.*}
    unitname=$(basename "$unitnameFull")

    echo "=== Test n°$ntest : $unitname ==="
    echo 

    # Compilation
    spath=$(cat $testDir/$unitname/path)
    toml="$spath/Cargo.toml"
    if [ -f "$toml" ]
    then
        mkdir --parents $buildDir/$unitname/
        cp -rf $spath/* $buildDir/$unitname/
        echo -ne "[package]\nname = \"$unitname\"\nversion = \"0.1.0\"\nedition = \"2021\"" > "$buildDir/$unitname/Cargo.toml"
        $compiler build --manifest-path "$buildDir/$unitname/Cargo.toml"
    else
        echo "=== $unitname: BUILDING"
        $compiler new "$buildDir/$unitname"

        cp -rf $spath/$(cat $testDir/$unitname/files) $buildDir/$unitname/src/
        cp -rf $testDir/$unitname/in.rs $buildDir/$unitname/src/main.rs
        $compiler build --manifest-path "$buildDir/$unitname/Cargo.toml"
    fi
    if [ $? -ne 0 ]
    then 
        echo "=== $unitname: BUILD FAILED"
        testOk=0
        ((ntest++))
        echo
        continue
    else
        echo "=== $unitname: BUILD SUCCESS"
    fi

    echo
    echo "=== RUN UNIT TEST ==="

    $compiler test --manifest-path "$buildDir/$unitname/Cargo.toml" 2> /dev/null

    # run command
    echo
    echo "=== RUN TEST ==="
    if [ -f "$testDir/$unitname/args" ]
    then
        xargs ./"$buildDir/$unitname/target/debug/$unitname" < "$testDir/$unitname/args" > $resultDir/$unitname.out 2> $resultDir/$unitname.err
    else
        ./"$buildDir/$unitname/target/debug/$unitname" > $resultDir/$unitname.out 2> $resultDir/$unitname.err
    fi
    echo $? > $resultDir/$unitname.code
    # Check
    commands=(
         "sdiff --suppress-common-lines $testDir/$unitname/out $resultDir/$unitname.out"
         "sdiff --suppress-common-lines $testDir/$unitname/err $resultDir/$unitname.err"
         "sdiff --suppress-common-lines $testDir/$unitname/code $resultDir/$unitname.code"
    )

    for cmd in "${commands[@]}"
    do
        $cmd
        if [ $? -ne 0 ]
        then
            testOk=0
        fi
    done

    if [ $testOk -eq 1 ]
    then
        echo -e $colorSucces"SUCCESS"$colorReset
        ((ntestOk++))
    else
        echo -e $colorFailed"FAILED"$colorReset
    fi
    ((ntest++))
    echo
done

if [ $ntest -ne $ntestOk ]
then
    exitCode=1
    echo "$ntestOk / $ntest"
    echo $(($ntestOk * 100 / $ntest))%
    rm -rf "$buildDir"
else
    echo -e $colorSucces"ALL TESTS PASS"$colorReset
    rm -rf "$resultDir"
    rm -rf "$buildDir"
fi

exit $exitCode

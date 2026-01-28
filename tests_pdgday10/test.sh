#!/usr/bin/bash

testDir="unit"
resultDir="result"
compiler="clang++ -Wall -Wextra -Werror -std=c++20"

colorSucces="\033[32m\033[1m"
colorFailed="\033[31m\033[1m"
colorReset="\033[0m"

mkdir --parents "$resultDir"

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
    echo "=== $unitname: BUILDING"
    $compiler ../*.cpp "$testDir/$unitname/in.cpp" -o "$unitname"
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
    
    # Run executable
    input_file="$testDir/$unitname/input"
    if [ -f "$input_file" ]; then
        ./"$unitname" < "$input_file" > "$resultDir/$unitname.out" 2> "$resultDir/$unitname.err"
    else
        ./"$unitname" > "$resultDir/$unitname.out" 2> "$resultDir/$unitname.err"
    fi
    echo $? > "$resultDir/$unitname.code"

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
    rm "$unitname"
    ((ntest++))
    echo
done

if [ $ntest -ne $ntestOk ]
then
    exitCode=1
    echo "$ntestOk / $ntest"
    echo $(($ntestOk * 100 / $ntest))%
else
    echo -e $colorSucces"ALL TESTS PASS"$colorReset
    rm -rf "$resultDir"
fi

exit $exitCode

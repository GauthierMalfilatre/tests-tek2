#!/usr/bin/env bash

searchDir="units"
resultDir="results"

exeBinary="../nanotekspice"
refBinary="ref.bin"

colorSucces="\033[32m\033[1m"
colorFailed="\033[31m\033[1m"
colorReset="\033[0m"

mkdir --parents $resultDir
ntest=0
ntestOk=0
exitCode=0

# Compilation
echo "=== BUILDING"
# Using -j for faster compilation.
make -C .. -j > /dev/null
if [ $? -ne 0 ]
then 
    echo "=== BUILD FAILED"
    testOk=0
    echo
    exit 0
else
    echo "=== BUILD SUCCESS"
    echo
fi

for test in "$searchDir"/*
do
    testOk=1
    testUnitFull=${test%.*}
    testUnit=$(basename $testUnitFull)

    echo === Test no $ntest : $testUnit ===

    $exeBinary "$searchDir/$testUnit/nts" < "$searchDir/$testUnit/in" > "$resultDir/$testUnit.out" 2> "$resultDir/$testUnit.err"
    echo $? > "$resultDir/$testUnit.code"

    if [ -x $searchDir/$testUnit/$refBinary ]
    then
        $searchDir/$testUnit/$refBinary "$searchDir/$testUnit/nts" < "$searchDir/$testUnit/in" > $searchDir/$testUnit/out 2> $searchDir/$testUnit/err
        echo $? > "$searchDir/$testUnit/code"
    fi

    commands=(
        "sdiff --suppress-common-lines $searchDir/$testUnit/out $resultDir/$testUnit.out"
        # "sdiff --suppress-common-lines $searchDir/$testUnit/err $resultDir/$testUnit.err"
        "sdiff --suppress-common-lines $searchDir/$testUnit/code $resultDir/$testUnit.code"
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
    echo $ntestOk / $ntest
    echo $(($ntestOk * 100 / $ntest))%
else
    echo -e $colorSucces"ALL TESTS PASS"$colorReset
    # rm -rf $resultDir
fi

exit $exitCode

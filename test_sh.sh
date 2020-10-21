#!/bin/bash
function test1(){
    input=${@:2:1}
    echo $input
    if [[ $input == "aa" ]];then
        return 1
    else
        return 0
    fi
}

test1 "first test" "bb"
echo $?
exit


path_1=`pwd`

echo current dir: ${path_1}
if [[ $# < 1 ]] 
then 
    echo "usage:sh eval"
fi

res_dir=$1
if [ -f $1-aaa.txt ]
then 
   echo "exit"
fi

test_dir=`readlink -f $0`
echo absolute dir: 
echo ${test_dir}

echo pwd: `pwd`

dirss=`pwd`
dirss=${dirss%/*}
echo finaltest
echo ${dirss}

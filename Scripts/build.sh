#!/bin/bash
progDir='/home/jacobhampton/Prog06/Prog06/'
exeDir="${progDir}Executable"
if [[ ! -d "$exeDir" ]]
then
    echo `mkdir ${exeDir}`
fi
vr=$1
for i in 1 2 3
do
    verDir="${progDir}Version$i"
    d="${verDir##*/}"
    ex="${d/V/v}"
    final=""
    for file in $verDir/*.cpp
    do
        f="${file##*/}"
        op="${f%.cpp}"
        if [[ $op != $ex ]]
        then
            f="${file##*/}"
            op="${f%.cpp}"
            g++ -std=c++14 -Wall -lstdc++ -lpthread -c $file 
        else
            final=$file
        fi
    done
    g++ -std=c++14 -Wall $final -lstdc++ -lpthread -o $ex *.o
    if (($i == $vr)); then
        ./$ex "/home/jacobhampton/Prog06/Prog06/Data/testNode.txt"
    fi 
    mv $ex "$exeDir"
    rm -f *.o
done
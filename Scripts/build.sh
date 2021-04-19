#!/bin/bash
progDir='/home/jacobhampton/Prog06/Prog06/'
exeDir="${progDir}Executable"
#echo `mkdir ${exeDir}`
if [[-d "$exeDir"]];
then
    echo worked
fi
#vr=$1
#count=0
for i in 1 2 3
do
    verDir="${progDir}Version$i"
    for file in $verDir/*.cpp
    do
        echo $file
        ##f="${file##*/}"
        ##ex="${f%.cpp}"
        ##g++ -std=c++14 -Wall $file -lstdc++ -lpthread -o $ex
    done
    ##mv $ex "${progDir%/*}"
    ##if (($count == $vr)); then
    ##    ./$ex "/home/jacobhampton/Prog05/Data/smallMap_Horiz.map" "sajhbd" 1 1 1
    ##fi 
done
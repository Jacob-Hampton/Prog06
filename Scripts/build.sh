#!/bin/bash
progDir='/home/jacobhampton/Prog06/Prog06/'
exeDir="${progDir}Executable"
if [[ ! -d "$exeDir" ]]
then
    echo `mkdir ${exeDir}`
fi
#vr=$1
#count=0
for i in 1 2 3
do
    verDir="${progDir}Version$i"
    for file in $verDir/*.cpp
    do
        f="${file##*/}"
        ex="${f%.cpp}"
        g++ -std=c++14 -Wall $file -lstdc++ -lpthread -o $ex
        mv $ex "$exeDir"
    done
    ##mv $ex "${progDir%/*}"
    ##if (($count == $vr)); then
    ##    ./$ex "/home/jacobhampton/Prog05/Data/smallMap_Horiz.map" "sajhbd" 1 1 1
    ##fi 
done
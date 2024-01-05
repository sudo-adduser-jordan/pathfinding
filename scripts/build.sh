#!/bin/bash

cd ..
PROJECT_DIRECTORY=$(pwd)
VERSION="-std=c++23"

mkdir $PROJECT_DIRECTORY/build/
mkdir $PROJECT_DIRECTORY/build/debug/

g++ $VERSION \
    -c *.cpp \

cd $PROJECT_DIRECTORY/structures/ 
g++ $VERSION \
    -c *.cpp \

cd $PROJECT_DIRECTORY/algorithms/ 
g++ $VERSION \
    -c *.cpp \

cd $PROJECT_DIRECTORY  
mv *.o $PROJECT_DIRECTORY/build/debug/
mv $PROJECT_DIRECTORY/algorithms/*.o $PROJECT_DIRECTORY/build/debug/
mv $PROJECT_DIRECTORY/structures/*.o $PROJECT_DIRECTORY/build/debug/
    
g++ $VERSION $PROJECT_DIRECTORY/build/debug/*.o -o $PROJECT_DIRECTORY/build/debug/Main.exe

#!/bin/bash

fileName=$1
cimVersion=$2
currDir=$(pwd)
cd ../examples/cmake/build/$cimVersion

./example $currDir/xml/$fileName wtf
mv $fileName.IdentifiedObjects.txt $currDir/outputs/$cimVersion/$fileName.IdentifiedObjects.txt

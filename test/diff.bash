#!/bin/bash

fileName=$1
cimVersion=$2
comm -3 <(sort outputs/$cimVersion/$fileName) <(sort solutions/$fileName)



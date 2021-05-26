#!/usr/bin/python
import subprocess
import filecmp
import os
from os import listdir
from os.path import isfile, join
import sys, os
# Define folder in which xmls are located

def main(argv):
    rootdir = './xml'
    print ("ARGS")
    cim_version = argv[0]
    print (cim_version)

    diffs = 0
    errors = 0
    testedFiles = []
    # Locate all dirs and files in rootdir
    dirs = [f for f in os.listdir(rootdir) if not isfile(join(rootdir, f))]
    files = [f for f in listdir(rootdir) if isfile(join(rootdir, f))]
    if not (os.path.isdir("outputs/")):
        bashCommand = "mkdir outputs"
        process = subprocess.call(bashCommand.split(), stdout=subprocess.PIPE)

    if not (os.path.isdir("outputs/" + cim_version)):
        bashCommand = "mkdir outputs/" + cim_version
        process = subprocess.call(bashCommand.split(), stdout=subprocess.PIPE)

    for dir in dirs:
        print ("-------------------------------------------")
        print ("Create output for folder " + dir)
        print ("-------------------------------------------")
        bashCommand = "./create_output.bash " + dir + " " + cim_version
        process = subprocess.Popen(bashCommand.split(), stdout=subprocess.PIPE)
        output, error = process.communicate()
        testedFiles.append(dir + ".IdentifiedObjects.txt")

    for file in files:
        print ("-------------------------------------------")
        print ("Create output for file " +file[0:len(file) - 4] + " " + file[0:len(file) - 4])
        print ("-------------------------------------------")
        bashCommand = "./create_output.bash  " + file[0:len(file) - 4] + " " + cim_version
        process = subprocess.Popen(bashCommand.split(), stdout=subprocess.PIPE)
        output, error = process.communicate()
        testedFiles.append(file[0:len(file) - 4] + ".IdentifiedObjects.txt")

    # For all files check if they match the expected output. Otherwise print the diffs
    for file in testedFiles:
        bashCommand = "./diff.bash " + file + " " + cim_version
        process = subprocess.Popen(bashCommand.split(), stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        out, err = process.communicate()
        print ("-------------------------------------------")
        print ("Results of " + file)
        print ("-------------------------------------------")
        if out and not out.isspace():
            print ("diff")
            print (out)
            diffs += 1
        elif err and not err.isspace():
            print ("err")
            errors += 1
            print (err)
        else:
            print ("File is okay")

    if diffs == 0 and errors == 0:
        print ("Everything fine")
        exit(0)
    else:
        print (diffs, " diffs occured")
        print (errors, " errors occured")
        exit(1)


if __name__ == "__main__":
    main(sys.argv[1:])

libcimpp
========
libcimpp is a deserialiser library for C++ objects from XML/RDF documents based on the Common Information Model (CIM) standards (i.e. IEC61970/61968/62325) for the energy sector.
It is part of the CIM++ project. More on CIM++ can be found [here](http://rdcu.be/vOop) and on the CIM++ [HomePage](http://fein-aachen.org/projects/cimpp).

## General information
limcimpp uses [arabica](http://www.jezuk.co.uk/cgi-bin/view/arabica) as cross platform wrapper around one of the XML parsers listed int the dependencies (see below).
It is recommended to use libcimpp as cmake module.

## Dependencies
You need following software packages for libcimpp:
+ The XML parser [Xerces](http://xerces.apache.org/xerces-c/)

## Install Xerces
### The UNIX / Linux way
Install Xerces via the package-manager e.g.:
```
sudo apt install libxerces-c-dev
```
### The Windows way with MS Visual Studio
1. Download the newest Version of [Xerces](https://xerces.apache.org/xerces-c/download.cgi)
2. Unzip the downloaded File to your desired location
3. Run the Windows CMake (GUI)
4. Set the
* source code directory, e.g.: `C:/repos/xerces-c.3.2.3`
* build directory, e.g.: `C:/repos/xerces-c.3.2.3`
5. Click on `Configure` and choose the Visual Studio project version, e.g.: `Visual Studio 15 2017`
6. Click on `Finish` and wait while CMake is configuring the project.
7. Click on `Generate` to generate the Visual Studio project files.
8. Click on `Open Project` to open the project in Visual Studio.
9. In Visual Studio's main menu choose `Build -> Build Solution`. This will build the `xerces` library.
10. In Visual Studio press on the `Developer-Shell` Button at the bottom-left.
 In case there is no such button press the Windows button on your keyboard and search for the `Developer Command Prompt for VS 2019`.
 It might be necessary to run the Shell with Administrator rights.
11. In the `Developer-Shell` type `cmake --build . --config Debug --target install` to install the xerces library.



## Get the Git repository
```bash
git clone https://github.com/RWTH-ACS/libcimpp.git
cd libcimpp
git submodule update --init --recursive
```

## Build instructions
### The UNIX / Linux / MacOS way
After getting the Git repository, create a build subdirectory and change into it:
```bash
mkdir build
cd build
```

For building libcimpp with the default CIM version, type:
```bash
cmake ..
make -j 4
```

For building libcimpp with a certain CIM version (e.g. `IEC61970_16v29a`), type:
```bash
cmake .. -DUSE_CIM_VERSION=IEC61970_16v29a
make -j 4
```
All available CIM versions can be determined in the [CMakeLists.txt](CMakeLists.txt)

### The Windows way with MS Visual Studio
1. After getting the Git repository, create a `build` subdirectory.
2. Run the Windows CMake (GUI)
3. Set the
* source code directory, e.g.: `C:/git/libcimpp`
* build directory, e.g.: `C:/git/libcimpp/build`
4. Press the `Add Entry` Button and set
* Name: CMAKE_PREFIX_PATH
* Type: PATH
* Value: Path to your xerces-c installation e.g. `C:/Program/xerces-c`
5. Click on `Configure` and choose the Visual Studio project version, e.g.: `Visual Studio 15 2017`
6. Click on `Finish` and wait while CMake is configuring the project.
7. Click on `Generate` to generate the Visual Studio project files.
8. Click on `Open Project` to open the project in Visual Studio.
9. In Visual Studio's main menu choose `Build -> Build Solution`. This will build the `libcimpp` library.

### Build instructions for using libcimpp as a cmake module
To be continued...


## Usage of the libcimpp library
For information how to use the library please see the [cmake based example](https://git.rwth-aachen.de/acs/core/cim/cimpp/libcimpp/tree/master/examples/cmake).
Building of the example can be performed analogous to bulding the library itself (as described in the *Build instructions* above).<br>
The pure make example is currently not supported due to the lack of an install target for arabica.

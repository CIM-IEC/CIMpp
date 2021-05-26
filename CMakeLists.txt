cmake_minimum_required(VERSION 3.5)

project(libcimpp CXX)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/" "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake")

add_subdirectory(doc)
find_package(XercesC REQUIRED)

set(libcimpp_MAJOR_VERSION 2)
set(libcimpp_MINOR_VERSION 1)
set(libcimpp_PATCH_VERSION 0)
set(libcimpp_VERSION ${libcimpp_MAJOR_VERSION}.${libcimpp_MINOR_VERSION}.${libcimpp_PATCH_VERSION})

# Options
option(BUILD_SHARED_LIBS "Build shared library" OFF)
option (BUILD_EXAMPLES "Build examples" OFF)

if(NOT USE_CIM_VERSION)
	set(USE_CIM_VERSION "CGMES_2.4.15_27JAN2020" CACHE STRING "Define CIM Version")
endif()

message(STATUS "Building ${PROJECT_NAME} with USE_CIM_VERSION=${USE_CIM_VERSION}")

if(USE_CIM_VERSION STREQUAL "CGMES_2.4.15_27JAN2020")
  set(CGMES_BUILD ON)
  set(CIM_NAME "CGMES 2_4_15 27_01_2020")
elseif(USE_CIM_VERSION STREQUAL "CGMES_2.4.15_16FEB2016")
  set(CGMES_BUILD ON)
  set(CIM_NAME "CGMES 2_4_15 16_02_2016")
elseif(USE_CIM_VERSION STREQUAL "CGMES_2.4.13_18DEC2013")
  set(CGMES_BUILD ON)
  set(CIM_NAME "CGMES 2_4_13 18_12_2013")
elseif(USE_CIM_VERSION STREQUAL "IEC61970_17v07")
  set(CIM_NAME "IEC61970 17v07")
elseif(USE_CIM_VERSION STREQUAL "IEC61970_17v23")
  set(CIM_NAME "IEC61970 17v23")
elseif(USE_CIM_VERSION STREQUAL "IEC61970_17v23_IEC61968_13v11")
  set(CIM_NAME "IEC61970 17v23 - IEC61968 13v11")
elseif(USE_CIM_VERSION STREQUAL "IEC61970_16v29a")
  set(CIM_NAME "IEC61970 16v29a")
elseif(USE_CIM_VERSION STREQUAL "IEC61970_16v29a_IEC61968_12v08")
  set(CIM_NAME "IEC61970 16v29a - IEC61968 12v08")
else()
  message(FATAL_ERROR "${USE_CIM_VERSION} is an invalid value for USE_CIM_VERSION")
endif()

# Uncomment this if you are developing on CIMgen and want to generate CIM c++
#if(CGMES_BUILD)
#  set(CGMES_OUTPUT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/${CIM_FOLDER})
#  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/CGMES_2.4.15/generate)
#endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/<src> ${XercesC_INCLUDE_DIRS})
file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE CIM_SRC ${USE_CIM_VERSION}/*.cpp)
add_library(${PROJECT_NAME} ${SRC} ${CIM_SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "cimpp${USE_CIM_VERSION}")
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${USE_CIM_VERSION}>)
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
target_link_libraries(${PROJECT_NAME} PUBLIC ${XercesC_LIBRARIES})
set_property(TARGET PROPERTY POSITION_INDEPENDENT_CODE ON)

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/static
)

file(GLOB HEADERS "src/*.h" "src/*.hpp")
install(FILES ${HEADERS}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cimpp/${USE_CIM_VERSION}
    COMPONENT devel
)

install(DIRECTORY ${USE_CIM_VERSION}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cimpp
    COMPONENT devel
    FILES_MATCHING
        PATTERN "*.h"
        PATTERN "*.hpp"
)

# Settings for packaging
include(CIMppPackaging)

if(BUILD_EXAMPLES)
  add_executable(example examples/src/main.cpp)
  target_link_libraries(example libcimpp)
  target_compile_features(example PUBLIC cxx_range_for)
endif()

# Show feature summary
include(FeatureSummary)
feature_summary(WHAT ALL VAR enabledFeaturesText)
message(STATUS "${enabledFeaturesText}")
message(STATUS "Building CIMpp with USE_CIM_VERSION=${USE_CIM_VERSION}")

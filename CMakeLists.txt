# Minimum version can be no higher than 3.5 as Ubuntu package management uses this version.
cmake_minimum_required(VERSION 3.5)

project (EX06-Partition)

set(SOURCE_PREFIX "partition")
set(EXEC_NAME "Partition")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wreturn-type -Werror")
add_executable(EX06-Partition include/algorithm.h src/main.cc)

if(EXISTS ${CMAKE_HOME_DIRECTORY}/csv15-lib/CMakeLists.txt)
    include(csv15-lib/CMakeLists.txt)
elseif(EXISTS /usr/local/csv15-lib/CMakeLists.txt)
    include(/usr/local/csv15-lib/CMakeLists.txt)
else()
    add_custom_target(add-submodules ALL git clone https://github.com/vc-csv15/csv15-lib.git ../csv15-lib)
endif()


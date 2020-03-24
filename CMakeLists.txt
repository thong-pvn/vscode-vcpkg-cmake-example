cmake_minimum_required(VERSION 3.0)

# Please set VCPKG_ROOT in .bashrc
# export VCPKG_ROOT=/home/thongpv/.vcpkg
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
  message(" [INFO] VCPKG CMAKE_TOOLCHAIN_FILE = ${CMAKE_TOOLCHAIN_FILE}")
endif()

# Please set VCPKG_DEFAULT_TRIPLET in .bashrc
# export VCPKG_DEFAULT_TRIPLET=x64-linux
if(DEFINED ENV{VCPKG_DEFAULT_TRIPLET} AND NOT DEFINED VCPKG_TARGET_TRIPLET)
  set(VCPKG_TARGET_TRIPLET "$ENV{VCPKG_DEFAULT_TRIPLET}" CACHE STRING "")
  message(" [INFO] VCPKG VCPKG_TARGET_TRIPLET = ${VCPKG_TARGET_TRIPLET}")
endif()

#======= Global Project Configuration =========#

project(test)
set(CMAKE_CXX_STANDARD 17)     

#========== Targets Configurations ============#

# CMakeLists.txt
find_package(sqlite3 CONFIG REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE sqlite3)
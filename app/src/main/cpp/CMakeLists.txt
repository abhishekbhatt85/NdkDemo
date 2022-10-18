
cmake_minimum_required(VERSION 3.22.1)
project("ndkdemo")
#set(CMAKE_CXX_STANDARD 11)

add_library( # Sets the name of the library.
        ndkdemo
        # Sets the library as a shared library.
        SHARED
        # Provides a relative path to your source file(s).
        native-lib.cpp)

find_library( # Sets the name of the path variable.
        log-lib
        log)



# Set a default build type if none was specified
# Based on: https://github.com/openchemistry/tomviz/blob/master/cmake/BuildType.cmake
set(DEFAULT_BUILD_TYPE "Release")
#if(EXISTS "${CMAKE_SOURCE_DIR}/.git")
#    set(DEFAULT_BUILD_TYPE "Debug")
#endif()
#if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
#    message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
#    set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
#    # Set the possible values of build type for cmake-gui
#    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
#endif()
#
#add_executable(finalndksample native-lib.cpp)
#
#if(WIN32) # Install dlls in the same directory as the executable on Windows
#    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
#    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
#endif()

include(FetchContent)

#set(CPR_ENABLE_SSL OFF)
#set(-DOPENSSL_ROOT_DIR=/usr/bin/openssl/ -DOPENSSL_CRYPTO_LIBRARY=/usr/bin/openssl/lib/)
#set(SYSTEM_OPENSSL ON)
#if (CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
#    execute_process(
#            COMMAND brew --prefix OpenSSL
#            RESULT_VARIABLE BREW_OPENSSL
#            OUTPUT_VARIABLE BREW_OPENSSL_PREFIX
#            OUTPUT_STRIP_TRAILING_WHITESPACE
#    )
#    if (BREW_OPENSSL EQUAL 0 AND EXISTS "${BREW_OPENSSL_PREFIX}")
#        message(STATUS "Found OpenSSL keg installed by Homebrew at ${BREW_OPENSSL_PREFIX}")
#        set(OPENSSL_ROOT_DIR "${BREW_OPENSSL_PREFIX}/")
#        set(OPENSSL_INCLUDE_DIR "${BREW_OPENSSL_PREFIX}/include")
#        set(OPENSSL_LIBRARIES "${BREW_OPENSSL_PREFIX}/lib")
#        set(OPENSSL_CRYPTO_LIBRARY "${BREW_OPENSSL_PREFIX}/lib/libcrypto.dylib")
#    endif()
#endif()
#
#find_package(OpenSSL REQUIRED)
#if (OPENSSL_FOUND)
## Add the include directories for compiling
#target_include_directories(${TARGET_SERVER} PUBLIC ${OPENSSL_INCLUDE_DIR})
## Add the static lib for linking
#target_link_libraries(${TARGET_SERVER} OpenSSL::SSL OpenSSL::Crypto finalndksample PRIVATE cpr::cpr ${log-lib} ${lib})
#message(STATUS "Found OpenSSL ${OPENSSL_VERSION}")
#else()
#message(STATUS "OpenSSL Not Found")
#endif()

set(-DOPENSSL_ROOT_DIR=/usr/bin/openssl)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG f88fd7737de3e640c61703eb57a0fa0ce00c60cd) # The commit hash for 1.9.0. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)
#add_subdirectory("../cpr/" "${CMAKE_CURRENT_BINARY_DIR}/cpr")
#include_directories(${CPR_INCLUDE_DIRS})
#find_package(OpenSSL REQUIRED)
#find_package(cpr REQUIRED)
#set(CPR_FORCE_USE_SYSTEM_CURL)

#FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/tallalnparis4ev/cpr.git GIT_TAG stable)
#set(CPR_ENABLE_SSL OFF CACHE INTERNAL "" FORCE)
#set(CPR "cpr::cpr")
#
##add_executable(finalndksample native-lib.cpp)
#
target_link_libraries(ndkdemo PRIVATE cpr::cpr ${log-lib} ${lib})






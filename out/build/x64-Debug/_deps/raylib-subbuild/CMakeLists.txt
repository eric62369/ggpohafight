# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.20.21032501-MSVC_2)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(raylib-populate NONE)



include(ExternalProject)
ExternalProject_Add(raylib-populate
                     "UPDATE_DISCONNECTED" "False" "URL" "https://github.com/raysan5/raylib/archive/master.tar.gz"
                    SOURCE_DIR          "C:/Users/Eric Yoon/Documents/Git/ggpoHaFight/out/build/x64-Debug/_deps/raylib-src"
                    BINARY_DIR          "C:/Users/Eric Yoon/Documents/Git/ggpoHaFight/out/build/x64-Debug/_deps/raylib-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)



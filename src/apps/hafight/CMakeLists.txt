include(CMakeSources.cmake)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(example)

# Set this to the minimal version you want to support
find_package(raylib 3.0 QUIET) # Let CMake search for a raylib-config.cmake

# You could change the QUIET above to REQUIRED and remove this if() clause
# This part downloads raylib and builds it if it's not installed on your system
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)

  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/master.tar.gz
  )

  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)

    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples

    # build raylib
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})

  endif()

endif()

add_executable(HAFight WIN32 
	${GGPO_EXAMPLES_HAFIGHT_SRC}
)

if(WIN32 AND BUILD_SHARED_LIBS)
	add_definitions(-DGGPO_SHARED_LIB)
endif()

add_common_flags(HAFight)
# Change the character set to unicode.
add_definitions(-D_UNICODE -DUNICODE)

# Link against GGPO, winmm (Windows Multimedia API), and ws2_32 (Winsock). Added raylib
target_link_libraries(HAFight LINK_PUBLIC GGPO winmm.lib ws2_32.lib opengl32.lib gdi32.lib raylib)
target_compile_options(HAFight PRIVATE "/W4" "/WX")
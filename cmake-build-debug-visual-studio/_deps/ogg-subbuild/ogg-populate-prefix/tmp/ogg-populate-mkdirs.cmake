# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/C/ball_simulation/cmake-build-debug-visual-studio/_deps/ogg-src"
  "C:/C/ball_simulation/cmake-build-debug-visual-studio/_deps/ogg-build"
  "C:/C/ball_simulation/cmake-build-debug-visual-studio/_deps/ogg-subbuild/ogg-populate-prefix"
  "C:/C/ball_simulation/cmake-build-debug-visual-studio/_deps/ogg-subbuild/ogg-populate-prefix/tmp"
  "C:/C/ball_simulation/cmake-build-debug-visual-studio/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp"
  "C:/C/ball_simulation/cmake-build-debug-visual-studio/_deps/ogg-subbuild/ogg-populate-prefix/src"
  "C:/C/ball_simulation/cmake-build-debug-visual-studio/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/C/ball_simulation/cmake-build-debug-visual-studio/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/C/ball_simulation/cmake-build-debug-visual-studio/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

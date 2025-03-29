# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug-coverage/_deps/ogg-src")
  file(MAKE_DIRECTORY "D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug-coverage/_deps/ogg-src")
endif()
file(MAKE_DIRECTORY
  "D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug-coverage/_deps/ogg-build"
  "D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug-coverage/_deps/ogg-subbuild/ogg-populate-prefix"
  "D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug-coverage/_deps/ogg-subbuild/ogg-populate-prefix/tmp"
  "D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug-coverage/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp"
  "D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug-coverage/_deps/ogg-subbuild/ogg-populate-prefix/src"
  "D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug-coverage/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug-coverage/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/GitHub_Repos/pwr_AiZO_project1/cmake-build-debug-coverage/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/benchmark-build/third_party/googletest/src"
  "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/benchmark-build/third_party/googletest/build"
  "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/benchmark-build/third_party/googletest"
  "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/benchmark-build/third_party/googletest/tmp"
  "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/benchmark-build/third_party/googletest/stamp"
  "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/benchmark-build/third_party/googletest/download"
  "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/benchmark-build/third_party/googletest/stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/benchmark-build/third_party/googletest/stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/benchmark-build/third_party/googletest/stamp${cfgdir}") # cfgdir has leading slash
endif()

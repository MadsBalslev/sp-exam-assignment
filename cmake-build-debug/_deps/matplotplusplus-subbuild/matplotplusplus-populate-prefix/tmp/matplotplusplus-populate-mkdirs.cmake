# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Patrick/Documents/GitHub/Sp-Exam-Try-2/cmake-build-debug/_deps/matplotplusplus-src"
  "C:/Users/Patrick/Documents/GitHub/Sp-Exam-Try-2/cmake-build-debug/_deps/matplotplusplus-build"
  "C:/Users/Patrick/Documents/GitHub/Sp-Exam-Try-2/cmake-build-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix"
  "C:/Users/Patrick/Documents/GitHub/Sp-Exam-Try-2/cmake-build-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/tmp"
  "C:/Users/Patrick/Documents/GitHub/Sp-Exam-Try-2/cmake-build-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp"
  "C:/Users/Patrick/Documents/GitHub/Sp-Exam-Try-2/cmake-build-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src"
  "C:/Users/Patrick/Documents/GitHub/Sp-Exam-Try-2/cmake-build-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Patrick/Documents/GitHub/Sp-Exam-Try-2/cmake-build-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Patrick/Documents/GitHub/Sp-Exam-Try-2/cmake-build-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
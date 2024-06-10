# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-src"
  "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-build"
  "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-subbuild/sciplot_content-populate-prefix"
  "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-subbuild/sciplot_content-populate-prefix/tmp"
  "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-subbuild/sciplot_content-populate-prefix/src/sciplot_content-populate-stamp"
  "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-subbuild/sciplot_content-populate-prefix/src"
  "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-subbuild/sciplot_content-populate-prefix/src/sciplot_content-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-subbuild/sciplot_content-populate-prefix/src/sciplot_content-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-subbuild/sciplot_content-populate-prefix/src/sciplot_content-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

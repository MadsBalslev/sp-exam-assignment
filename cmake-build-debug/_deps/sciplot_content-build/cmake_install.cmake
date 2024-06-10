# Install script for directory: /Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-src/sciplot")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/SpStochLib/sciplotTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/SpStochLib/sciplotTargets.cmake"
         "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-build/CMakeFiles/Export/9bb465ea8e95b1c4e9f6f1c5a596b618/sciplotTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/SpStochLib/sciplotTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/SpStochLib/sciplotTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/SpStochLib" TYPE FILE FILES "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-build/CMakeFiles/Export/9bb465ea8e95b1c4e9f6f1c5a596b618/sciplotTargets.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/SpStochLib" TYPE FILE FILES
    "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-build/sciplotConfig.cmake"
    "/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-build/sciplotConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-build/examples/cmake_install.cmake")
  include("/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-build/tests/cmake_install.cmake")
  include("/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-build/docs/cmake_install.cmake")
  include("/Users/mads/dev/aau/Sp/Sp-Exam-Try-2/cmake-build-debug/_deps/sciplot_content-build/scripts/cmake_install.cmake")

endif()


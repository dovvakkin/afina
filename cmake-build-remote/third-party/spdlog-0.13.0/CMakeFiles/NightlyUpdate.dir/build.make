# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.YIDWVUSsKZ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.YIDWVUSsKZ/cmake-build-remote

# Utility rule file for NightlyUpdate.

# Include the progress variables for this target.
include third-party/spdlog-0.13.0/CMakeFiles/NightlyUpdate.dir/progress.make

third-party/spdlog-0.13.0/CMakeFiles/NightlyUpdate:
	cd /tmp/tmp.YIDWVUSsKZ/cmake-build-remote/third-party/spdlog-0.13.0 && /usr/bin/ctest -D NightlyUpdate

NightlyUpdate: third-party/spdlog-0.13.0/CMakeFiles/NightlyUpdate
NightlyUpdate: third-party/spdlog-0.13.0/CMakeFiles/NightlyUpdate.dir/build.make

.PHONY : NightlyUpdate

# Rule to build all files generated by this target.
third-party/spdlog-0.13.0/CMakeFiles/NightlyUpdate.dir/build: NightlyUpdate

.PHONY : third-party/spdlog-0.13.0/CMakeFiles/NightlyUpdate.dir/build

third-party/spdlog-0.13.0/CMakeFiles/NightlyUpdate.dir/clean:
	cd /tmp/tmp.YIDWVUSsKZ/cmake-build-remote/third-party/spdlog-0.13.0 && $(CMAKE_COMMAND) -P CMakeFiles/NightlyUpdate.dir/cmake_clean.cmake
.PHONY : third-party/spdlog-0.13.0/CMakeFiles/NightlyUpdate.dir/clean

third-party/spdlog-0.13.0/CMakeFiles/NightlyUpdate.dir/depend:
	cd /tmp/tmp.YIDWVUSsKZ/cmake-build-remote && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.YIDWVUSsKZ /tmp/tmp.YIDWVUSsKZ/third-party/spdlog-0.13.0 /tmp/tmp.YIDWVUSsKZ/cmake-build-remote /tmp/tmp.YIDWVUSsKZ/cmake-build-remote/third-party/spdlog-0.13.0 /tmp/tmp.YIDWVUSsKZ/cmake-build-remote/third-party/spdlog-0.13.0/CMakeFiles/NightlyUpdate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third-party/spdlog-0.13.0/CMakeFiles/NightlyUpdate.dir/depend


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
CMAKE_COMMAND = "/Users/dovvakkin/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.4284.156/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/dovvakkin/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.4284.156/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dovvakkin/ssh/afina

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dovvakkin/ssh/afina/cmake-build-system

# Utility rule file for ContinuousCoverage.

# Include the progress variables for this target.
include third-party/spdlog-0.13.0/CMakeFiles/ContinuousCoverage.dir/progress.make

third-party/spdlog-0.13.0/CMakeFiles/ContinuousCoverage:
	cd /Users/dovvakkin/ssh/afina/cmake-build-system/third-party/spdlog-0.13.0 && "/Users/dovvakkin/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.4284.156/CLion.app/Contents/bin/cmake/mac/bin/ctest" -D ContinuousCoverage

ContinuousCoverage: third-party/spdlog-0.13.0/CMakeFiles/ContinuousCoverage
ContinuousCoverage: third-party/spdlog-0.13.0/CMakeFiles/ContinuousCoverage.dir/build.make

.PHONY : ContinuousCoverage

# Rule to build all files generated by this target.
third-party/spdlog-0.13.0/CMakeFiles/ContinuousCoverage.dir/build: ContinuousCoverage

.PHONY : third-party/spdlog-0.13.0/CMakeFiles/ContinuousCoverage.dir/build

third-party/spdlog-0.13.0/CMakeFiles/ContinuousCoverage.dir/clean:
	cd /Users/dovvakkin/ssh/afina/cmake-build-system/third-party/spdlog-0.13.0 && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousCoverage.dir/cmake_clean.cmake
.PHONY : third-party/spdlog-0.13.0/CMakeFiles/ContinuousCoverage.dir/clean

third-party/spdlog-0.13.0/CMakeFiles/ContinuousCoverage.dir/depend:
	cd /Users/dovvakkin/ssh/afina/cmake-build-system && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dovvakkin/ssh/afina /Users/dovvakkin/ssh/afina/third-party/spdlog-0.13.0 /Users/dovvakkin/ssh/afina/cmake-build-system /Users/dovvakkin/ssh/afina/cmake-build-system/third-party/spdlog-0.13.0 /Users/dovvakkin/ssh/afina/cmake-build-system/third-party/spdlog-0.13.0/CMakeFiles/ContinuousCoverage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third-party/spdlog-0.13.0/CMakeFiles/ContinuousCoverage.dir/depend


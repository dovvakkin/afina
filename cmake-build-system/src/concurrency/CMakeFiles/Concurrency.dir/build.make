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

# Include any dependencies generated for this target.
include src/concurrency/CMakeFiles/Concurrency.dir/depend.make

# Include the progress variables for this target.
include src/concurrency/CMakeFiles/Concurrency.dir/progress.make

# Include the compile flags for this target's objects.
include src/concurrency/CMakeFiles/Concurrency.dir/flags.make

src/concurrency/CMakeFiles/Concurrency.dir/Executor.cpp.o: src/concurrency/CMakeFiles/Concurrency.dir/flags.make
src/concurrency/CMakeFiles/Concurrency.dir/Executor.cpp.o: ../src/concurrency/Executor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dovvakkin/ssh/afina/cmake-build-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/concurrency/CMakeFiles/Concurrency.dir/Executor.cpp.o"
	cd /Users/dovvakkin/ssh/afina/cmake-build-system/src/concurrency && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Concurrency.dir/Executor.cpp.o -c /Users/dovvakkin/ssh/afina/src/concurrency/Executor.cpp

src/concurrency/CMakeFiles/Concurrency.dir/Executor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Concurrency.dir/Executor.cpp.i"
	cd /Users/dovvakkin/ssh/afina/cmake-build-system/src/concurrency && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dovvakkin/ssh/afina/src/concurrency/Executor.cpp > CMakeFiles/Concurrency.dir/Executor.cpp.i

src/concurrency/CMakeFiles/Concurrency.dir/Executor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Concurrency.dir/Executor.cpp.s"
	cd /Users/dovvakkin/ssh/afina/cmake-build-system/src/concurrency && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dovvakkin/ssh/afina/src/concurrency/Executor.cpp -o CMakeFiles/Concurrency.dir/Executor.cpp.s

# Object files for target Concurrency
Concurrency_OBJECTS = \
"CMakeFiles/Concurrency.dir/Executor.cpp.o"

# External object files for target Concurrency
Concurrency_EXTERNAL_OBJECTS =

src/concurrency/libConcurrency.a: src/concurrency/CMakeFiles/Concurrency.dir/Executor.cpp.o
src/concurrency/libConcurrency.a: src/concurrency/CMakeFiles/Concurrency.dir/build.make
src/concurrency/libConcurrency.a: src/concurrency/CMakeFiles/Concurrency.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dovvakkin/ssh/afina/cmake-build-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libConcurrency.a"
	cd /Users/dovvakkin/ssh/afina/cmake-build-system/src/concurrency && $(CMAKE_COMMAND) -P CMakeFiles/Concurrency.dir/cmake_clean_target.cmake
	cd /Users/dovvakkin/ssh/afina/cmake-build-system/src/concurrency && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Concurrency.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/concurrency/CMakeFiles/Concurrency.dir/build: src/concurrency/libConcurrency.a

.PHONY : src/concurrency/CMakeFiles/Concurrency.dir/build

src/concurrency/CMakeFiles/Concurrency.dir/clean:
	cd /Users/dovvakkin/ssh/afina/cmake-build-system/src/concurrency && $(CMAKE_COMMAND) -P CMakeFiles/Concurrency.dir/cmake_clean.cmake
.PHONY : src/concurrency/CMakeFiles/Concurrency.dir/clean

src/concurrency/CMakeFiles/Concurrency.dir/depend:
	cd /Users/dovvakkin/ssh/afina/cmake-build-system && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dovvakkin/ssh/afina /Users/dovvakkin/ssh/afina/src/concurrency /Users/dovvakkin/ssh/afina/cmake-build-system /Users/dovvakkin/ssh/afina/cmake-build-system/src/concurrency /Users/dovvakkin/ssh/afina/cmake-build-system/src/concurrency/CMakeFiles/Concurrency.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/concurrency/CMakeFiles/Concurrency.dir/depend


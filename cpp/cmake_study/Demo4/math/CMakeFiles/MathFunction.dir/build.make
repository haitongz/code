# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.1

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.1.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.1.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/haitongz/Code/cpp/cmake_study/Demo3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/haitongz/Code/cpp/cmake_study/Demo3

# Include any dependencies generated for this target.
include math/CMakeFiles/MathFunction.dir/depend.make

# Include the progress variables for this target.
include math/CMakeFiles/MathFunction.dir/progress.make

# Include the compile flags for this target's objects.
include math/CMakeFiles/MathFunction.dir/flags.make

math/CMakeFiles/MathFunction.dir/MathFunction.cc.o: math/CMakeFiles/MathFunction.dir/flags.make
math/CMakeFiles/MathFunction.dir/MathFunction.cc.o: math/MathFunction.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/haitongz/Code/cpp/cmake_study/Demo3/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object math/CMakeFiles/MathFunction.dir/MathFunction.cc.o"
	cd /Users/haitongz/Code/cpp/cmake_study/Demo3/math && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MathFunction.dir/MathFunction.cc.o -c /Users/haitongz/Code/cpp/cmake_study/Demo3/math/MathFunction.cc

math/CMakeFiles/MathFunction.dir/MathFunction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MathFunction.dir/MathFunction.cc.i"
	cd /Users/haitongz/Code/cpp/cmake_study/Demo3/math && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/haitongz/Code/cpp/cmake_study/Demo3/math/MathFunction.cc > CMakeFiles/MathFunction.dir/MathFunction.cc.i

math/CMakeFiles/MathFunction.dir/MathFunction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MathFunction.dir/MathFunction.cc.s"
	cd /Users/haitongz/Code/cpp/cmake_study/Demo3/math && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/haitongz/Code/cpp/cmake_study/Demo3/math/MathFunction.cc -o CMakeFiles/MathFunction.dir/MathFunction.cc.s

math/CMakeFiles/MathFunction.dir/MathFunction.cc.o.requires:
.PHONY : math/CMakeFiles/MathFunction.dir/MathFunction.cc.o.requires

math/CMakeFiles/MathFunction.dir/MathFunction.cc.o.provides: math/CMakeFiles/MathFunction.dir/MathFunction.cc.o.requires
	$(MAKE) -f math/CMakeFiles/MathFunction.dir/build.make math/CMakeFiles/MathFunction.dir/MathFunction.cc.o.provides.build
.PHONY : math/CMakeFiles/MathFunction.dir/MathFunction.cc.o.provides

math/CMakeFiles/MathFunction.dir/MathFunction.cc.o.provides.build: math/CMakeFiles/MathFunction.dir/MathFunction.cc.o

# Object files for target MathFunction
MathFunction_OBJECTS = \
"CMakeFiles/MathFunction.dir/MathFunction.cc.o"

# External object files for target MathFunction
MathFunction_EXTERNAL_OBJECTS =

math/libMathFunction.a: math/CMakeFiles/MathFunction.dir/MathFunction.cc.o
math/libMathFunction.a: math/CMakeFiles/MathFunction.dir/build.make
math/libMathFunction.a: math/CMakeFiles/MathFunction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libMathFunction.a"
	cd /Users/haitongz/Code/cpp/cmake_study/Demo3/math && $(CMAKE_COMMAND) -P CMakeFiles/MathFunction.dir/cmake_clean_target.cmake
	cd /Users/haitongz/Code/cpp/cmake_study/Demo3/math && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MathFunction.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
math/CMakeFiles/MathFunction.dir/build: math/libMathFunction.a
.PHONY : math/CMakeFiles/MathFunction.dir/build

math/CMakeFiles/MathFunction.dir/requires: math/CMakeFiles/MathFunction.dir/MathFunction.cc.o.requires
.PHONY : math/CMakeFiles/MathFunction.dir/requires

math/CMakeFiles/MathFunction.dir/clean:
	cd /Users/haitongz/Code/cpp/cmake_study/Demo3/math && $(CMAKE_COMMAND) -P CMakeFiles/MathFunction.dir/cmake_clean.cmake
.PHONY : math/CMakeFiles/MathFunction.dir/clean

math/CMakeFiles/MathFunction.dir/depend:
	cd /Users/haitongz/Code/cpp/cmake_study/Demo3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/haitongz/Code/cpp/cmake_study/Demo3 /Users/haitongz/Code/cpp/cmake_study/Demo3/math /Users/haitongz/Code/cpp/cmake_study/Demo3 /Users/haitongz/Code/cpp/cmake_study/Demo3/math /Users/haitongz/Code/cpp/cmake_study/Demo3/math/CMakeFiles/MathFunction.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : math/CMakeFiles/MathFunction.dir/depend


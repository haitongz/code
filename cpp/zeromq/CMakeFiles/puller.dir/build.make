# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.1

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /Users/haitongz/Code/cpp/zeromq

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/haitongz/Code/cpp/zeromq

# Include any dependencies generated for this target.
include CMakeFiles/puller.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/puller.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/puller.dir/flags.make

CMakeFiles/puller.dir/puller.cpp.o: CMakeFiles/puller.dir/flags.make
CMakeFiles/puller.dir/puller.cpp.o: puller.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/haitongz/Code/cpp/zeromq/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/puller.dir/puller.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/puller.dir/puller.cpp.o -c /Users/haitongz/Code/cpp/zeromq/puller.cpp

CMakeFiles/puller.dir/puller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/puller.dir/puller.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/haitongz/Code/cpp/zeromq/puller.cpp > CMakeFiles/puller.dir/puller.cpp.i

CMakeFiles/puller.dir/puller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/puller.dir/puller.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/haitongz/Code/cpp/zeromq/puller.cpp -o CMakeFiles/puller.dir/puller.cpp.s

CMakeFiles/puller.dir/puller.cpp.o.requires:
.PHONY : CMakeFiles/puller.dir/puller.cpp.o.requires

CMakeFiles/puller.dir/puller.cpp.o.provides: CMakeFiles/puller.dir/puller.cpp.o.requires
	$(MAKE) -f CMakeFiles/puller.dir/build.make CMakeFiles/puller.dir/puller.cpp.o.provides.build
.PHONY : CMakeFiles/puller.dir/puller.cpp.o.provides

CMakeFiles/puller.dir/puller.cpp.o.provides.build: CMakeFiles/puller.dir/puller.cpp.o

# Object files for target puller
puller_OBJECTS = \
"CMakeFiles/puller.dir/puller.cpp.o"

# External object files for target puller
puller_EXTERNAL_OBJECTS =

puller: CMakeFiles/puller.dir/puller.cpp.o
puller: CMakeFiles/puller.dir/build.make
puller: CMakeFiles/puller.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable puller"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/puller.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/puller.dir/build: puller
.PHONY : CMakeFiles/puller.dir/build

CMakeFiles/puller.dir/requires: CMakeFiles/puller.dir/puller.cpp.o.requires
.PHONY : CMakeFiles/puller.dir/requires

CMakeFiles/puller.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/puller.dir/cmake_clean.cmake
.PHONY : CMakeFiles/puller.dir/clean

CMakeFiles/puller.dir/depend:
	cd /Users/haitongz/Code/cpp/zeromq && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/haitongz/Code/cpp/zeromq /Users/haitongz/Code/cpp/zeromq /Users/haitongz/Code/cpp/zeromq /Users/haitongz/Code/cpp/zeromq /Users/haitongz/Code/cpp/zeromq/CMakeFiles/puller.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/puller.dir/depend


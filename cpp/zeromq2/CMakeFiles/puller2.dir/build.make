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
CMAKE_SOURCE_DIR = /Users/haitongz/Code/cpp/zeromq2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/haitongz/Code/cpp/zeromq2

# Include any dependencies generated for this target.
include CMakeFiles/puller2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/puller2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/puller2.dir/flags.make

CMakeFiles/puller2.dir/puller2.cpp.o: CMakeFiles/puller2.dir/flags.make
CMakeFiles/puller2.dir/puller2.cpp.o: puller2.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/haitongz/Code/cpp/zeromq2/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/puller2.dir/puller2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/puller2.dir/puller2.cpp.o -c /Users/haitongz/Code/cpp/zeromq2/puller2.cpp

CMakeFiles/puller2.dir/puller2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/puller2.dir/puller2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/haitongz/Code/cpp/zeromq2/puller2.cpp > CMakeFiles/puller2.dir/puller2.cpp.i

CMakeFiles/puller2.dir/puller2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/puller2.dir/puller2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/haitongz/Code/cpp/zeromq2/puller2.cpp -o CMakeFiles/puller2.dir/puller2.cpp.s

CMakeFiles/puller2.dir/puller2.cpp.o.requires:
.PHONY : CMakeFiles/puller2.dir/puller2.cpp.o.requires

CMakeFiles/puller2.dir/puller2.cpp.o.provides: CMakeFiles/puller2.dir/puller2.cpp.o.requires
	$(MAKE) -f CMakeFiles/puller2.dir/build.make CMakeFiles/puller2.dir/puller2.cpp.o.provides.build
.PHONY : CMakeFiles/puller2.dir/puller2.cpp.o.provides

CMakeFiles/puller2.dir/puller2.cpp.o.provides.build: CMakeFiles/puller2.dir/puller2.cpp.o

# Object files for target puller2
puller2_OBJECTS = \
"CMakeFiles/puller2.dir/puller2.cpp.o"

# External object files for target puller2
puller2_EXTERNAL_OBJECTS =

puller2: CMakeFiles/puller2.dir/puller2.cpp.o
puller2: CMakeFiles/puller2.dir/build.make
puller2: CMakeFiles/puller2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable puller2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/puller2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/puller2.dir/build: puller2
.PHONY : CMakeFiles/puller2.dir/build

CMakeFiles/puller2.dir/requires: CMakeFiles/puller2.dir/puller2.cpp.o.requires
.PHONY : CMakeFiles/puller2.dir/requires

CMakeFiles/puller2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/puller2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/puller2.dir/clean

CMakeFiles/puller2.dir/depend:
	cd /Users/haitongz/Code/cpp/zeromq2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/haitongz/Code/cpp/zeromq2 /Users/haitongz/Code/cpp/zeromq2 /Users/haitongz/Code/cpp/zeromq2 /Users/haitongz/Code/cpp/zeromq2 /Users/haitongz/Code/cpp/zeromq2/CMakeFiles/puller2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/puller2.dir/depend


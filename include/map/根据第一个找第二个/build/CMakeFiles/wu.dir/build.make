# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wu/桌面/cmake_muban

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wu/桌面/cmake_muban/build

# Include any dependencies generated for this target.
include CMakeFiles/wu.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wu.dir/flags.make

CMakeFiles/wu.dir/input.cc.o: CMakeFiles/wu.dir/flags.make
CMakeFiles/wu.dir/input.cc.o: ../input.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/wu/桌面/cmake_muban/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/wu.dir/input.cc.o"
	/usr/local/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/wu.dir/input.cc.o -c /home/wu/桌面/cmake_muban/input.cc

CMakeFiles/wu.dir/input.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wu.dir/input.cc.i"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/wu/桌面/cmake_muban/input.cc > CMakeFiles/wu.dir/input.cc.i

CMakeFiles/wu.dir/input.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wu.dir/input.cc.s"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/wu/桌面/cmake_muban/input.cc -o CMakeFiles/wu.dir/input.cc.s

CMakeFiles/wu.dir/input.cc.o.requires:
.PHONY : CMakeFiles/wu.dir/input.cc.o.requires

CMakeFiles/wu.dir/input.cc.o.provides: CMakeFiles/wu.dir/input.cc.o.requires
	$(MAKE) -f CMakeFiles/wu.dir/build.make CMakeFiles/wu.dir/input.cc.o.provides.build
.PHONY : CMakeFiles/wu.dir/input.cc.o.provides

CMakeFiles/wu.dir/input.cc.o.provides.build: CMakeFiles/wu.dir/input.cc.o

CMakeFiles/wu.dir/src/wuhongyi.cc.o: CMakeFiles/wu.dir/flags.make
CMakeFiles/wu.dir/src/wuhongyi.cc.o: ../src/wuhongyi.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/wu/桌面/cmake_muban/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/wu.dir/src/wuhongyi.cc.o"
	/usr/local/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/wu.dir/src/wuhongyi.cc.o -c /home/wu/桌面/cmake_muban/src/wuhongyi.cc

CMakeFiles/wu.dir/src/wuhongyi.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wu.dir/src/wuhongyi.cc.i"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/wu/桌面/cmake_muban/src/wuhongyi.cc > CMakeFiles/wu.dir/src/wuhongyi.cc.i

CMakeFiles/wu.dir/src/wuhongyi.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wu.dir/src/wuhongyi.cc.s"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/wu/桌面/cmake_muban/src/wuhongyi.cc -o CMakeFiles/wu.dir/src/wuhongyi.cc.s

CMakeFiles/wu.dir/src/wuhongyi.cc.o.requires:
.PHONY : CMakeFiles/wu.dir/src/wuhongyi.cc.o.requires

CMakeFiles/wu.dir/src/wuhongyi.cc.o.provides: CMakeFiles/wu.dir/src/wuhongyi.cc.o.requires
	$(MAKE) -f CMakeFiles/wu.dir/build.make CMakeFiles/wu.dir/src/wuhongyi.cc.o.provides.build
.PHONY : CMakeFiles/wu.dir/src/wuhongyi.cc.o.provides

CMakeFiles/wu.dir/src/wuhongyi.cc.o.provides.build: CMakeFiles/wu.dir/src/wuhongyi.cc.o

# Object files for target wu
wu_OBJECTS = \
"CMakeFiles/wu.dir/input.cc.o" \
"CMakeFiles/wu.dir/src/wuhongyi.cc.o"

# External object files for target wu
wu_EXTERNAL_OBJECTS =

../bin/wu: CMakeFiles/wu.dir/input.cc.o
../bin/wu: CMakeFiles/wu.dir/src/wuhongyi.cc.o
../bin/wu: CMakeFiles/wu.dir/build.make
../bin/wu: CMakeFiles/wu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/wu"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wu.dir/build: ../bin/wu
.PHONY : CMakeFiles/wu.dir/build

CMakeFiles/wu.dir/requires: CMakeFiles/wu.dir/input.cc.o.requires
CMakeFiles/wu.dir/requires: CMakeFiles/wu.dir/src/wuhongyi.cc.o.requires
.PHONY : CMakeFiles/wu.dir/requires

CMakeFiles/wu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wu.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wu.dir/clean

CMakeFiles/wu.dir/depend:
	cd /home/wu/桌面/cmake_muban/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wu/桌面/cmake_muban /home/wu/桌面/cmake_muban /home/wu/桌面/cmake_muban/build /home/wu/桌面/cmake_muban/build /home/wu/桌面/cmake_muban/build/CMakeFiles/wu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wu.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /usr/local/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dushan/Workspace/C++/C-Competitive-Problems/leet-spiral-matrix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dushan/Workspace/C++/C-Competitive-Problems/leet-spiral-matrix/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/leet_spiral_matrix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/leet_spiral_matrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/leet_spiral_matrix.dir/flags.make

CMakeFiles/leet_spiral_matrix.dir/main.cpp.o: CMakeFiles/leet_spiral_matrix.dir/flags.make
CMakeFiles/leet_spiral_matrix.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dushan/Workspace/C++/C-Competitive-Problems/leet-spiral-matrix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/leet_spiral_matrix.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/leet_spiral_matrix.dir/main.cpp.o -c /home/dushan/Workspace/C++/C-Competitive-Problems/leet-spiral-matrix/main.cpp

CMakeFiles/leet_spiral_matrix.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/leet_spiral_matrix.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dushan/Workspace/C++/C-Competitive-Problems/leet-spiral-matrix/main.cpp > CMakeFiles/leet_spiral_matrix.dir/main.cpp.i

CMakeFiles/leet_spiral_matrix.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/leet_spiral_matrix.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dushan/Workspace/C++/C-Competitive-Problems/leet-spiral-matrix/main.cpp -o CMakeFiles/leet_spiral_matrix.dir/main.cpp.s

CMakeFiles/leet_spiral_matrix.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/leet_spiral_matrix.dir/main.cpp.o.requires

CMakeFiles/leet_spiral_matrix.dir/main.cpp.o.provides: CMakeFiles/leet_spiral_matrix.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/leet_spiral_matrix.dir/build.make CMakeFiles/leet_spiral_matrix.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/leet_spiral_matrix.dir/main.cpp.o.provides

CMakeFiles/leet_spiral_matrix.dir/main.cpp.o.provides.build: CMakeFiles/leet_spiral_matrix.dir/main.cpp.o


# Object files for target leet_spiral_matrix
leet_spiral_matrix_OBJECTS = \
"CMakeFiles/leet_spiral_matrix.dir/main.cpp.o"

# External object files for target leet_spiral_matrix
leet_spiral_matrix_EXTERNAL_OBJECTS =

leet_spiral_matrix: CMakeFiles/leet_spiral_matrix.dir/main.cpp.o
leet_spiral_matrix: CMakeFiles/leet_spiral_matrix.dir/build.make
leet_spiral_matrix: CMakeFiles/leet_spiral_matrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dushan/Workspace/C++/C-Competitive-Problems/leet-spiral-matrix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable leet_spiral_matrix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/leet_spiral_matrix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/leet_spiral_matrix.dir/build: leet_spiral_matrix

.PHONY : CMakeFiles/leet_spiral_matrix.dir/build

CMakeFiles/leet_spiral_matrix.dir/requires: CMakeFiles/leet_spiral_matrix.dir/main.cpp.o.requires

.PHONY : CMakeFiles/leet_spiral_matrix.dir/requires

CMakeFiles/leet_spiral_matrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/leet_spiral_matrix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/leet_spiral_matrix.dir/clean

CMakeFiles/leet_spiral_matrix.dir/depend:
	cd /home/dushan/Workspace/C++/C-Competitive-Problems/leet-spiral-matrix/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dushan/Workspace/C++/C-Competitive-Problems/leet-spiral-matrix /home/dushan/Workspace/C++/C-Competitive-Problems/leet-spiral-matrix /home/dushan/Workspace/C++/C-Competitive-Problems/leet-spiral-matrix/cmake-build-debug /home/dushan/Workspace/C++/C-Competitive-Problems/leet-spiral-matrix/cmake-build-debug /home/dushan/Workspace/C++/C-Competitive-Problems/leet-spiral-matrix/cmake-build-debug/CMakeFiles/leet_spiral_matrix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/leet_spiral_matrix.dir/depend


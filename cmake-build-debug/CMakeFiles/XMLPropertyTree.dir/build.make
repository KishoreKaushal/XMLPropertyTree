# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /home/kaushal/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.8194.17/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kaushal/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.8194.17/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kaushal/CLionProjects/XMLPropertyTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kaushal/CLionProjects/XMLPropertyTree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/XMLPropertyTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/XMLPropertyTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/XMLPropertyTree.dir/flags.make

CMakeFiles/XMLPropertyTree.dir/main.cpp.o: CMakeFiles/XMLPropertyTree.dir/flags.make
CMakeFiles/XMLPropertyTree.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kaushal/CLionProjects/XMLPropertyTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/XMLPropertyTree.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XMLPropertyTree.dir/main.cpp.o -c /home/kaushal/CLionProjects/XMLPropertyTree/main.cpp

CMakeFiles/XMLPropertyTree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XMLPropertyTree.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kaushal/CLionProjects/XMLPropertyTree/main.cpp > CMakeFiles/XMLPropertyTree.dir/main.cpp.i

CMakeFiles/XMLPropertyTree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XMLPropertyTree.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kaushal/CLionProjects/XMLPropertyTree/main.cpp -o CMakeFiles/XMLPropertyTree.dir/main.cpp.s

CMakeFiles/XMLPropertyTree.dir/XMLPropertyTree.cpp.o: CMakeFiles/XMLPropertyTree.dir/flags.make
CMakeFiles/XMLPropertyTree.dir/XMLPropertyTree.cpp.o: ../XMLPropertyTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kaushal/CLionProjects/XMLPropertyTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/XMLPropertyTree.dir/XMLPropertyTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XMLPropertyTree.dir/XMLPropertyTree.cpp.o -c /home/kaushal/CLionProjects/XMLPropertyTree/XMLPropertyTree.cpp

CMakeFiles/XMLPropertyTree.dir/XMLPropertyTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XMLPropertyTree.dir/XMLPropertyTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kaushal/CLionProjects/XMLPropertyTree/XMLPropertyTree.cpp > CMakeFiles/XMLPropertyTree.dir/XMLPropertyTree.cpp.i

CMakeFiles/XMLPropertyTree.dir/XMLPropertyTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XMLPropertyTree.dir/XMLPropertyTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kaushal/CLionProjects/XMLPropertyTree/XMLPropertyTree.cpp -o CMakeFiles/XMLPropertyTree.dir/XMLPropertyTree.cpp.s

# Object files for target XMLPropertyTree
XMLPropertyTree_OBJECTS = \
"CMakeFiles/XMLPropertyTree.dir/main.cpp.o" \
"CMakeFiles/XMLPropertyTree.dir/XMLPropertyTree.cpp.o"

# External object files for target XMLPropertyTree
XMLPropertyTree_EXTERNAL_OBJECTS =

XMLPropertyTree: CMakeFiles/XMLPropertyTree.dir/main.cpp.o
XMLPropertyTree: CMakeFiles/XMLPropertyTree.dir/XMLPropertyTree.cpp.o
XMLPropertyTree: CMakeFiles/XMLPropertyTree.dir/build.make
XMLPropertyTree: CMakeFiles/XMLPropertyTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kaushal/CLionProjects/XMLPropertyTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable XMLPropertyTree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/XMLPropertyTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/XMLPropertyTree.dir/build: XMLPropertyTree

.PHONY : CMakeFiles/XMLPropertyTree.dir/build

CMakeFiles/XMLPropertyTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/XMLPropertyTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/XMLPropertyTree.dir/clean

CMakeFiles/XMLPropertyTree.dir/depend:
	cd /home/kaushal/CLionProjects/XMLPropertyTree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kaushal/CLionProjects/XMLPropertyTree /home/kaushal/CLionProjects/XMLPropertyTree /home/kaushal/CLionProjects/XMLPropertyTree/cmake-build-debug /home/kaushal/CLionProjects/XMLPropertyTree/cmake-build-debug /home/kaushal/CLionProjects/XMLPropertyTree/cmake-build-debug/CMakeFiles/XMLPropertyTree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/XMLPropertyTree.dir/depend


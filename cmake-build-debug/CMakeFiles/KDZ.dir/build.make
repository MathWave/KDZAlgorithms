# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/egormatveev/CLionProjects/KDZ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/egormatveev/CLionProjects/KDZ/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/KDZ.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/KDZ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KDZ.dir/flags.make

CMakeFiles/KDZ.dir/main.cpp.o: CMakeFiles/KDZ.dir/flags.make
CMakeFiles/KDZ.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/egormatveev/CLionProjects/KDZ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/KDZ.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/KDZ.dir/main.cpp.o -c /Users/egormatveev/CLionProjects/KDZ/main.cpp

CMakeFiles/KDZ.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KDZ.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/egormatveev/CLionProjects/KDZ/main.cpp > CMakeFiles/KDZ.dir/main.cpp.i

CMakeFiles/KDZ.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KDZ.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/egormatveev/CLionProjects/KDZ/main.cpp -o CMakeFiles/KDZ.dir/main.cpp.s

# Object files for target KDZ
KDZ_OBJECTS = \
"CMakeFiles/KDZ.dir/main.cpp.o"

# External object files for target KDZ
KDZ_EXTERNAL_OBJECTS =

KDZ: CMakeFiles/KDZ.dir/main.cpp.o
KDZ: CMakeFiles/KDZ.dir/build.make
KDZ: CMakeFiles/KDZ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/egormatveev/CLionProjects/KDZ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable KDZ"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/KDZ.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KDZ.dir/build: KDZ

.PHONY : CMakeFiles/KDZ.dir/build

CMakeFiles/KDZ.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/KDZ.dir/cmake_clean.cmake
.PHONY : CMakeFiles/KDZ.dir/clean

CMakeFiles/KDZ.dir/depend:
	cd /Users/egormatveev/CLionProjects/KDZ/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/egormatveev/CLionProjects/KDZ /Users/egormatveev/CLionProjects/KDZ /Users/egormatveev/CLionProjects/KDZ/cmake-build-debug /Users/egormatveev/CLionProjects/KDZ/cmake-build-debug /Users/egormatveev/CLionProjects/KDZ/cmake-build-debug/CMakeFiles/KDZ.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KDZ.dir/depend


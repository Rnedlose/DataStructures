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
CMAKE_COMMAND = /opt/clion-2019.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rod/Documents/myprojects/DataStructures/InfixPrefixPostfix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rod/Documents/myprojects/DataStructures/InfixPrefixPostfix/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/InfixPrefixPostfix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/InfixPrefixPostfix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/InfixPrefixPostfix.dir/flags.make

CMakeFiles/InfixPrefixPostfix.dir/InfixPrefixPostfix.cpp.o: CMakeFiles/InfixPrefixPostfix.dir/flags.make
CMakeFiles/InfixPrefixPostfix.dir/InfixPrefixPostfix.cpp.o: ../InfixPrefixPostfix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rod/Documents/myprojects/DataStructures/InfixPrefixPostfix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/InfixPrefixPostfix.dir/InfixPrefixPostfix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/InfixPrefixPostfix.dir/InfixPrefixPostfix.cpp.o -c /home/rod/Documents/myprojects/DataStructures/InfixPrefixPostfix/InfixPrefixPostfix.cpp

CMakeFiles/InfixPrefixPostfix.dir/InfixPrefixPostfix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/InfixPrefixPostfix.dir/InfixPrefixPostfix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rod/Documents/myprojects/DataStructures/InfixPrefixPostfix/InfixPrefixPostfix.cpp > CMakeFiles/InfixPrefixPostfix.dir/InfixPrefixPostfix.cpp.i

CMakeFiles/InfixPrefixPostfix.dir/InfixPrefixPostfix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/InfixPrefixPostfix.dir/InfixPrefixPostfix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rod/Documents/myprojects/DataStructures/InfixPrefixPostfix/InfixPrefixPostfix.cpp -o CMakeFiles/InfixPrefixPostfix.dir/InfixPrefixPostfix.cpp.s

# Object files for target InfixPrefixPostfix
InfixPrefixPostfix_OBJECTS = \
"CMakeFiles/InfixPrefixPostfix.dir/InfixPrefixPostfix.cpp.o"

# External object files for target InfixPrefixPostfix
InfixPrefixPostfix_EXTERNAL_OBJECTS =

InfixPrefixPostfix: CMakeFiles/InfixPrefixPostfix.dir/InfixPrefixPostfix.cpp.o
InfixPrefixPostfix: CMakeFiles/InfixPrefixPostfix.dir/build.make
InfixPrefixPostfix: CMakeFiles/InfixPrefixPostfix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rod/Documents/myprojects/DataStructures/InfixPrefixPostfix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable InfixPrefixPostfix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/InfixPrefixPostfix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/InfixPrefixPostfix.dir/build: InfixPrefixPostfix

.PHONY : CMakeFiles/InfixPrefixPostfix.dir/build

CMakeFiles/InfixPrefixPostfix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/InfixPrefixPostfix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/InfixPrefixPostfix.dir/clean

CMakeFiles/InfixPrefixPostfix.dir/depend:
	cd /home/rod/Documents/myprojects/DataStructures/InfixPrefixPostfix/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rod/Documents/myprojects/DataStructures/InfixPrefixPostfix /home/rod/Documents/myprojects/DataStructures/InfixPrefixPostfix /home/rod/Documents/myprojects/DataStructures/InfixPrefixPostfix/cmake-build-debug /home/rod/Documents/myprojects/DataStructures/InfixPrefixPostfix/cmake-build-debug /home/rod/Documents/myprojects/DataStructures/InfixPrefixPostfix/cmake-build-debug/CMakeFiles/InfixPrefixPostfix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/InfixPrefixPostfix.dir/depend


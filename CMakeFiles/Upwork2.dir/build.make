# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pantelisg/Documents/railbrosTicketSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pantelisg/Documents/railbrosTicketSystem

# Include any dependencies generated for this target.
include CMakeFiles/Upwork2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Upwork2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Upwork2.dir/flags.make

CMakeFiles/Upwork2.dir/Upwork2.cpp.o: CMakeFiles/Upwork2.dir/flags.make
CMakeFiles/Upwork2.dir/Upwork2.cpp.o: Upwork2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pantelisg/Documents/railbrosTicketSystem/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Upwork2.dir/Upwork2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Upwork2.dir/Upwork2.cpp.o -c /home/pantelisg/Documents/railbrosTicketSystem/Upwork2.cpp

CMakeFiles/Upwork2.dir/Upwork2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Upwork2.dir/Upwork2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pantelisg/Documents/railbrosTicketSystem/Upwork2.cpp > CMakeFiles/Upwork2.dir/Upwork2.cpp.i

CMakeFiles/Upwork2.dir/Upwork2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Upwork2.dir/Upwork2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pantelisg/Documents/railbrosTicketSystem/Upwork2.cpp -o CMakeFiles/Upwork2.dir/Upwork2.cpp.s

# Object files for target Upwork2
Upwork2_OBJECTS = \
"CMakeFiles/Upwork2.dir/Upwork2.cpp.o"

# External object files for target Upwork2
Upwork2_EXTERNAL_OBJECTS =

Upwork2: CMakeFiles/Upwork2.dir/Upwork2.cpp.o
Upwork2: CMakeFiles/Upwork2.dir/build.make
Upwork2: CMakeFiles/Upwork2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pantelisg/Documents/railbrosTicketSystem/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Upwork2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Upwork2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Upwork2.dir/build: Upwork2

.PHONY : CMakeFiles/Upwork2.dir/build

CMakeFiles/Upwork2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Upwork2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Upwork2.dir/clean

CMakeFiles/Upwork2.dir/depend:
	cd /home/pantelisg/Documents/railbrosTicketSystem && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pantelisg/Documents/railbrosTicketSystem /home/pantelisg/Documents/railbrosTicketSystem /home/pantelisg/Documents/railbrosTicketSystem /home/pantelisg/Documents/railbrosTicketSystem /home/pantelisg/Documents/railbrosTicketSystem/CMakeFiles/Upwork2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Upwork2.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Ccode\Clion\xdoj_303

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Ccode\Clion\xdoj_303\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/xdoj_303.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/xdoj_303.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xdoj_303.dir/flags.make

CMakeFiles/xdoj_303.dir/main.cpp.obj: CMakeFiles/xdoj_303.dir/flags.make
CMakeFiles/xdoj_303.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Ccode\Clion\xdoj_303\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/xdoj_303.dir/main.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\xdoj_303.dir\main.cpp.obj -c D:\Ccode\Clion\xdoj_303\main.cpp

CMakeFiles/xdoj_303.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xdoj_303.dir/main.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Ccode\Clion\xdoj_303\main.cpp > CMakeFiles\xdoj_303.dir\main.cpp.i

CMakeFiles/xdoj_303.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xdoj_303.dir/main.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Ccode\Clion\xdoj_303\main.cpp -o CMakeFiles\xdoj_303.dir\main.cpp.s

# Object files for target xdoj_303
xdoj_303_OBJECTS = \
"CMakeFiles/xdoj_303.dir/main.cpp.obj"

# External object files for target xdoj_303
xdoj_303_EXTERNAL_OBJECTS =

xdoj_303.exe: CMakeFiles/xdoj_303.dir/main.cpp.obj
xdoj_303.exe: CMakeFiles/xdoj_303.dir/build.make
xdoj_303.exe: CMakeFiles/xdoj_303.dir/linklibs.rsp
xdoj_303.exe: CMakeFiles/xdoj_303.dir/objects1.rsp
xdoj_303.exe: CMakeFiles/xdoj_303.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Ccode\Clion\xdoj_303\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable xdoj_303.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\xdoj_303.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xdoj_303.dir/build: xdoj_303.exe

.PHONY : CMakeFiles/xdoj_303.dir/build

CMakeFiles/xdoj_303.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\xdoj_303.dir\cmake_clean.cmake
.PHONY : CMakeFiles/xdoj_303.dir/clean

CMakeFiles/xdoj_303.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Ccode\Clion\xdoj_303 D:\Ccode\Clion\xdoj_303 D:\Ccode\Clion\xdoj_303\cmake-build-debug D:\Ccode\Clion\xdoj_303\cmake-build-debug D:\Ccode\Clion\xdoj_303\cmake-build-debug\CMakeFiles\xdoj_303.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xdoj_303.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\ADT_TEST\BinTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ADT_TEST\BinTree\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BinTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BinTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BinTree.dir/flags.make

CMakeFiles/BinTree.dir/main.c.obj: CMakeFiles/BinTree.dir/flags.make
CMakeFiles/BinTree.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ADT_TEST\BinTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BinTree.dir/main.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\BinTree.dir\main.c.obj   -c D:\ADT_TEST\BinTree\main.c

CMakeFiles/BinTree.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BinTree.dir/main.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\ADT_TEST\BinTree\main.c > CMakeFiles\BinTree.dir\main.c.i

CMakeFiles/BinTree.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BinTree.dir/main.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\ADT_TEST\BinTree\main.c -o CMakeFiles\BinTree.dir\main.c.s

CMakeFiles/BinTree.dir/bintree.c.obj: CMakeFiles/BinTree.dir/flags.make
CMakeFiles/BinTree.dir/bintree.c.obj: ../bintree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ADT_TEST\BinTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/BinTree.dir/bintree.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\BinTree.dir\bintree.c.obj   -c D:\ADT_TEST\BinTree\bintree.c

CMakeFiles/BinTree.dir/bintree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BinTree.dir/bintree.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\ADT_TEST\BinTree\bintree.c > CMakeFiles\BinTree.dir\bintree.c.i

CMakeFiles/BinTree.dir/bintree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BinTree.dir/bintree.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\ADT_TEST\BinTree\bintree.c -o CMakeFiles\BinTree.dir\bintree.c.s

CMakeFiles/BinTree.dir/binstack.c.obj: CMakeFiles/BinTree.dir/flags.make
CMakeFiles/BinTree.dir/binstack.c.obj: ../binstack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ADT_TEST\BinTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/BinTree.dir/binstack.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\BinTree.dir\binstack.c.obj   -c D:\ADT_TEST\BinTree\binstack.c

CMakeFiles/BinTree.dir/binstack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BinTree.dir/binstack.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\ADT_TEST\BinTree\binstack.c > CMakeFiles\BinTree.dir\binstack.c.i

CMakeFiles/BinTree.dir/binstack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BinTree.dir/binstack.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\ADT_TEST\BinTree\binstack.c -o CMakeFiles\BinTree.dir\binstack.c.s

# Object files for target BinTree
BinTree_OBJECTS = \
"CMakeFiles/BinTree.dir/main.c.obj" \
"CMakeFiles/BinTree.dir/bintree.c.obj" \
"CMakeFiles/BinTree.dir/binstack.c.obj"

# External object files for target BinTree
BinTree_EXTERNAL_OBJECTS =

BinTree.exe: CMakeFiles/BinTree.dir/main.c.obj
BinTree.exe: CMakeFiles/BinTree.dir/bintree.c.obj
BinTree.exe: CMakeFiles/BinTree.dir/binstack.c.obj
BinTree.exe: CMakeFiles/BinTree.dir/build.make
BinTree.exe: CMakeFiles/BinTree.dir/linklibs.rsp
BinTree.exe: CMakeFiles/BinTree.dir/objects1.rsp
BinTree.exe: CMakeFiles/BinTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ADT_TEST\BinTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable BinTree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BinTree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BinTree.dir/build: BinTree.exe

.PHONY : CMakeFiles/BinTree.dir/build

CMakeFiles/BinTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BinTree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BinTree.dir/clean

CMakeFiles/BinTree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ADT_TEST\BinTree D:\ADT_TEST\BinTree D:\ADT_TEST\BinTree\cmake-build-debug D:\ADT_TEST\BinTree\cmake-build-debug D:\ADT_TEST\BinTree\cmake-build-debug\CMakeFiles\BinTree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BinTree.dir/depend


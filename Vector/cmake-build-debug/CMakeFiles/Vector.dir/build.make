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
CMAKE_SOURCE_DIR = D:\ADT_TEST\Vector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ADT_TEST\Vector\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Vector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Vector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Vector.dir/flags.make

CMakeFiles/Vector.dir/main.c.obj: CMakeFiles/Vector.dir/flags.make
CMakeFiles/Vector.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ADT_TEST\Vector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Vector.dir/main.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Vector.dir\main.c.obj   -c D:\ADT_TEST\Vector\main.c

CMakeFiles/Vector.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Vector.dir/main.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\ADT_TEST\Vector\main.c > CMakeFiles\Vector.dir\main.c.i

CMakeFiles/Vector.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Vector.dir/main.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\ADT_TEST\Vector\main.c -o CMakeFiles\Vector.dir\main.c.s

CMakeFiles/Vector.dir/vector.c.obj: CMakeFiles/Vector.dir/flags.make
CMakeFiles/Vector.dir/vector.c.obj: ../vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ADT_TEST\Vector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Vector.dir/vector.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Vector.dir\vector.c.obj   -c D:\ADT_TEST\Vector\vector.c

CMakeFiles/Vector.dir/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Vector.dir/vector.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\ADT_TEST\Vector\vector.c > CMakeFiles\Vector.dir\vector.c.i

CMakeFiles/Vector.dir/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Vector.dir/vector.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\ADT_TEST\Vector\vector.c -o CMakeFiles\Vector.dir\vector.c.s

CMakeFiles/Vector.dir/SearchAlgo.c.obj: CMakeFiles/Vector.dir/flags.make
CMakeFiles/Vector.dir/SearchAlgo.c.obj: ../SearchAlgo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ADT_TEST\Vector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Vector.dir/SearchAlgo.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Vector.dir\SearchAlgo.c.obj   -c D:\ADT_TEST\Vector\SearchAlgo.c

CMakeFiles/Vector.dir/SearchAlgo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Vector.dir/SearchAlgo.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\ADT_TEST\Vector\SearchAlgo.c > CMakeFiles\Vector.dir\SearchAlgo.c.i

CMakeFiles/Vector.dir/SearchAlgo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Vector.dir/SearchAlgo.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\ADT_TEST\Vector\SearchAlgo.c -o CMakeFiles\Vector.dir\SearchAlgo.c.s

CMakeFiles/Vector.dir/sort.c.obj: CMakeFiles/Vector.dir/flags.make
CMakeFiles/Vector.dir/sort.c.obj: ../sort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ADT_TEST\Vector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Vector.dir/sort.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Vector.dir\sort.c.obj   -c D:\ADT_TEST\Vector\sort.c

CMakeFiles/Vector.dir/sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Vector.dir/sort.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\ADT_TEST\Vector\sort.c > CMakeFiles\Vector.dir\sort.c.i

CMakeFiles/Vector.dir/sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Vector.dir/sort.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\ADT_TEST\Vector\sort.c -o CMakeFiles\Vector.dir\sort.c.s

# Object files for target Vector
Vector_OBJECTS = \
"CMakeFiles/Vector.dir/main.c.obj" \
"CMakeFiles/Vector.dir/vector.c.obj" \
"CMakeFiles/Vector.dir/SearchAlgo.c.obj" \
"CMakeFiles/Vector.dir/sort.c.obj"

# External object files for target Vector
Vector_EXTERNAL_OBJECTS =

Vector.exe: CMakeFiles/Vector.dir/main.c.obj
Vector.exe: CMakeFiles/Vector.dir/vector.c.obj
Vector.exe: CMakeFiles/Vector.dir/SearchAlgo.c.obj
Vector.exe: CMakeFiles/Vector.dir/sort.c.obj
Vector.exe: CMakeFiles/Vector.dir/build.make
Vector.exe: CMakeFiles/Vector.dir/linklibs.rsp
Vector.exe: CMakeFiles/Vector.dir/objects1.rsp
Vector.exe: CMakeFiles/Vector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ADT_TEST\Vector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Vector.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Vector.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Vector.dir/build: Vector.exe

.PHONY : CMakeFiles/Vector.dir/build

CMakeFiles/Vector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Vector.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Vector.dir/clean

CMakeFiles/Vector.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ADT_TEST\Vector D:\ADT_TEST\Vector D:\ADT_TEST\Vector\cmake-build-debug D:\ADT_TEST\Vector\cmake-build-debug D:\ADT_TEST\Vector\cmake-build-debug\CMakeFiles\Vector.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Vector.dir/depend

# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\maria\Desktop\Taller\Algoritmos II\L02-definicion_clases"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\maria\Desktop\Taller\Algoritmos II\L02-definicion_clases\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ej7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ej7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej7.dir/flags.make

CMakeFiles/ej7.dir/tests/test_recordatorios.cpp.obj: CMakeFiles/ej7.dir/flags.make
CMakeFiles/ej7.dir/tests/test_recordatorios.cpp.obj: ../tests/test_recordatorios.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\maria\Desktop\Taller\Algoritmos II\L02-definicion_clases\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej7.dir/tests/test_recordatorios.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ej7.dir\tests\test_recordatorios.cpp.obj -c "C:\Users\maria\Desktop\Taller\Algoritmos II\L02-definicion_clases\tests\test_recordatorios.cpp"

CMakeFiles/ej7.dir/tests/test_recordatorios.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej7.dir/tests/test_recordatorios.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\maria\Desktop\Taller\Algoritmos II\L02-definicion_clases\tests\test_recordatorios.cpp" > CMakeFiles\ej7.dir\tests\test_recordatorios.cpp.i

CMakeFiles/ej7.dir/tests/test_recordatorios.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej7.dir/tests/test_recordatorios.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\maria\Desktop\Taller\Algoritmos II\L02-definicion_clases\tests\test_recordatorios.cpp" -o CMakeFiles\ej7.dir\tests\test_recordatorios.cpp.s

# Object files for target ej7
ej7_OBJECTS = \
"CMakeFiles/ej7.dir/tests/test_recordatorios.cpp.obj"

# External object files for target ej7
ej7_EXTERNAL_OBJECTS =

ej7.exe: CMakeFiles/ej7.dir/tests/test_recordatorios.cpp.obj
ej7.exe: CMakeFiles/ej7.dir/build.make
ej7.exe: libgtest.a
ej7.exe: libgtest_main.a
ej7.exe: CMakeFiles/ej7.dir/linklibs.rsp
ej7.exe: CMakeFiles/ej7.dir/objects1.rsp
ej7.exe: CMakeFiles/ej7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\maria\Desktop\Taller\Algoritmos II\L02-definicion_clases\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ej7.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ej7.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej7.dir/build: ej7.exe

.PHONY : CMakeFiles/ej7.dir/build

CMakeFiles/ej7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ej7.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ej7.dir/clean

CMakeFiles/ej7.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\maria\Desktop\Taller\Algoritmos II\L02-definicion_clases" "C:\Users\maria\Desktop\Taller\Algoritmos II\L02-definicion_clases" "C:\Users\maria\Desktop\Taller\Algoritmos II\L02-definicion_clases\cmake-build-debug" "C:\Users\maria\Desktop\Taller\Algoritmos II\L02-definicion_clases\cmake-build-debug" "C:\Users\maria\Desktop\Taller\Algoritmos II\L02-definicion_clases\cmake-build-debug\CMakeFiles\ej7.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ej7.dir/depend


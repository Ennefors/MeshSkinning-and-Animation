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
CMAKE_COMMAND = /home/bill/Desktop/clion-2017.2.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/bill/Desktop/clion-2017.2.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bill/wilenn-5/S0008E/Labb1/lab-env-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug

# Include any dependencies generated for this target.
include exts/CMakeFiles/imgui.dir/depend.make

# Include the progress variables for this target.
include exts/CMakeFiles/imgui.dir/progress.make

# Include the compile flags for this target's objects.
include exts/CMakeFiles/imgui.dir/flags.make

exts/CMakeFiles/imgui.dir/imgui/imgui.cpp.o: exts/CMakeFiles/imgui.dir/flags.make
exts/CMakeFiles/imgui.dir/imgui/imgui.cpp.o: ../exts/imgui/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object exts/CMakeFiles/imgui.dir/imgui/imgui.cpp.o"
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/imgui/imgui.cpp.o -c /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/exts/imgui/imgui.cpp

exts/CMakeFiles/imgui.dir/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/imgui/imgui.cpp.i"
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/exts/imgui/imgui.cpp > CMakeFiles/imgui.dir/imgui/imgui.cpp.i

exts/CMakeFiles/imgui.dir/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/imgui/imgui.cpp.s"
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/exts/imgui/imgui.cpp -o CMakeFiles/imgui.dir/imgui/imgui.cpp.s

exts/CMakeFiles/imgui.dir/imgui/imgui.cpp.o.requires:

.PHONY : exts/CMakeFiles/imgui.dir/imgui/imgui.cpp.o.requires

exts/CMakeFiles/imgui.dir/imgui/imgui.cpp.o.provides: exts/CMakeFiles/imgui.dir/imgui/imgui.cpp.o.requires
	$(MAKE) -f exts/CMakeFiles/imgui.dir/build.make exts/CMakeFiles/imgui.dir/imgui/imgui.cpp.o.provides.build
.PHONY : exts/CMakeFiles/imgui.dir/imgui/imgui.cpp.o.provides

exts/CMakeFiles/imgui.dir/imgui/imgui.cpp.o.provides.build: exts/CMakeFiles/imgui.dir/imgui/imgui.cpp.o


exts/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o: exts/CMakeFiles/imgui.dir/flags.make
exts/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o: ../exts/imgui/imgui_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object exts/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o"
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o -c /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/exts/imgui/imgui_demo.cpp

exts/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.i"
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/exts/imgui/imgui_demo.cpp > CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.i

exts/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.s"
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/exts/imgui/imgui_demo.cpp -o CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.s

exts/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o.requires:

.PHONY : exts/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o.requires

exts/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o.provides: exts/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o.requires
	$(MAKE) -f exts/CMakeFiles/imgui.dir/build.make exts/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o.provides.build
.PHONY : exts/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o.provides

exts/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o.provides.build: exts/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o


exts/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o: exts/CMakeFiles/imgui.dir/flags.make
exts/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o: ../exts/imgui/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object exts/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o"
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o -c /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/exts/imgui/imgui_draw.cpp

exts/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.i"
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/exts/imgui/imgui_draw.cpp > CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.i

exts/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.s"
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/exts/imgui/imgui_draw.cpp -o CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.s

exts/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o.requires:

.PHONY : exts/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o.requires

exts/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o.provides: exts/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o.requires
	$(MAKE) -f exts/CMakeFiles/imgui.dir/build.make exts/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o.provides.build
.PHONY : exts/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o.provides

exts/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o.provides.build: exts/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o


exts/CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.o: exts/CMakeFiles/imgui.dir/flags.make
exts/CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.o: ../exts/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object exts/CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.o"
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.o -c /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/exts/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp

exts/CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.i"
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/exts/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp > CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.i

exts/CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.s"
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/exts/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp -o CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.s

exts/CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.o.requires:

.PHONY : exts/CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.o.requires

exts/CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.o.provides: exts/CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.o.requires
	$(MAKE) -f exts/CMakeFiles/imgui.dir/build.make exts/CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.o.provides.build
.PHONY : exts/CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.o.provides

exts/CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.o.provides.build: exts/CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.o


# Object files for target imgui
imgui_OBJECTS = \
"CMakeFiles/imgui.dir/imgui/imgui.cpp.o" \
"CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o" \
"CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o" \
"CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.o"

# External object files for target imgui
imgui_EXTERNAL_OBJECTS =

exts/libimgui.a: exts/CMakeFiles/imgui.dir/imgui/imgui.cpp.o
exts/libimgui.a: exts/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o
exts/libimgui.a: exts/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o
exts/libimgui.a: exts/CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.o
exts/libimgui.a: exts/CMakeFiles/imgui.dir/build.make
exts/libimgui.a: exts/CMakeFiles/imgui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libimgui.a"
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts && $(CMAKE_COMMAND) -P CMakeFiles/imgui.dir/cmake_clean_target.cmake
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imgui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
exts/CMakeFiles/imgui.dir/build: exts/libimgui.a

.PHONY : exts/CMakeFiles/imgui.dir/build

exts/CMakeFiles/imgui.dir/requires: exts/CMakeFiles/imgui.dir/imgui/imgui.cpp.o.requires
exts/CMakeFiles/imgui.dir/requires: exts/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o.requires
exts/CMakeFiles/imgui.dir/requires: exts/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o.requires
exts/CMakeFiles/imgui.dir/requires: exts/CMakeFiles/imgui.dir/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp.o.requires

.PHONY : exts/CMakeFiles/imgui.dir/requires

exts/CMakeFiles/imgui.dir/clean:
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts && $(CMAKE_COMMAND) -P CMakeFiles/imgui.dir/cmake_clean.cmake
.PHONY : exts/CMakeFiles/imgui.dir/clean

exts/CMakeFiles/imgui.dir/depend:
	cd /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bill/wilenn-5/S0008E/Labb1/lab-env-master /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/exts /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts /home/bill/wilenn-5/S0008E/Labb1/lab-env-master/cmake-build-debug/exts/CMakeFiles/imgui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : exts/CMakeFiles/imgui.dir/depend


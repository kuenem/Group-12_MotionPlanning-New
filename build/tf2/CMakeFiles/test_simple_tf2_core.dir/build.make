# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/UMRobotics/new_ws/src/geometry2/tf2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/UMRobotics/new_ws/build/tf2

# Include any dependencies generated for this target.
include CMakeFiles/test_simple_tf2_core.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_simple_tf2_core.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_simple_tf2_core.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_simple_tf2_core.dir/flags.make

CMakeFiles/test_simple_tf2_core.dir/test/simple_tf2_core.cpp.o: CMakeFiles/test_simple_tf2_core.dir/flags.make
CMakeFiles/test_simple_tf2_core.dir/test/simple_tf2_core.cpp.o: /home/UMRobotics/new_ws/src/geometry2/tf2/test/simple_tf2_core.cpp
CMakeFiles/test_simple_tf2_core.dir/test/simple_tf2_core.cpp.o: CMakeFiles/test_simple_tf2_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/UMRobotics/new_ws/build/tf2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_simple_tf2_core.dir/test/simple_tf2_core.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_simple_tf2_core.dir/test/simple_tf2_core.cpp.o -MF CMakeFiles/test_simple_tf2_core.dir/test/simple_tf2_core.cpp.o.d -o CMakeFiles/test_simple_tf2_core.dir/test/simple_tf2_core.cpp.o -c /home/UMRobotics/new_ws/src/geometry2/tf2/test/simple_tf2_core.cpp

CMakeFiles/test_simple_tf2_core.dir/test/simple_tf2_core.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_simple_tf2_core.dir/test/simple_tf2_core.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/UMRobotics/new_ws/src/geometry2/tf2/test/simple_tf2_core.cpp > CMakeFiles/test_simple_tf2_core.dir/test/simple_tf2_core.cpp.i

CMakeFiles/test_simple_tf2_core.dir/test/simple_tf2_core.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_simple_tf2_core.dir/test/simple_tf2_core.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/UMRobotics/new_ws/src/geometry2/tf2/test/simple_tf2_core.cpp -o CMakeFiles/test_simple_tf2_core.dir/test/simple_tf2_core.cpp.s

# Object files for target test_simple_tf2_core
test_simple_tf2_core_OBJECTS = \
"CMakeFiles/test_simple_tf2_core.dir/test/simple_tf2_core.cpp.o"

# External object files for target test_simple_tf2_core
test_simple_tf2_core_EXTERNAL_OBJECTS =

test_simple_tf2_core: CMakeFiles/test_simple_tf2_core.dir/test/simple_tf2_core.cpp.o
test_simple_tf2_core: CMakeFiles/test_simple_tf2_core.dir/build.make
test_simple_tf2_core: gtest/libgtest_main.a
test_simple_tf2_core: gtest/libgtest.a
test_simple_tf2_core: libtf2.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libgeometry_msgs__rosidl_typesupport_fastrtps_c.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libgeometry_msgs__rosidl_typesupport_introspection_c.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libgeometry_msgs__rosidl_typesupport_fastrtps_cpp.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libgeometry_msgs__rosidl_typesupport_introspection_cpp.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libgeometry_msgs__rosidl_typesupport_cpp.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libgeometry_msgs__rosidl_generator_py.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libgeometry_msgs__rosidl_typesupport_c.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libgeometry_msgs__rosidl_generator_c.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libstd_msgs__rosidl_typesupport_fastrtps_c.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libstd_msgs__rosidl_typesupport_introspection_c.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libstd_msgs__rosidl_typesupport_fastrtps_cpp.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libstd_msgs__rosidl_typesupport_introspection_cpp.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libstd_msgs__rosidl_typesupport_cpp.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_c.so
test_simple_tf2_core: /opt/ros/jazzy/lib/librosidl_typesupport_fastrtps_c.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_c.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_cpp.so
test_simple_tf2_core: /opt/ros/jazzy/lib/librosidl_typesupport_fastrtps_cpp.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libfastcdr.so.2.2.5
test_simple_tf2_core: /opt/ros/jazzy/lib/librmw.so
test_simple_tf2_core: /opt/ros/jazzy/lib/librosidl_dynamic_typesupport.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_cpp.so
test_simple_tf2_core: /opt/ros/jazzy/lib/librosidl_typesupport_introspection_cpp.so
test_simple_tf2_core: /opt/ros/jazzy/lib/librosidl_typesupport_introspection_c.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_typesupport_cpp.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_generator_py.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libstd_msgs__rosidl_typesupport_c.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_typesupport_c.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libstd_msgs__rosidl_generator_c.so
test_simple_tf2_core: /opt/ros/jazzy/lib/libbuiltin_interfaces__rosidl_generator_c.so
test_simple_tf2_core: /opt/ros/jazzy/lib/librosidl_runtime_c.so
test_simple_tf2_core: /opt/ros/jazzy/lib/librcutils.so
test_simple_tf2_core: CMakeFiles/test_simple_tf2_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/UMRobotics/new_ws/build/tf2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_simple_tf2_core"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_simple_tf2_core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_simple_tf2_core.dir/build: test_simple_tf2_core
.PHONY : CMakeFiles/test_simple_tf2_core.dir/build

CMakeFiles/test_simple_tf2_core.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_simple_tf2_core.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_simple_tf2_core.dir/clean

CMakeFiles/test_simple_tf2_core.dir/depend:
	cd /home/UMRobotics/new_ws/build/tf2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/UMRobotics/new_ws/src/geometry2/tf2 /home/UMRobotics/new_ws/src/geometry2/tf2 /home/UMRobotics/new_ws/build/tf2 /home/UMRobotics/new_ws/build/tf2 /home/UMRobotics/new_ws/build/tf2/CMakeFiles/test_simple_tf2_core.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test_simple_tf2_core.dir/depend


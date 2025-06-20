#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "moveit_servo::moveit_servo_lib_cpp" for configuration "Release"
set_property(TARGET moveit_servo::moveit_servo_lib_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(moveit_servo::moveit_servo_lib_cpp PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmoveit_servo_lib_cpp.so.2.12.3"
  IMPORTED_SONAME_RELEASE "libmoveit_servo_lib_cpp.so.2.12.3"
  )

list(APPEND _cmake_import_check_targets moveit_servo::moveit_servo_lib_cpp )
list(APPEND _cmake_import_check_files_for_moveit_servo::moveit_servo_lib_cpp "${_IMPORT_PREFIX}/lib/libmoveit_servo_lib_cpp.so.2.12.3" )

# Import target "moveit_servo::moveit_servo_lib_ros" for configuration "Release"
set_property(TARGET moveit_servo::moveit_servo_lib_ros APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(moveit_servo::moveit_servo_lib_ros PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmoveit_servo_lib_ros.so.2.12.3"
  IMPORTED_SONAME_RELEASE "libmoveit_servo_lib_ros.so.2.12.3"
  )

list(APPEND _cmake_import_check_targets moveit_servo::moveit_servo_lib_ros )
list(APPEND _cmake_import_check_files_for_moveit_servo::moveit_servo_lib_ros "${_IMPORT_PREFIX}/lib/libmoveit_servo_lib_ros.so.2.12.3" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

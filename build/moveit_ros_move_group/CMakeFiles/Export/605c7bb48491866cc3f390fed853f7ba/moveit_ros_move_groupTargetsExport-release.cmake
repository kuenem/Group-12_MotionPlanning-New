#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "moveit_ros_move_group::moveit_move_group_capabilities_base" for configuration "Release"
set_property(TARGET moveit_ros_move_group::moveit_move_group_capabilities_base APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(moveit_ros_move_group::moveit_move_group_capabilities_base PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmoveit_move_group_capabilities_base.so.2.12.3"
  IMPORTED_SONAME_RELEASE "libmoveit_move_group_capabilities_base.so.2.12.3"
  )

list(APPEND _cmake_import_check_targets moveit_ros_move_group::moveit_move_group_capabilities_base )
list(APPEND _cmake_import_check_files_for_moveit_ros_move_group::moveit_move_group_capabilities_base "${_IMPORT_PREFIX}/lib/libmoveit_move_group_capabilities_base.so.2.12.3" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

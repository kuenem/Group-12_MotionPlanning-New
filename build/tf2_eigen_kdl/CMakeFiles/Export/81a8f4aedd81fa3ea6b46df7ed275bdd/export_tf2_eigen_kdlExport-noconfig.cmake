#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tf2_eigen_kdl::tf2_eigen_kdl" for configuration ""
set_property(TARGET tf2_eigen_kdl::tf2_eigen_kdl APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(tf2_eigen_kdl::tf2_eigen_kdl PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libtf2_eigen_kdl.so"
  IMPORTED_SONAME_NOCONFIG "libtf2_eigen_kdl.so"
  )

list(APPEND _cmake_import_check_targets tf2_eigen_kdl::tf2_eigen_kdl )
list(APPEND _cmake_import_check_files_for_tf2_eigen_kdl::tf2_eigen_kdl "${_IMPORT_PREFIX}/lib/libtf2_eigen_kdl.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

# generated from catkin/cmake/template/pkgConfig.cmake.in

# append elements to a list and remove existing duplicates from the list
# copied from catkin/cmake/list_append_deduplicate.cmake to keep pkgConfig
# self contained
macro(_list_append_deduplicate listname)
  if(NOT "${ARGN}" STREQUAL "")
    if(${listname})
      list(REMOVE_ITEM ${listname} ${ARGN})
    endif()
    list(APPEND ${listname} ${ARGN})
  endif()
endmacro()

# append elements to a list if they are not already in the list
# copied from catkin/cmake/list_append_unique.cmake to keep pkgConfig
# self contained
macro(_list_append_unique listname)
  foreach(_item ${ARGN})
    list(FIND ${listname} ${_item} _index)
    if(_index EQUAL -1)
      list(APPEND ${listname} ${_item})
    endif()
  endforeach()
endmacro()

# pack a list of libraries with optional build configuration keywords
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_pack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  set(_argn ${ARGN})
  list(LENGTH _argn _count)
  set(_index 0)
  while(${_index} LESS ${_count})
    list(GET _argn ${_index} lib)
    if("${lib}" MATCHES "^(debug|optimized|general)$")
      math(EXPR _index "${_index} + 1")
      if(${_index} EQUAL ${_count})
        message(FATAL_ERROR "_pack_libraries_with_build_configuration() the list of libraries '${ARGN}' ends with '${lib}' which is a build configuration keyword and must be followed by a library")
      endif()
      list(GET _argn ${_index} library)
      list(APPEND ${VAR} "${lib}${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}${library}")
    else()
      list(APPEND ${VAR} "${lib}")
    endif()
    math(EXPR _index "${_index} + 1")
  endwhile()
endmacro()

# unpack a list of libraries with optional build configuration keyword prefixes
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_unpack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  foreach(lib ${ARGN})
    string(REGEX REPLACE "^(debug|optimized|general)${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}(.+)$" "\\1;\\2" lib "${lib}")
    list(APPEND ${VAR} "${lib}")
  endforeach()
endmacro()


if(handsfree_2dnav_CONFIG_INCLUDED)
  return()
endif()
set(handsfree_2dnav_CONFIG_INCLUDED TRUE)

# set variables for source/devel/install prefixes
if("TRUE" STREQUAL "TRUE")
  set(handsfree_2dnav_SOURCE_PREFIX /home/cyb7369299/My_Workspace/xyi_ws/src/handsfree_2dnav)
  set(handsfree_2dnav_DEVEL_PREFIX /home/cyb7369299/My_Workspace/xyi_ws/devel)
  set(handsfree_2dnav_INSTALL_PREFIX "")
  set(handsfree_2dnav_PREFIX ${handsfree_2dnav_DEVEL_PREFIX})
else()
  set(handsfree_2dnav_SOURCE_PREFIX "")
  set(handsfree_2dnav_DEVEL_PREFIX "")
  set(handsfree_2dnav_INSTALL_PREFIX /home/cyb7369299/My_Workspace/xyi_ws/install)
  set(handsfree_2dnav_PREFIX ${handsfree_2dnav_INSTALL_PREFIX})
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "WARNING: package 'handsfree_2dnav' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  message("${_msg}")
endif()

# flag project as catkin-based to distinguish if a find_package()-ed project is a catkin project
set(handsfree_2dnav_FOUND_CATKIN_PROJECT TRUE)

if(NOT " " STREQUAL " ")
  set(handsfree_2dnav_INCLUDE_DIRS "")
  set(_include_dirs "")
  foreach(idir ${_include_dirs})
    if(IS_ABSOLUTE ${idir} AND IS_DIRECTORY ${idir})
      set(include ${idir})
    elseif("${idir} " STREQUAL "include ")
      get_filename_component(include "${handsfree_2dnav_DIR}/../../../include" ABSOLUTE)
      if(NOT IS_DIRECTORY ${include})
        message(FATAL_ERROR "Project 'handsfree_2dnav' specifies '${idir}' as an include dir, which is not found.  It does not exist in '${include}'.  Ask the maintainer 'luke_liao <luke_liao@126.com>' to fix it.")
      endif()
    else()
      message(FATAL_ERROR "Project 'handsfree_2dnav' specifies '${idir}' as an include dir, which is not found.  It does neither exist as an absolute directory nor in '/home/cyb7369299/My_Workspace/xyi_ws/src/handsfree_2dnav/${idir}'.  Ask the maintainer 'luke_liao <luke_liao@126.com>' to fix it.")
    endif()
    _list_append_unique(handsfree_2dnav_INCLUDE_DIRS ${include})
  endforeach()
endif()

set(libraries "")
foreach(library ${libraries})
  # keep build configuration keywords, target names and absolute libraries as-is
  if("${library}" MATCHES "^(debug|optimized|general)$")
    list(APPEND handsfree_2dnav_LIBRARIES ${library})
  elseif(TARGET ${library})
    list(APPEND handsfree_2dnav_LIBRARIES ${library})
  elseif(IS_ABSOLUTE ${library})
    list(APPEND handsfree_2dnav_LIBRARIES ${library})
  else()
    set(lib_path "")
    set(lib "${library}-NOTFOUND")
    # since the path where the library is found is returned we have to iterate over the paths manually
    foreach(path /home/cyb7369299/My_Workspace/xyi_ws/devel/lib;/home/cyb7369299/My_Workspace/xyi_ws/devel/lib;/home/cyb7369299/My_Workspace/catkin_ws/devel/lib;/opt/ros/jade/lib)
      find_library(lib ${library}
        PATHS ${path}
        NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
      if(lib)
        set(lib_path ${path})
        break()
      endif()
    endforeach()
    if(lib)
      _list_append_unique(handsfree_2dnav_LIBRARY_DIRS ${lib_path})
      list(APPEND handsfree_2dnav_LIBRARIES ${lib})
    else()
      # as a fall back for non-catkin libraries try to search globally
      find_library(lib ${library})
      if(NOT lib)
        message(FATAL_ERROR "Project '${PROJECT_NAME}' tried to find library '${library}'.  The library is neither a target nor built/installed properly.  Did you compile project 'handsfree_2dnav'?  Did you find_package() it before the subdirectory containing its code is included?")
      endif()
      list(APPEND handsfree_2dnav_LIBRARIES ${lib})
    endif()
  endif()
endforeach()

set(handsfree_2dnav_EXPORTED_TARGETS "")
# create dummy targets for exported code generation targets to make life of users easier
foreach(t ${handsfree_2dnav_EXPORTED_TARGETS})
  if(NOT TARGET ${t})
    add_custom_target(${t})
  endif()
endforeach()

set(depends "")
foreach(depend ${depends})
  string(REPLACE " " ";" depend_list ${depend})
  # the package name of the dependency must be kept in a unique variable so that it is not overwritten in recursive calls
  list(GET depend_list 0 handsfree_2dnav_dep)
  list(LENGTH depend_list count)
  if(${count} EQUAL 1)
    # simple dependencies must only be find_package()-ed once
    if(NOT ${handsfree_2dnav_dep}_FOUND)
      find_package(${handsfree_2dnav_dep} REQUIRED)
    endif()
  else()
    # dependencies with components must be find_package()-ed again
    list(REMOVE_AT depend_list 0)
    find_package(${handsfree_2dnav_dep} REQUIRED ${depend_list})
  endif()
  _list_append_unique(handsfree_2dnav_INCLUDE_DIRS ${${handsfree_2dnav_dep}_INCLUDE_DIRS})

  # merge build configuration keywords with library names to correctly deduplicate
  _pack_libraries_with_build_configuration(handsfree_2dnav_LIBRARIES ${handsfree_2dnav_LIBRARIES})
  _pack_libraries_with_build_configuration(_libraries ${${handsfree_2dnav_dep}_LIBRARIES})
  _list_append_deduplicate(handsfree_2dnav_LIBRARIES ${_libraries})
  # undo build configuration keyword merging after deduplication
  _unpack_libraries_with_build_configuration(handsfree_2dnav_LIBRARIES ${handsfree_2dnav_LIBRARIES})

  _list_append_unique(handsfree_2dnav_LIBRARY_DIRS ${${handsfree_2dnav_dep}_LIBRARY_DIRS})
  list(APPEND handsfree_2dnav_EXPORTED_TARGETS ${${handsfree_2dnav_dep}_EXPORTED_TARGETS})
endforeach()

set(pkg_cfg_extras "")
foreach(extra ${pkg_cfg_extras})
  if(NOT IS_ABSOLUTE ${extra})
    set(extra ${handsfree_2dnav_DIR}/${extra})
  endif()
  include(${extra})
endforeach()

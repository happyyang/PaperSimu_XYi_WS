# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "xiaoyi_swd: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ixiaoyi_swd:/home/cyb7369299/My_Workspace/xyi_ws/src/xiaoyi_swd/msg;-Igeometry_msgs:/opt/ros/jade/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/jade/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(xiaoyi_swd_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/cyb7369299/My_Workspace/xyi_ws/src/xiaoyi_swd/msg/MDtaPack_Lvl0.msg" NAME_WE)
add_custom_target(_xiaoyi_swd_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "xiaoyi_swd" "/home/cyb7369299/My_Workspace/xyi_ws/src/xiaoyi_swd/msg/MDtaPack_Lvl0.msg" "geometry_msgs/Pose:geometry_msgs/Quaternion:geometry_msgs/Point32:geometry_msgs/Point"
)

#
#  langs = gencpp;geneus;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(xiaoyi_swd
  "/home/cyb7369299/My_Workspace/xyi_ws/src/xiaoyi_swd/msg/MDtaPack_Lvl0.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/jade/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/jade/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/jade/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/xiaoyi_swd
)

### Generating Services

### Generating Module File
_generate_module_cpp(xiaoyi_swd
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/xiaoyi_swd
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(xiaoyi_swd_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(xiaoyi_swd_generate_messages xiaoyi_swd_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cyb7369299/My_Workspace/xyi_ws/src/xiaoyi_swd/msg/MDtaPack_Lvl0.msg" NAME_WE)
add_dependencies(xiaoyi_swd_generate_messages_cpp _xiaoyi_swd_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(xiaoyi_swd_gencpp)
add_dependencies(xiaoyi_swd_gencpp xiaoyi_swd_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS xiaoyi_swd_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(xiaoyi_swd
  "/home/cyb7369299/My_Workspace/xyi_ws/src/xiaoyi_swd/msg/MDtaPack_Lvl0.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/jade/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/jade/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/jade/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/xiaoyi_swd
)

### Generating Services

### Generating Module File
_generate_module_eus(xiaoyi_swd
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/xiaoyi_swd
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(xiaoyi_swd_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(xiaoyi_swd_generate_messages xiaoyi_swd_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cyb7369299/My_Workspace/xyi_ws/src/xiaoyi_swd/msg/MDtaPack_Lvl0.msg" NAME_WE)
add_dependencies(xiaoyi_swd_generate_messages_eus _xiaoyi_swd_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(xiaoyi_swd_geneus)
add_dependencies(xiaoyi_swd_geneus xiaoyi_swd_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS xiaoyi_swd_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(xiaoyi_swd
  "/home/cyb7369299/My_Workspace/xyi_ws/src/xiaoyi_swd/msg/MDtaPack_Lvl0.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/jade/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/jade/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/jade/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/xiaoyi_swd
)

### Generating Services

### Generating Module File
_generate_module_lisp(xiaoyi_swd
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/xiaoyi_swd
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(xiaoyi_swd_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(xiaoyi_swd_generate_messages xiaoyi_swd_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cyb7369299/My_Workspace/xyi_ws/src/xiaoyi_swd/msg/MDtaPack_Lvl0.msg" NAME_WE)
add_dependencies(xiaoyi_swd_generate_messages_lisp _xiaoyi_swd_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(xiaoyi_swd_genlisp)
add_dependencies(xiaoyi_swd_genlisp xiaoyi_swd_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS xiaoyi_swd_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(xiaoyi_swd
  "/home/cyb7369299/My_Workspace/xyi_ws/src/xiaoyi_swd/msg/MDtaPack_Lvl0.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/jade/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/jade/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/jade/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/jade/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/xiaoyi_swd
)

### Generating Services

### Generating Module File
_generate_module_py(xiaoyi_swd
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/xiaoyi_swd
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(xiaoyi_swd_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(xiaoyi_swd_generate_messages xiaoyi_swd_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cyb7369299/My_Workspace/xyi_ws/src/xiaoyi_swd/msg/MDtaPack_Lvl0.msg" NAME_WE)
add_dependencies(xiaoyi_swd_generate_messages_py _xiaoyi_swd_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(xiaoyi_swd_genpy)
add_dependencies(xiaoyi_swd_genpy xiaoyi_swd_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS xiaoyi_swd_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/xiaoyi_swd)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/xiaoyi_swd
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(xiaoyi_swd_generate_messages_cpp geometry_msgs_generate_messages_cpp)

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/xiaoyi_swd)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/xiaoyi_swd
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
add_dependencies(xiaoyi_swd_generate_messages_eus geometry_msgs_generate_messages_eus)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/xiaoyi_swd)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/xiaoyi_swd
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(xiaoyi_swd_generate_messages_lisp geometry_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/xiaoyi_swd)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/xiaoyi_swd\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/xiaoyi_swd
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(xiaoyi_swd_generate_messages_py geometry_msgs_generate_messages_py)

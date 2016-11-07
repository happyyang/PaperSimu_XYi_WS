
(cl:in-package :asdf)

(defsystem "handsfree_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "robot_state" :depends-on ("_package_robot_state"))
    (:file "_package_robot_state" :depends-on ("_package"))
    (:file "parameters" :depends-on ("_package_parameters"))
    (:file "_package_parameters" :depends-on ("_package"))
  ))
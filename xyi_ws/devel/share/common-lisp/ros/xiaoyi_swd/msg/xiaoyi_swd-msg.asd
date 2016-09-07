
(cl:in-package :asdf)

(defsystem "xiaoyi_swd-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "MDtaPack_Lvl0" :depends-on ("_package_MDtaPack_Lvl0"))
    (:file "_package_MDtaPack_Lvl0" :depends-on ("_package"))
  ))
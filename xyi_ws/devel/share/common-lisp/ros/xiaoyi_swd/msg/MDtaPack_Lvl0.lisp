; Auto-generated. Do not edit!


(cl:in-package xiaoyi_swd-msg)


;//! \htmlinclude MDtaPack_Lvl0.msg.html

(cl:defclass <MDtaPack_Lvl0> (roslisp-msg-protocol:ros-message)
  ((bdta_use
    :reader bdta_use
    :initarg :bdta_use
    :type cl:fixnum
    :initform 0)
   (bdta0
    :reader bdta0
    :initarg :bdta0
    :type cl:boolean
    :initform cl:nil)
   (bdta1
    :reader bdta1
    :initarg :bdta1
    :type cl:boolean
    :initform cl:nil)
   (bdta2
    :reader bdta2
    :initarg :bdta2
    :type cl:boolean
    :initform cl:nil)
   (idta_use
    :reader idta_use
    :initarg :idta_use
    :type cl:fixnum
    :initform 0)
   (idta0
    :reader idta0
    :initarg :idta0
    :type cl:integer
    :initform 0)
   (idta1
    :reader idta1
    :initarg :idta1
    :type cl:integer
    :initform 0)
   (idta2
    :reader idta2
    :initarg :idta2
    :type cl:integer
    :initform 0)
   (fdta_use
    :reader fdta_use
    :initarg :fdta_use
    :type cl:fixnum
    :initform 0)
   (fdta0
    :reader fdta0
    :initarg :fdta0
    :type cl:float
    :initform 0.0)
   (fdta1
    :reader fdta1
    :initarg :fdta1
    :type cl:float
    :initform 0.0)
   (fdta2
    :reader fdta2
    :initarg :fdta2
    :type cl:float
    :initform 0.0)
   (carray_use
    :reader carray_use
    :initarg :carray_use
    :type cl:fixnum
    :initform 0)
   (carray0
    :reader carray0
    :initarg :carray0
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (carray1
    :reader carray1
    :initarg :carray1
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (carray2
    :reader carray2
    :initarg :carray2
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (iarray_use
    :reader iarray_use
    :initarg :iarray_use
    :type cl:fixnum
    :initform 0)
   (iarray0
    :reader iarray0
    :initarg :iarray0
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (iarray1
    :reader iarray1
    :initarg :iarray1
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (farray_use
    :reader farray_use
    :initarg :farray_use
    :type cl:fixnum
    :initform 0)
   (farray0
    :reader farray0
    :initarg :farray0
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (farray1
    :reader farray1
    :initarg :farray1
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (farray2
    :reader farray2
    :initarg :farray2
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (farray3
    :reader farray3
    :initarg :farray3
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (farray4
    :reader farray4
    :initarg :farray4
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (farray5
    :reader farray5
    :initarg :farray5
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (point32dta
    :reader point32dta
    :initarg :point32dta
    :type geometry_msgs-msg:Point32
    :initform (cl:make-instance 'geometry_msgs-msg:Point32))
   (posedta
    :reader posedta
    :initarg :posedta
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose)))
)

(cl:defclass MDtaPack_Lvl0 (<MDtaPack_Lvl0>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MDtaPack_Lvl0>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MDtaPack_Lvl0)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name xiaoyi_swd-msg:<MDtaPack_Lvl0> is deprecated: use xiaoyi_swd-msg:MDtaPack_Lvl0 instead.")))

(cl:ensure-generic-function 'bdta_use-val :lambda-list '(m))
(cl:defmethod bdta_use-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:bdta_use-val is deprecated.  Use xiaoyi_swd-msg:bdta_use instead.")
  (bdta_use m))

(cl:ensure-generic-function 'bdta0-val :lambda-list '(m))
(cl:defmethod bdta0-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:bdta0-val is deprecated.  Use xiaoyi_swd-msg:bdta0 instead.")
  (bdta0 m))

(cl:ensure-generic-function 'bdta1-val :lambda-list '(m))
(cl:defmethod bdta1-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:bdta1-val is deprecated.  Use xiaoyi_swd-msg:bdta1 instead.")
  (bdta1 m))

(cl:ensure-generic-function 'bdta2-val :lambda-list '(m))
(cl:defmethod bdta2-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:bdta2-val is deprecated.  Use xiaoyi_swd-msg:bdta2 instead.")
  (bdta2 m))

(cl:ensure-generic-function 'idta_use-val :lambda-list '(m))
(cl:defmethod idta_use-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:idta_use-val is deprecated.  Use xiaoyi_swd-msg:idta_use instead.")
  (idta_use m))

(cl:ensure-generic-function 'idta0-val :lambda-list '(m))
(cl:defmethod idta0-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:idta0-val is deprecated.  Use xiaoyi_swd-msg:idta0 instead.")
  (idta0 m))

(cl:ensure-generic-function 'idta1-val :lambda-list '(m))
(cl:defmethod idta1-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:idta1-val is deprecated.  Use xiaoyi_swd-msg:idta1 instead.")
  (idta1 m))

(cl:ensure-generic-function 'idta2-val :lambda-list '(m))
(cl:defmethod idta2-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:idta2-val is deprecated.  Use xiaoyi_swd-msg:idta2 instead.")
  (idta2 m))

(cl:ensure-generic-function 'fdta_use-val :lambda-list '(m))
(cl:defmethod fdta_use-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:fdta_use-val is deprecated.  Use xiaoyi_swd-msg:fdta_use instead.")
  (fdta_use m))

(cl:ensure-generic-function 'fdta0-val :lambda-list '(m))
(cl:defmethod fdta0-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:fdta0-val is deprecated.  Use xiaoyi_swd-msg:fdta0 instead.")
  (fdta0 m))

(cl:ensure-generic-function 'fdta1-val :lambda-list '(m))
(cl:defmethod fdta1-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:fdta1-val is deprecated.  Use xiaoyi_swd-msg:fdta1 instead.")
  (fdta1 m))

(cl:ensure-generic-function 'fdta2-val :lambda-list '(m))
(cl:defmethod fdta2-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:fdta2-val is deprecated.  Use xiaoyi_swd-msg:fdta2 instead.")
  (fdta2 m))

(cl:ensure-generic-function 'carray_use-val :lambda-list '(m))
(cl:defmethod carray_use-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:carray_use-val is deprecated.  Use xiaoyi_swd-msg:carray_use instead.")
  (carray_use m))

(cl:ensure-generic-function 'carray0-val :lambda-list '(m))
(cl:defmethod carray0-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:carray0-val is deprecated.  Use xiaoyi_swd-msg:carray0 instead.")
  (carray0 m))

(cl:ensure-generic-function 'carray1-val :lambda-list '(m))
(cl:defmethod carray1-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:carray1-val is deprecated.  Use xiaoyi_swd-msg:carray1 instead.")
  (carray1 m))

(cl:ensure-generic-function 'carray2-val :lambda-list '(m))
(cl:defmethod carray2-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:carray2-val is deprecated.  Use xiaoyi_swd-msg:carray2 instead.")
  (carray2 m))

(cl:ensure-generic-function 'iarray_use-val :lambda-list '(m))
(cl:defmethod iarray_use-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:iarray_use-val is deprecated.  Use xiaoyi_swd-msg:iarray_use instead.")
  (iarray_use m))

(cl:ensure-generic-function 'iarray0-val :lambda-list '(m))
(cl:defmethod iarray0-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:iarray0-val is deprecated.  Use xiaoyi_swd-msg:iarray0 instead.")
  (iarray0 m))

(cl:ensure-generic-function 'iarray1-val :lambda-list '(m))
(cl:defmethod iarray1-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:iarray1-val is deprecated.  Use xiaoyi_swd-msg:iarray1 instead.")
  (iarray1 m))

(cl:ensure-generic-function 'farray_use-val :lambda-list '(m))
(cl:defmethod farray_use-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:farray_use-val is deprecated.  Use xiaoyi_swd-msg:farray_use instead.")
  (farray_use m))

(cl:ensure-generic-function 'farray0-val :lambda-list '(m))
(cl:defmethod farray0-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:farray0-val is deprecated.  Use xiaoyi_swd-msg:farray0 instead.")
  (farray0 m))

(cl:ensure-generic-function 'farray1-val :lambda-list '(m))
(cl:defmethod farray1-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:farray1-val is deprecated.  Use xiaoyi_swd-msg:farray1 instead.")
  (farray1 m))

(cl:ensure-generic-function 'farray2-val :lambda-list '(m))
(cl:defmethod farray2-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:farray2-val is deprecated.  Use xiaoyi_swd-msg:farray2 instead.")
  (farray2 m))

(cl:ensure-generic-function 'farray3-val :lambda-list '(m))
(cl:defmethod farray3-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:farray3-val is deprecated.  Use xiaoyi_swd-msg:farray3 instead.")
  (farray3 m))

(cl:ensure-generic-function 'farray4-val :lambda-list '(m))
(cl:defmethod farray4-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:farray4-val is deprecated.  Use xiaoyi_swd-msg:farray4 instead.")
  (farray4 m))

(cl:ensure-generic-function 'farray5-val :lambda-list '(m))
(cl:defmethod farray5-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:farray5-val is deprecated.  Use xiaoyi_swd-msg:farray5 instead.")
  (farray5 m))

(cl:ensure-generic-function 'point32dta-val :lambda-list '(m))
(cl:defmethod point32dta-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:point32dta-val is deprecated.  Use xiaoyi_swd-msg:point32dta instead.")
  (point32dta m))

(cl:ensure-generic-function 'posedta-val :lambda-list '(m))
(cl:defmethod posedta-val ((m <MDtaPack_Lvl0>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xiaoyi_swd-msg:posedta-val is deprecated.  Use xiaoyi_swd-msg:posedta instead.")
  (posedta m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MDtaPack_Lvl0>) ostream)
  "Serializes a message object of type '<MDtaPack_Lvl0>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bdta_use)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'bdta0) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'bdta1) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'bdta2) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'idta_use)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'idta0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'idta0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'idta0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'idta0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'idta1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'idta1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'idta1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'idta1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'idta2)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'idta2)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'idta2)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'idta2)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'fdta_use)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'fdta0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'fdta1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'fdta2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'carray_use)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'carray0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'carray0))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'carray1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'carray1))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'carray2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'carray2))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'iarray_use)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'iarray0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) ele) ostream))
   (cl:slot-value msg 'iarray0))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'iarray1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) ele) ostream))
   (cl:slot-value msg 'iarray1))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'farray_use)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'farray0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'farray0))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'farray1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'farray1))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'farray2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'farray2))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'farray3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'farray3))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'farray4))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'farray4))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'farray5))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'farray5))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'point32dta) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'posedta) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MDtaPack_Lvl0>) istream)
  "Deserializes a message object of type '<MDtaPack_Lvl0>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bdta_use)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'bdta0) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'bdta1) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'bdta2) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'idta_use)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'idta0)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'idta0)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'idta0)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'idta0)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'idta1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'idta1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'idta1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'idta1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'idta2)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'idta2)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'idta2)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'idta2)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'fdta_use)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'fdta0) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'fdta1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'fdta2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'carray_use)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'carray0) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'carray0)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'carray1) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'carray1)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'carray2) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'carray2)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'iarray_use)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'iarray0) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'iarray0)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:aref vals i)) (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'iarray1) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'iarray1)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:aref vals i)) (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'farray_use)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'farray0) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'farray0)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'farray1) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'farray1)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'farray2) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'farray2)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'farray3) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'farray3)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'farray4) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'farray4)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'farray5) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'farray5)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'point32dta) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'posedta) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MDtaPack_Lvl0>)))
  "Returns string type for a message object of type '<MDtaPack_Lvl0>"
  "xiaoyi_swd/MDtaPack_Lvl0")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MDtaPack_Lvl0)))
  "Returns string type for a message object of type 'MDtaPack_Lvl0"
  "xiaoyi_swd/MDtaPack_Lvl0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MDtaPack_Lvl0>)))
  "Returns md5sum for a message object of type '<MDtaPack_Lvl0>"
  "0d624bbd853ed36260975cb1970e85ab")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MDtaPack_Lvl0)))
  "Returns md5sum for a message object of type 'MDtaPack_Lvl0"
  "0d624bbd853ed36260975cb1970e85ab")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MDtaPack_Lvl0>)))
  "Returns full string definition for message of type '<MDtaPack_Lvl0>"
  (cl:format cl:nil "uint8 bdta_use~%bool bdta0~%bool bdta1~%bool bdta2~%~%uint8 idta_use~%uint32 idta0~%uint32 idta1~%uint32 idta2~%~%uint8 fdta_use~%float32 fdta0~%float32 fdta1~%float32 fdta2~%~%uint8 carray_use~%uint8[] carray0~%uint8[] carray1~%uint8[] carray2~%~%uint8 iarray_use~%uint32[] iarray0~%uint32[] iarray1~%~%uint8 farray_use~%float32[] farray0~%float32[] farray1~%float32[] farray2~%float32[] farray3~%float32[] farray4~%float32[] farray5~%~%geometry_msgs/Point32 point32dta~%geometry_msgs/Pose posedta~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of postion and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MDtaPack_Lvl0)))
  "Returns full string definition for message of type 'MDtaPack_Lvl0"
  (cl:format cl:nil "uint8 bdta_use~%bool bdta0~%bool bdta1~%bool bdta2~%~%uint8 idta_use~%uint32 idta0~%uint32 idta1~%uint32 idta2~%~%uint8 fdta_use~%float32 fdta0~%float32 fdta1~%float32 fdta2~%~%uint8 carray_use~%uint8[] carray0~%uint8[] carray1~%uint8[] carray2~%~%uint8 iarray_use~%uint32[] iarray0~%uint32[] iarray1~%~%uint8 farray_use~%float32[] farray0~%float32[] farray1~%float32[] farray2~%float32[] farray3~%float32[] farray4~%float32[] farray5~%~%geometry_msgs/Point32 point32dta~%geometry_msgs/Pose posedta~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of postion and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MDtaPack_Lvl0>))
  (cl:+ 0
     1
     1
     1
     1
     1
     4
     4
     4
     1
     4
     4
     4
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'carray0) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'carray1) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'carray2) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'iarray0) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'iarray1) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'farray0) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'farray1) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'farray2) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'farray3) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'farray4) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'farray5) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'point32dta))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'posedta))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MDtaPack_Lvl0>))
  "Converts a ROS message object to a list"
  (cl:list 'MDtaPack_Lvl0
    (cl:cons ':bdta_use (bdta_use msg))
    (cl:cons ':bdta0 (bdta0 msg))
    (cl:cons ':bdta1 (bdta1 msg))
    (cl:cons ':bdta2 (bdta2 msg))
    (cl:cons ':idta_use (idta_use msg))
    (cl:cons ':idta0 (idta0 msg))
    (cl:cons ':idta1 (idta1 msg))
    (cl:cons ':idta2 (idta2 msg))
    (cl:cons ':fdta_use (fdta_use msg))
    (cl:cons ':fdta0 (fdta0 msg))
    (cl:cons ':fdta1 (fdta1 msg))
    (cl:cons ':fdta2 (fdta2 msg))
    (cl:cons ':carray_use (carray_use msg))
    (cl:cons ':carray0 (carray0 msg))
    (cl:cons ':carray1 (carray1 msg))
    (cl:cons ':carray2 (carray2 msg))
    (cl:cons ':iarray_use (iarray_use msg))
    (cl:cons ':iarray0 (iarray0 msg))
    (cl:cons ':iarray1 (iarray1 msg))
    (cl:cons ':farray_use (farray_use msg))
    (cl:cons ':farray0 (farray0 msg))
    (cl:cons ':farray1 (farray1 msg))
    (cl:cons ':farray2 (farray2 msg))
    (cl:cons ':farray3 (farray3 msg))
    (cl:cons ':farray4 (farray4 msg))
    (cl:cons ':farray5 (farray5 msg))
    (cl:cons ':point32dta (point32dta msg))
    (cl:cons ':posedta (posedta msg))
))

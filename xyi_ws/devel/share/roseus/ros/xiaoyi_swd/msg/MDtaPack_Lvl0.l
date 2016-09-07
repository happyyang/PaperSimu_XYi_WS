;; Auto-generated. Do not edit!


(when (boundp 'xiaoyi_swd::MDtaPack_Lvl0)
  (if (not (find-package "XIAOYI_SWD"))
    (make-package "XIAOYI_SWD"))
  (shadow 'MDtaPack_Lvl0 (find-package "XIAOYI_SWD")))
(unless (find-package "XIAOYI_SWD::MDTAPACK_LVL0")
  (make-package "XIAOYI_SWD::MDTAPACK_LVL0"))

(in-package "ROS")
;;//! \htmlinclude MDtaPack_Lvl0.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass xiaoyi_swd::MDtaPack_Lvl0
  :super ros::object
  :slots (_bdta_use _bdta0 _bdta1 _bdta2 _idta_use _idta0 _idta1 _idta2 _fdta_use _fdta0 _fdta1 _fdta2 _carray_use _carray0 _carray1 _carray2 _iarray_use _iarray0 _iarray1 _farray_use _farray0 _farray1 _farray2 _farray3 _farray4 _farray5 _point32dta _posedta ))

(defmethod xiaoyi_swd::MDtaPack_Lvl0
  (:init
   (&key
    ((:bdta_use __bdta_use) 0)
    ((:bdta0 __bdta0) nil)
    ((:bdta1 __bdta1) nil)
    ((:bdta2 __bdta2) nil)
    ((:idta_use __idta_use) 0)
    ((:idta0 __idta0) 0)
    ((:idta1 __idta1) 0)
    ((:idta2 __idta2) 0)
    ((:fdta_use __fdta_use) 0)
    ((:fdta0 __fdta0) 0.0)
    ((:fdta1 __fdta1) 0.0)
    ((:fdta2 __fdta2) 0.0)
    ((:carray_use __carray_use) 0)
    ((:carray0 __carray0) (make-array 0 :initial-element 0 :element-type :char))
    ((:carray1 __carray1) (make-array 0 :initial-element 0 :element-type :char))
    ((:carray2 __carray2) (make-array 0 :initial-element 0 :element-type :char))
    ((:iarray_use __iarray_use) 0)
    ((:iarray0 __iarray0) (make-array 0 :initial-element 0 :element-type :integer))
    ((:iarray1 __iarray1) (make-array 0 :initial-element 0 :element-type :integer))
    ((:farray_use __farray_use) 0)
    ((:farray0 __farray0) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:farray1 __farray1) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:farray2 __farray2) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:farray3 __farray3) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:farray4 __farray4) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:farray5 __farray5) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:point32dta __point32dta) (instance geometry_msgs::Point32 :init))
    ((:posedta __posedta) (instance geometry_msgs::Pose :init))
    )
   (send-super :init)
   (setq _bdta_use (round __bdta_use))
   (setq _bdta0 __bdta0)
   (setq _bdta1 __bdta1)
   (setq _bdta2 __bdta2)
   (setq _idta_use (round __idta_use))
   (setq _idta0 (round __idta0))
   (setq _idta1 (round __idta1))
   (setq _idta2 (round __idta2))
   (setq _fdta_use (round __fdta_use))
   (setq _fdta0 (float __fdta0))
   (setq _fdta1 (float __fdta1))
   (setq _fdta2 (float __fdta2))
   (setq _carray_use (round __carray_use))
   (setq _carray0 __carray0)
   (setq _carray1 __carray1)
   (setq _carray2 __carray2)
   (setq _iarray_use (round __iarray_use))
   (setq _iarray0 __iarray0)
   (setq _iarray1 __iarray1)
   (setq _farray_use (round __farray_use))
   (setq _farray0 __farray0)
   (setq _farray1 __farray1)
   (setq _farray2 __farray2)
   (setq _farray3 __farray3)
   (setq _farray4 __farray4)
   (setq _farray5 __farray5)
   (setq _point32dta __point32dta)
   (setq _posedta __posedta)
   self)
  (:bdta_use
   (&optional __bdta_use)
   (if __bdta_use (setq _bdta_use __bdta_use)) _bdta_use)
  (:bdta0
   (&optional __bdta0)
   (if __bdta0 (setq _bdta0 __bdta0)) _bdta0)
  (:bdta1
   (&optional __bdta1)
   (if __bdta1 (setq _bdta1 __bdta1)) _bdta1)
  (:bdta2
   (&optional __bdta2)
   (if __bdta2 (setq _bdta2 __bdta2)) _bdta2)
  (:idta_use
   (&optional __idta_use)
   (if __idta_use (setq _idta_use __idta_use)) _idta_use)
  (:idta0
   (&optional __idta0)
   (if __idta0 (setq _idta0 __idta0)) _idta0)
  (:idta1
   (&optional __idta1)
   (if __idta1 (setq _idta1 __idta1)) _idta1)
  (:idta2
   (&optional __idta2)
   (if __idta2 (setq _idta2 __idta2)) _idta2)
  (:fdta_use
   (&optional __fdta_use)
   (if __fdta_use (setq _fdta_use __fdta_use)) _fdta_use)
  (:fdta0
   (&optional __fdta0)
   (if __fdta0 (setq _fdta0 __fdta0)) _fdta0)
  (:fdta1
   (&optional __fdta1)
   (if __fdta1 (setq _fdta1 __fdta1)) _fdta1)
  (:fdta2
   (&optional __fdta2)
   (if __fdta2 (setq _fdta2 __fdta2)) _fdta2)
  (:carray_use
   (&optional __carray_use)
   (if __carray_use (setq _carray_use __carray_use)) _carray_use)
  (:carray0
   (&optional __carray0)
   (if __carray0 (setq _carray0 __carray0)) _carray0)
  (:carray1
   (&optional __carray1)
   (if __carray1 (setq _carray1 __carray1)) _carray1)
  (:carray2
   (&optional __carray2)
   (if __carray2 (setq _carray2 __carray2)) _carray2)
  (:iarray_use
   (&optional __iarray_use)
   (if __iarray_use (setq _iarray_use __iarray_use)) _iarray_use)
  (:iarray0
   (&optional __iarray0)
   (if __iarray0 (setq _iarray0 __iarray0)) _iarray0)
  (:iarray1
   (&optional __iarray1)
   (if __iarray1 (setq _iarray1 __iarray1)) _iarray1)
  (:farray_use
   (&optional __farray_use)
   (if __farray_use (setq _farray_use __farray_use)) _farray_use)
  (:farray0
   (&optional __farray0)
   (if __farray0 (setq _farray0 __farray0)) _farray0)
  (:farray1
   (&optional __farray1)
   (if __farray1 (setq _farray1 __farray1)) _farray1)
  (:farray2
   (&optional __farray2)
   (if __farray2 (setq _farray2 __farray2)) _farray2)
  (:farray3
   (&optional __farray3)
   (if __farray3 (setq _farray3 __farray3)) _farray3)
  (:farray4
   (&optional __farray4)
   (if __farray4 (setq _farray4 __farray4)) _farray4)
  (:farray5
   (&optional __farray5)
   (if __farray5 (setq _farray5 __farray5)) _farray5)
  (:point32dta
   (&rest __point32dta)
   (if (keywordp (car __point32dta))
       (send* _point32dta __point32dta)
     (progn
       (if __point32dta (setq _point32dta (car __point32dta)))
       _point32dta)))
  (:posedta
   (&rest __posedta)
   (if (keywordp (car __posedta))
       (send* _posedta __posedta)
     (progn
       (if __posedta (setq _posedta (car __posedta)))
       _posedta)))
  (:serialization-length
   ()
   (+
    ;; uint8 _bdta_use
    1
    ;; bool _bdta0
    1
    ;; bool _bdta1
    1
    ;; bool _bdta2
    1
    ;; uint8 _idta_use
    1
    ;; uint32 _idta0
    4
    ;; uint32 _idta1
    4
    ;; uint32 _idta2
    4
    ;; uint8 _fdta_use
    1
    ;; float32 _fdta0
    4
    ;; float32 _fdta1
    4
    ;; float32 _fdta2
    4
    ;; uint8 _carray_use
    1
    ;; uint8[] _carray0
    (* 1    (length _carray0)) 4
    ;; uint8[] _carray1
    (* 1    (length _carray1)) 4
    ;; uint8[] _carray2
    (* 1    (length _carray2)) 4
    ;; uint8 _iarray_use
    1
    ;; uint32[] _iarray0
    (* 4    (length _iarray0)) 4
    ;; uint32[] _iarray1
    (* 4    (length _iarray1)) 4
    ;; uint8 _farray_use
    1
    ;; float32[] _farray0
    (* 4    (length _farray0)) 4
    ;; float32[] _farray1
    (* 4    (length _farray1)) 4
    ;; float32[] _farray2
    (* 4    (length _farray2)) 4
    ;; float32[] _farray3
    (* 4    (length _farray3)) 4
    ;; float32[] _farray4
    (* 4    (length _farray4)) 4
    ;; float32[] _farray5
    (* 4    (length _farray5)) 4
    ;; geometry_msgs/Point32 _point32dta
    (send _point32dta :serialization-length)
    ;; geometry_msgs/Pose _posedta
    (send _posedta :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _bdta_use
       (write-byte _bdta_use s)
     ;; bool _bdta0
       (if _bdta0 (write-byte -1 s) (write-byte 0 s))
     ;; bool _bdta1
       (if _bdta1 (write-byte -1 s) (write-byte 0 s))
     ;; bool _bdta2
       (if _bdta2 (write-byte -1 s) (write-byte 0 s))
     ;; uint8 _idta_use
       (write-byte _idta_use s)
     ;; uint32 _idta0
       (write-long _idta0 s)
     ;; uint32 _idta1
       (write-long _idta1 s)
     ;; uint32 _idta2
       (write-long _idta2 s)
     ;; uint8 _fdta_use
       (write-byte _fdta_use s)
     ;; float32 _fdta0
       (sys::poke _fdta0 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _fdta1
       (sys::poke _fdta1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _fdta2
       (sys::poke _fdta2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint8 _carray_use
       (write-byte _carray_use s)
     ;; uint8[] _carray0
     (write-long (length _carray0) s)
     (princ _carray0 s)
     ;; uint8[] _carray1
     (write-long (length _carray1) s)
     (princ _carray1 s)
     ;; uint8[] _carray2
     (write-long (length _carray2) s)
     (princ _carray2 s)
     ;; uint8 _iarray_use
       (write-byte _iarray_use s)
     ;; uint32[] _iarray0
     (write-long (length _iarray0) s)
     (dotimes (i (length _iarray0))
       (write-long (elt _iarray0 i) s)
       )
     ;; uint32[] _iarray1
     (write-long (length _iarray1) s)
     (dotimes (i (length _iarray1))
       (write-long (elt _iarray1 i) s)
       )
     ;; uint8 _farray_use
       (write-byte _farray_use s)
     ;; float32[] _farray0
     (write-long (length _farray0) s)
     (dotimes (i (length _farray0))
       (sys::poke (elt _farray0 i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _farray1
     (write-long (length _farray1) s)
     (dotimes (i (length _farray1))
       (sys::poke (elt _farray1 i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _farray2
     (write-long (length _farray2) s)
     (dotimes (i (length _farray2))
       (sys::poke (elt _farray2 i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _farray3
     (write-long (length _farray3) s)
     (dotimes (i (length _farray3))
       (sys::poke (elt _farray3 i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _farray4
     (write-long (length _farray4) s)
     (dotimes (i (length _farray4))
       (sys::poke (elt _farray4 i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _farray5
     (write-long (length _farray5) s)
     (dotimes (i (length _farray5))
       (sys::poke (elt _farray5 i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; geometry_msgs/Point32 _point32dta
       (send _point32dta :serialize s)
     ;; geometry_msgs/Pose _posedta
       (send _posedta :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _bdta_use
     (setq _bdta_use (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; bool _bdta0
     (setq _bdta0 (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _bdta1
     (setq _bdta1 (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _bdta2
     (setq _bdta2 (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; uint8 _idta_use
     (setq _idta_use (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint32 _idta0
     (setq _idta0 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _idta1
     (setq _idta1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _idta2
     (setq _idta2 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8 _fdta_use
     (setq _fdta_use (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float32 _fdta0
     (setq _fdta0 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _fdta1
     (setq _fdta1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _fdta2
     (setq _fdta2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint8 _carray_use
     (setq _carray_use (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8[] _carray0
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _carray0 (make-array n :element-type :char))
     (replace _carray0 buf :start2 ptr-) (incf ptr- n))
   ;; uint8[] _carray1
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _carray1 (make-array n :element-type :char))
     (replace _carray1 buf :start2 ptr-) (incf ptr- n))
   ;; uint8[] _carray2
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _carray2 (make-array n :element-type :char))
     (replace _carray2 buf :start2 ptr-) (incf ptr- n))
   ;; uint8 _iarray_use
     (setq _iarray_use (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint32[] _iarray0
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _iarray0 (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _iarray0 i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; uint32[] _iarray1
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _iarray1 (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _iarray1 i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; uint8 _farray_use
     (setq _farray_use (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float32[] _farray0
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _farray0 (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _farray0 i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _farray1
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _farray1 (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _farray1 i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _farray2
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _farray2 (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _farray2 i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _farray3
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _farray3 (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _farray3 i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _farray4
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _farray4 (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _farray4 i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _farray5
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _farray5 (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _farray5 i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; geometry_msgs/Point32 _point32dta
     (send _point32dta :deserialize buf ptr-) (incf ptr- (send _point32dta :serialization-length))
   ;; geometry_msgs/Pose _posedta
     (send _posedta :deserialize buf ptr-) (incf ptr- (send _posedta :serialization-length))
   ;;
   self)
  )

(setf (get xiaoyi_swd::MDtaPack_Lvl0 :md5sum-) "0d624bbd853ed36260975cb1970e85ab")
(setf (get xiaoyi_swd::MDtaPack_Lvl0 :datatype-) "xiaoyi_swd/MDtaPack_Lvl0")
(setf (get xiaoyi_swd::MDtaPack_Lvl0 :definition-)
      "uint8 bdta_use
bool bdta0
bool bdta1
bool bdta2

uint8 idta_use
uint32 idta0
uint32 idta1
uint32 idta2

uint8 fdta_use
float32 fdta0
float32 fdta1
float32 fdta2

uint8 carray_use
uint8[] carray0
uint8[] carray1
uint8[] carray2

uint8 iarray_use
uint32[] iarray0
uint32[] iarray1

uint8 farray_use
float32[] farray0
float32[] farray1
float32[] farray2
float32[] farray3
float32[] farray4
float32[] farray5

geometry_msgs/Point32 point32dta
geometry_msgs/Pose posedta

================================================================================
MSG: geometry_msgs/Point32
# This contains the position of a point in free space(with 32 bits of precision).
# It is recommeded to use Point wherever possible instead of Point32.  
# 
# This recommendation is to promote interoperability.  
#
# This message is designed to take up less space when sending
# lots of points at once, as in the case of a PointCloud.  

float32 x
float32 y
float32 z
================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of postion and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

")



(provide :xiaoyi_swd/MDtaPack_Lvl0 "0d624bbd853ed36260975cb1970e85ab")



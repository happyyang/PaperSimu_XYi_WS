// Generated by gencpp from file handsfree_msgs/parameters.msg
// DO NOT EDIT!


#ifndef HANDSFREE_MSGS_MESSAGE_PARAMETERS_H
#define HANDSFREE_MSGS_MESSAGE_PARAMETERS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace handsfree_msgs
{
template <class ContainerAllocator>
struct parameters_
{
  typedef parameters_<ContainerAllocator> Type;

  parameters_()
    : param_name()
    , values()  {
    }
  parameters_(const ContainerAllocator& _alloc)
    : param_name(_alloc)
    , values(_alloc)  {
    }



   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _param_name_type;
  _param_name_type param_name;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _values_type;
  _values_type values;




  typedef boost::shared_ptr< ::handsfree_msgs::parameters_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::handsfree_msgs::parameters_<ContainerAllocator> const> ConstPtr;

}; // struct parameters_

typedef ::handsfree_msgs::parameters_<std::allocator<void> > parameters;

typedef boost::shared_ptr< ::handsfree_msgs::parameters > parametersPtr;
typedef boost::shared_ptr< ::handsfree_msgs::parameters const> parametersConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::handsfree_msgs::parameters_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::handsfree_msgs::parameters_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace handsfree_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/jade/share/std_msgs/cmake/../msg'], 'handsfree_msgs': ['/home/cyb7369299/My_Workspace/xyi_ws/src/handsfree_msgs/msg'], 'sensor_msgs': ['/opt/ros/jade/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/jade/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::handsfree_msgs::parameters_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::handsfree_msgs::parameters_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::handsfree_msgs::parameters_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::handsfree_msgs::parameters_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::handsfree_msgs::parameters_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::handsfree_msgs::parameters_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::handsfree_msgs::parameters_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8796a60c7639dcd20659eaeb24d59fb3";
  }

  static const char* value(const ::handsfree_msgs::parameters_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8796a60c7639dcd2ULL;
  static const uint64_t static_value2 = 0x0659eaeb24d59fb3ULL;
};

template<class ContainerAllocator>
struct DataType< ::handsfree_msgs::parameters_<ContainerAllocator> >
{
  static const char* value()
  {
    return "handsfree_msgs/parameters";
  }

  static const char* value(const ::handsfree_msgs::parameters_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::handsfree_msgs::parameters_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string[] param_name\n\
float64[] values\n\
\n\
";
  }

  static const char* value(const ::handsfree_msgs::parameters_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::handsfree_msgs::parameters_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.param_name);
      stream.next(m.values);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct parameters_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::handsfree_msgs::parameters_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::handsfree_msgs::parameters_<ContainerAllocator>& v)
  {
    s << indent << "param_name[]" << std::endl;
    for (size_t i = 0; i < v.param_name.size(); ++i)
    {
      s << indent << "  param_name[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.param_name[i]);
    }
    s << indent << "values[]" << std::endl;
    for (size_t i = 0; i < v.values.size(); ++i)
    {
      s << indent << "  values[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.values[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // HANDSFREE_MSGS_MESSAGE_PARAMETERS_H

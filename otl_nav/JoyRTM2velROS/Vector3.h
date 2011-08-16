/* Auto-generated by genmsg_cpp for file /tmp/buildd/ros-diamondback-common-msgs-1.4.0/debian/ros-diamondback-common-msgs/opt/ros/diamondback/stacks/common_msgs/geometry_msgs/msg/Vector3.msg */
#ifndef GEOMETRY_MSGS_MESSAGE_VECTOR3_H
#define GEOMETRY_MSGS_MESSAGE_VECTOR3_H
#include <string>
#include <vector>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/message.h"
#include "ros/time.h"


namespace geometry_msgs
{
template <class ContainerAllocator>
struct Vector3_ : public ros::Message
{
  typedef Vector3_<ContainerAllocator> Type;

  Vector3_()
  : x(0.0)
  , y(0.0)
  , z(0.0)
  {
  }

  Vector3_(const ContainerAllocator& _alloc)
  : x(0.0)
  , y(0.0)
  , z(0.0)
  {
  }

  typedef double _x_type;
  double x;

  typedef double _y_type;
  double y;

  typedef double _z_type;
  double z;


private:
  static const char* __s_getDataType_() { return "geometry_msgs/Vector3"; }
public:
  ROS_DEPRECATED static const std::string __s_getDataType() { return __s_getDataType_(); }

  ROS_DEPRECATED const std::string __getDataType() const { return __s_getDataType_(); }

private:
  static const char* __s_getMD5Sum_() { return "4a842b65f413084dc2b10fb484ea7f17"; }
public:
  ROS_DEPRECATED static const std::string __s_getMD5Sum() { return __s_getMD5Sum_(); }

  ROS_DEPRECATED const std::string __getMD5Sum() const { return __s_getMD5Sum_(); }

private:
  static const char* __s_getMessageDefinition_() { return "# This represents a vector in free space. \n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
"; }
public:
  ROS_DEPRECATED static const std::string __s_getMessageDefinition() { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED const std::string __getMessageDefinition() const { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
  {
    ros::serialization::OStream stream(write_ptr, 1000000000);
    ros::serialization::serialize(stream, x);
    ros::serialization::serialize(stream, y);
    ros::serialization::serialize(stream, z);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    ros::serialization::IStream stream(read_ptr, 1000000000);
    ros::serialization::deserialize(stream, x);
    ros::serialization::deserialize(stream, y);
    ros::serialization::deserialize(stream, z);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint32_t serializationLength() const
  {
    uint32_t size = 0;
    size += ros::serialization::serializationLength(x);
    size += ros::serialization::serializationLength(y);
    size += ros::serialization::serializationLength(z);
    return size;
  }

  typedef boost::shared_ptr< ::geometry_msgs::Vector3_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::geometry_msgs::Vector3_<ContainerAllocator>  const> ConstPtr;
}; // struct Vector3
typedef  ::geometry_msgs::Vector3_<std::allocator<void> > Vector3;

typedef boost::shared_ptr< ::geometry_msgs::Vector3> Vector3Ptr;
typedef boost::shared_ptr< ::geometry_msgs::Vector3 const> Vector3ConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::geometry_msgs::Vector3_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace geometry_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator>
struct MD5Sum< ::geometry_msgs::Vector3_<ContainerAllocator> > {
  static const char* value() 
  {
    return "4a842b65f413084dc2b10fb484ea7f17";
  }

  static const char* value(const  ::geometry_msgs::Vector3_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x4a842b65f413084dULL;
  static const uint64_t static_value2 = 0xc2b10fb484ea7f17ULL;
};

template<class ContainerAllocator>
struct DataType< ::geometry_msgs::Vector3_<ContainerAllocator> > {
  static const char* value() 
  {
    return "geometry_msgs/Vector3";
  }

  static const char* value(const  ::geometry_msgs::Vector3_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::geometry_msgs::Vector3_<ContainerAllocator> > {
  static const char* value() 
  {
    return "# This represents a vector in free space. \n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const  ::geometry_msgs::Vector3_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::geometry_msgs::Vector3_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::geometry_msgs::Vector3_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.x);
    stream.next(m.y);
    stream.next(m.z);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Vector3_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::geometry_msgs::Vector3_<ContainerAllocator> & v) 
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
  }
};


} // namespace message_operations
} // namespace ros

#endif // GEOMETRY_MSGS_MESSAGE_VECTOR3_H


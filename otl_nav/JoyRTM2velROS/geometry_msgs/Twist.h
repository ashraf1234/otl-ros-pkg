/* Auto-generated by genmsg_cpp for file /tmp/buildd/ros-diamondback-common-msgs-1.4.0/debian/ros-diamondback-common-msgs/opt/ros/diamondback/stacks/common_msgs/geometry_msgs/msg/Twist.msg */
#ifndef GEOMETRY_MSGS_MESSAGE_TWIST_H
#define GEOMETRY_MSGS_MESSAGE_TWIST_H
#include <string>
#include <vector>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/message.h"
#include "ros/time.h"

#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Vector3.h"

namespace geometry_msgs
{
template <class ContainerAllocator>
struct Twist_ : public ros::Message
{
  typedef Twist_<ContainerAllocator> Type;

  Twist_()
  : linear()
  , angular()
  {
  }

  Twist_(const ContainerAllocator& _alloc)
  : linear(_alloc)
  , angular(_alloc)
  {
  }

  typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _linear_type;
   ::geometry_msgs::Vector3_<ContainerAllocator>  linear;

  typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _angular_type;
   ::geometry_msgs::Vector3_<ContainerAllocator>  angular;


private:
  static const char* __s_getDataType_() { return "geometry_msgs/Twist"; }
public:
  ROS_DEPRECATED static const std::string __s_getDataType() { return __s_getDataType_(); }

  ROS_DEPRECATED const std::string __getDataType() const { return __s_getDataType_(); }

private:
  static const char* __s_getMD5Sum_() { return "9f195f881246fdfa2798d1d3eebca84a"; }
public:
  ROS_DEPRECATED static const std::string __s_getMD5Sum() { return __s_getMD5Sum_(); }

  ROS_DEPRECATED const std::string __getMD5Sum() const { return __s_getMD5Sum_(); }

private:
  static const char* __s_getMessageDefinition_() { return "# This expresses velocity in free space broken into it's linear and angular parts. \n\
Vector3  linear\n\
Vector3  angular\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
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
    ros::serialization::serialize(stream, linear);
    ros::serialization::serialize(stream, angular);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    ros::serialization::IStream stream(read_ptr, 1000000000);
    ros::serialization::deserialize(stream, linear);
    ros::serialization::deserialize(stream, angular);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint32_t serializationLength() const
  {
    uint32_t size = 0;
    size += ros::serialization::serializationLength(linear);
    size += ros::serialization::serializationLength(angular);
    return size;
  }

  typedef boost::shared_ptr< ::geometry_msgs::Twist_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::geometry_msgs::Twist_<ContainerAllocator>  const> ConstPtr;
}; // struct Twist
typedef  ::geometry_msgs::Twist_<std::allocator<void> > Twist;

typedef boost::shared_ptr< ::geometry_msgs::Twist> TwistPtr;
typedef boost::shared_ptr< ::geometry_msgs::Twist const> TwistConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::geometry_msgs::Twist_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::geometry_msgs::Twist_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace geometry_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator>
struct MD5Sum< ::geometry_msgs::Twist_<ContainerAllocator> > {
  static const char* value() 
  {
    return "9f195f881246fdfa2798d1d3eebca84a";
  }

  static const char* value(const  ::geometry_msgs::Twist_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x9f195f881246fdfaULL;
  static const uint64_t static_value2 = 0x2798d1d3eebca84aULL;
};

template<class ContainerAllocator>
struct DataType< ::geometry_msgs::Twist_<ContainerAllocator> > {
  static const char* value() 
  {
    return "geometry_msgs/Twist";
  }

  static const char* value(const  ::geometry_msgs::Twist_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::geometry_msgs::Twist_<ContainerAllocator> > {
  static const char* value() 
  {
    return "# This expresses velocity in free space broken into it's linear and angular parts. \n\
Vector3  linear\n\
Vector3  angular\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const  ::geometry_msgs::Twist_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::geometry_msgs::Twist_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::geometry_msgs::Twist_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.linear);
    stream.next(m.angular);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Twist_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::geometry_msgs::Twist_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::geometry_msgs::Twist_<ContainerAllocator> & v) 
  {
    s << indent << "linear: ";
s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.linear);
    s << indent << "angular: ";
s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.angular);
  }
};


} // namespace message_operations
} // namespace ros

#endif // GEOMETRY_MSGS_MESSAGE_TWIST_H


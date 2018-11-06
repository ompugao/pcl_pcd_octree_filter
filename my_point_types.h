#ifndef _MY_POINT_TYPES_H_
#define _MY_POINT_TYPES_H_

#include <pcl/point_types.h>

namespace pcl
{
  struct PointXYZRGBI;
}

#include "my_point_types.hpp"

POINT_CLOUD_REGISTER_POINT_STRUCT (pcl::_PointXYZRGBI,
    (float, x, x)
    (float, y, y)
    (float, z, z)
    (uint32_t, rgba, rgba)
    (float, intensity, intensity)
)
POINT_CLOUD_REGISTER_POINT_WRAPPER(pcl::PointXYZRGBI, pcl::_PointXYZRGBI)
#endif /* end of include guard */

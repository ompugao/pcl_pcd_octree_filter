
#include "my_point_types.h"
namespace pcl
{
  std::ostream& 
  operator << (std::ostream& os, const PointXYZRGBI& p)
  {
    os << "(" << p.x << "," << p.y << "," << p.z << " - " << p.r << "," << p.g << "," << p.b << " - " << p.intensity << ")";
    return (os);
  }
}

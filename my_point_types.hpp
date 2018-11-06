#ifndef _MY_POINT_TYPES_HPP_
#define _MY_POINT_TYPES_HPP_

#include <Eigen/Core>
#include <ostream>

namespace pcl
{
  struct EIGEN_ALIGN16 _PointXYZRGBI
  {
    PCL_ADD_POINT4D; // This adds the members x,y,z which can also be accessed using the point (which is float[4])
    PCL_ADD_RGB;
    PCL_ADD_INTENSITY;
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  };
  PCL_EXPORTS std::ostream& operator << (std::ostream& os, const PointXYZRGBI& p);
  struct EIGEN_ALIGN16 PointXYZRGBI : public _PointXYZRGBI
  {
    inline PointXYZRGBI (const _PointXYZRGBI &p)
    {
      x = p.x; y = p.y; z = p.z; data[3] = 1.0f;
      rgba = p.rgba;
      intensity = p.intensity;
    }

    inline PointXYZRGBI ()
    {
      x = y = z = 0.0f;
      data[3] = 1.0f;
      r = g = b = 0;
      a = 0;
      intensity = 0.0f;
    }

    inline PointXYZRGBI (uint8_t _r, uint8_t _g, uint8_t _b, float _intensity)
    {
      x = y = z = 0.0f;
      data[3] = 1.0f;
      r = _r;
      g = _g;
      b = _b;
      a = 0;
      intensity = _intensity;
    }
    //PCL_EXPORTS std::ostream& operator << (std::ostream& os, const PointXYZRGBI& p);
  
    friend std::ostream& operator << (std::ostream& os, const PointXYZRGBI& p);
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  };

}
#endif /* end of include guard */

#include <iostream>
#include <vector>
#include <string>
//#define PCL_NO_PRECOMPILE
#include <pcl/console/parse.h>
//#include <octree/OcTree.h>
#include <pcl/octree/octree.h>
//#include <pcl/octree/impl/octree_search.hpp>
#include <pcl/octree/octree_impl.h>
#include <pcl/io/pcd_io.h>
#include "my_point_types.h"

int main(int argc, char * argv[])
{
  std::string outputfile;
  std::vector<int> file_indices   = pcl::console::parse_file_extension_argument (argc, argv, ".pcd");
  pcl::console::parse_argument(argc, argv, "-output", outputfile);

  pcl::PCLPointCloud2::Ptr cloud_filtered (new pcl::PCLPointCloud2 ());

  //pcl::VoxelGrid<pcl::PCLPointCloud2> voxelfilter;
  typedef pcl::PointXYZRGBI PointT;
  pcl::octree::OctreePointCloudVoxelCentroid<PointT> opcvc(0.05);
  // Fill in the cloud data
  pcl::PCDReader reader;
  for (auto&& iarg : file_indices) {
    std::string filename(argv[iarg]);
    if (filename == outputfile) {
      continue;
    }
    pcl::PointCloud<PointT>::Ptr cloud (new pcl::PointCloud<PointT> ());
    reader.read (filename, *cloud);
    std::cerr << "PointCloud before filtering: " << cloud->width * cloud->height << " data points (" << pcl::getFieldsList (*cloud) << ")." << std::endl;

    opcvc.setInputCloud (cloud);
    //opcvc.defineBoundingBox();
    opcvc.addPointsFromInputCloud();
  }
  pcl::PointCloud<PointT>::VectorType voxelCentroids;
  opcvc.getVoxelCentroids(voxelCentroids);
  pcl::PointCloud<PointT>::Ptr newcloud(new pcl::PointCloud<PointT>);
  for (auto&& p : voxelCentroids) {
    newcloud->push_back(p);
  }
  pcl::io::savePCDFileBinaryCompressed(outputfile, *newcloud);

  // pcl::octree::OctreePointCloud<pcl::PointXYZ>::OctreeLeafNodeIterator it(occloud);
  // while ( *++it ) {
  //   pcl::octree::OctreePointCloud<pcl::PointXYZ>::LeafNode *node = *it;
  // } 

    
  return 0;
}

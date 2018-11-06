project(octree2pcd)

set(OCTREE2PCD_VERSION_MAJOR 0)
set(OCTREE2PCD_VERSION_MINOR 0)
set(OCTREE2PCD_VERSION_TEENY 1)
set(PACKAGE_VERSION "${OCTREE2PCD_VERSION_MAJOR}.${OCTREE2PCD_VERSION_MINOR}.${OCTREE2PCD_VERSION_TEENY}")

cmake_minimum_required(VERSION 2.8)

add_compile_options(-std=c++11)

find_package(octomap REQUIRED)
find_package(PCL REQUIRED COMPONENTS io common octree)

include_directories(${PCL_INCLUDE_DIRS} ${OCTOMAP_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS} ${OCTOMAP_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(octree2pcd octree2pcd.cpp my_point_types.cpp)
#target_link_libraries(octree2pcd ${PCL_LIBRARIES} ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES} ${PCL_OCTREE_LIBRARY} ${OCTOMAP_LIBRARIES})
target_link_libraries(octree2pcd ${PCL_LIBRARIES} ${OCTOMAP_LIBRARIES})


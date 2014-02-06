cmake_minimum_required(VERSION 2.8.3)
project(eigen_utils)

find_package(catkin REQUIRED COMPONENTS)
find_package(Eigen REQUIRED)

catkin_package(
  DEPENDS eigen
  CATKIN_DEPENDS 
  INCLUDE_DIRS include 
  LIBRARIES eigen_utils
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${EIGEN_INCLUDE_DIRS}
)

add_library(eigen_utils src/eigen_utils.cpp)
target_link_libraries(eigen_utils ${catkin_LIBRARIES})

install(TARGETS eigen_utils
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
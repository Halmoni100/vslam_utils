#pragma once

#include "vslamTypes.h"
#include "CameraIntrinsics.h"

struct CommonFixture {
  std::vector<Vector3f> getCubePoints1();

  /** Calculate a camera pose that points at the origin.  The translation of the pose is parametrized by the spherical coordinate system.
   * @param radius The distance from the origin
   * @param azimuth Angle measured from X axis on X-Y plane
   * @param polar Angle measured from Z axis on Z-(azimuth dir) plane 
   * @return The desired camera pose
   */
  AffineTransform getCameraPoseViewCenter(float radius, float altitude, float azimuth);

  CameraIntrinsics getStandardIntrinsics();
};

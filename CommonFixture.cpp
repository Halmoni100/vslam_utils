#include <iostream>

#include "CommonFixture.h"

std::vector<Vector3f> CommonFixture::getCubePoints1()
{
	std::vector<Vector3f> cubePoints;
	std::vector<int> coordVals = {-1,1};
	for (int i: coordVals) { for (int j: coordVals) { for (int k: coordVals) {
		Vector3f point;
		point << i, j, k;
		cubePoints.push_back(point);
	} } }
	return cubePoints;
}

AffineTransform CommonFixture::getCameraPoseViewCenter(float radius, float altitude, float azimuth)
{
  Vector3f rotAxis = AngleAxisf(azimuth, Vector3f::UnitZ()) * Vector3f::UnitY();
  Vector3f direction = AngleAxisf(altitude, rotAxis) * Vector3f::UnitZ();
  Vector3f translation = radius * direction;
  Vector3f rot_z = -direction;
  Vector3f rot_x = rot_z.cross(Vector3f::UnitZ());
  Vector3f rot_y = rot_z.cross(rot_x);
  Matrix3f rotation;
  rotation.block<3,1>(0,0) = rot_x;
  rotation.block<3,1>(0,1) = rot_y;
  rotation.block<3,1>(0,2) = rot_z;
  return Translation3f(translation) * rotation;  
}

CameraIntrinsics CommonFixture::getStandardIntrinsics()
{
  CameraIntrinsics intrinsics = {1.0,1.0};
  return intrinsics;
}

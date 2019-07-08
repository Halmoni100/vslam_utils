#pragma once

#include "vslamTypes.h"

namespace vslam {

  std::vector<Vector3f> transformPoints(AffineTransform transform, std::vector<Vector3f> points);
  std::vector<Vector2f> getImagePoints(std::vector<Vector3f> cameraPoints, float aspectRatio, float f_x);
  float getRotationAngle(const Matrix3f& rot);
  float getAngleDifference(const Matrix3f& rot1, const Matrix3f& rot2); 
  bool posesClose(AffineTransform pose1, AffineTransform pose2, float rotAngleTolerance, float translationTolerance);
  // Get projection of b on a
  Vector3f getProjection(Vector3f a, Vector3f b);
  // Get angle from a to b
  float getAngle(Vector3f a, Vector3f b);
  std::string to_string(AffineTransform transform);
  bool equal(float a, float b, float tolerance);

}

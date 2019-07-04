#pragma once

#include "vslamTypes.h"

class PointVisualizer {
public:  
  PointVisualizer();
  void visualizePoints(const std::vector<Vector3f>& points, const AffineTransform& cameraPose);

private:
  Vector3f getFocalPoint(const AffineTransform& cameraPose, const CameraIntrinsics& intrinsics);
}

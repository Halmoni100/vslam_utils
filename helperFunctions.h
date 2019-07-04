#pragma once

#include "vslamTypes.h"

namespace vslam {

  std::vector<Vector3f> transformPoints(AffineTransform transform, std::vector<Vector3f> points);
  std::vector<Vector2f> getImagePoints(std::vector<Vector3f> cameraPoints, float aspectRatio, float f_x);

}

#pragma once

#include "vslamTypes.h"

struct CommonFixture {
  std::vector<Vector3f> getCubePoints1();
  AffineTransform getCameraPose1();
};

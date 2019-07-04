#include "helperFunctions.h"

namespace vslam {

  std::vector<Vector3f> transformPoints(AffineTransform transform, std::vector<Vector3f> points)
  {
  	std::vector<Vector3f> transformedPoints;
  	std::transform(points.begin(), points.end(), std::back_inserter(transformedPoints),
  			           [transform](Vector3f point) -> Vector3f { return transform * point; });
  	return transformedPoints;
  }

  std::vector<Vector2f> getImagePoints(std::vector<Vector3f> cameraPoints, float aspectRatio, float f_x)
  {
    std::vector<Vector2f> imagePoints;
    for (const Vector3f& cameraPoint: cameraPoints) {
      float x_image = f_x * cameraPoint(0) / cameraPoint(2);
      float f_y = f_x / aspectRatio;
      float y_image = f_y * cameraPoint(1) / cameraPoint(2);
      Vector2f newImagePoint(x_image, y_image);
      imagePoints.push_back(newImagePoint);
    }
    return imagePoints; 
  }

} // namespace vslam

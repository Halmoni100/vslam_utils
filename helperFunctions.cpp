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

  float getRotationAngle(const Matrix3f& rot)
  {
    return acos((rot.trace() - 1) / 2.0);
  }

  float getAngleDifference(const Matrix3f& rot1, const Matrix3f& rot2)
  {
    return getRotationAngle(rot2.transpose() * rot1);
  }

  bool posesClose(AffineTransform pose1, AffineTransform pose2, float rotAngleTolerance, float translationTolerance)
  {
    float rotAngleDifference = vslam::getAngleDifference(pose1.rotation(), pose2.rotation());
    if (rotAngleDifference > rotAngleTolerance)
      return false;
    float translationDistance = (pose2.translation() - pose1.translation()).norm();
    if (translationDistance > translationTolerance)
      return false;
    return true;
  }

  Vector3f getProjection(Vector3f a, Vector3f b)
  {
    return (a.dot(b) / pow(a.norm(),2)) * a;
  }

  float getAngle(Vector3f a, Vector3f b)
  {
    return acos( a.dot(b) / (a.norm() * b.norm()) );
  }

  std::string to_string(AffineTransform transform)
  {
    std::stringstream ss;
    Vector3f translation = transform.translation();
    AngleAxisf rotation(transform.rotation());
    ss << "Rotation:\n";
    ss << "\taxis: [" << rotation.axis()(0) << "," << rotation.axis()(1) << "," << rotation.axis()(2) << "]\n";
    ss << "\tangle: " << rotation.angle() << "\n";
    ss << "Translation: [" <<  translation(0) << "," << translation(1) << "," << translation(2) << "]\n";
    return ss.str();
  }

  bool equal(float a, float b, float tolerance)
  {
    return abs(a - b) < tolerance;
  }

} // namespace vslam

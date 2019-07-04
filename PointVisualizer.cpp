#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <opencv2/viz.hpp>
#include <opencv2/core/eigen.hpp>

#include "CameraIntrinsics.h"

#include "PointVisualizer.h"

PointVisualizer::PointVisualizer()
{
}

void PointVisualizer::visualizePoints(const std::vector<Vector3f>& points, const AffineTransform& cameraPose, const CameraIntrinsics& intrinsics)
{
  cv::Vec3f cam_trans;
  Vector3f translation = cameraPose.translation();
  cv::eigen2cv(translation, cam_trans);

  cv::Vec3f cam_focal_point;
  cv::eigen2cv(getFocalPoint(cameraPose, intrinsics), cam_focal_point);	

  cv::Vec3f cam_y_dir;
  Vector3f yCompRotation = cameraPose.rotation().block<3,1>(0,1);
  cv::eigen2cv(yCompRotation, cam_y_dir);

  cv::Affine3f cam_pose = cv::viz::makeCameraPose(cam_trans, cam_focal_point, cam_y_dir);

  cv::viz::Viz3d window("Point Visualizer");

  int i = 0;
  std::vector<cv::viz::WSphere*> sphereWidgets;
  for (const Vector3f& point: points)
  {
    cv::Vec3f cvVec;
    cv::eigen2cv(point, cvVec);
    cv::Point3f cvPoint = cvVec; 
    cv::Point3d cvPointDouble = cvPoint;
    cv::viz::WSphere* spherePoint = new cv::viz::WSphere(cvPointDouble, 0.05);
    std::string widgetName = "Sphere " + std::to_string(i);
    window.showWidget(widgetName, *spherePoint);
    sphereWidgets.push_back(spherePoint);
    i++;
  } 

  window.showWidget("Coordinate Widget", cv::viz::WCoordinateSystem());

  window.setViewerPose(cam_pose);
  
  window.spin();

  for (cv::viz::WSphere* widget: sphereWidgets)
    delete widget;
}

Vector3f PointVisualizer::getFocalPoint(const AffineTransform& cameraPose, const CameraIntrinsics& intrinsics)
{
  Matrix3f rotation = cameraPose.rotation();
  Vector3f zComponentRotation = rotation.block<3,1>(0,2);
  return cameraPose.translation() + intrinsics.f_x * zComponentRotation;
}

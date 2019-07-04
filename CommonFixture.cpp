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

CommonFixture::AffineTransform CommonFixture::getCameraPose1()
{
  Vector3f cameraTranslation(5.0,6.0,7.0);
	Matrix3f cameraRotation;
  cameraRotation = AngleAxisf(0.25*M_PI, Vector3f::UnitZ()) 
                 * AngleAxisf(-0.75*M_PI, Vector3f::UnitY())
		             * AngleAxisf(0.5*M_PI, Vector3f::UnitZ());
	AffineTransform cameraPose1 = Translation3f(cameraTranslation) * cameraRotation; 
	return cameraPose1;	
}

add_library(commonFixture SHARED CommonFixture.cpp)
target_include_directories(commonFixture PRIVATE
  .
  ${EIGEN3_INCLUDE_DIR}
)

add_library(pointVisualizer SHARED PointVisualizer.cpp)
target_include_directories(pointVisualizer PRIVATE
  .
  ${EIGEN3_INCLUDE_DIR}
  ${OpenCV_INCLUDE_DIRS}
)
target_link_libraries(pointVisualizer
  ${OpenCV_LIBS}
)

add_library(helperFunctions SHARED helperFunctions.cpp)
target_include_directories(helperFunctions PRIVATE
  .
  ${EIGEN3_INCLUDE_DIR}
)

#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "position_model.h"
#include <pcl/io/pcd_io.h>
#include <pcl/kdtree/kdtree_flann.h>

class Registration
{
  public:

    Registration();
    ~Registration();

    void
    readData (std::string source_points_path, std::string target_points_path);

    void
    getDataFromModel(std::string database_path, Eigen::MatrixX3d rotation, Eigen::Vector3d translation);

    void
    calculateRigidTransformation(int number_of_iterations);

    void
    applyRigidTransformation();

    void
    writeDataToPCD(std::string file_path);


  private:

    Eigen::Matrix3d rotation_;
    Eigen::Vector3d translation_;
    Eigen::Matrix4d homogeneus_matrix_;

    std::vector < Eigen::Vector3d > source_points_;
    std::vector < Eigen::Vector3d > target_points_;
    std::vector < Eigen::Vector4d > rigid_transformed_points_;

    pcl::PointCloud<pcl::PointXYZ>::Ptr target_point_cloud_ptr_;
    pcl::KdTreeFLANN<pcl::PointXYZ> kdtree_;

    PositionModel* model_;

};

#endif // REGISTRATION_H

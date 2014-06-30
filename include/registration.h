#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "position_model.h"
#include <pcl/common/transforms.h>
#include <pcl/io/pcd_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/features/normal_3d.h>
#include <pcl/visualization/pcl_visualizer.h>

class Registration
{
  public:

    Registration();
    ~Registration();

    void
    readDataFromOBJFiles (std::string source_points_path, std::string target_points_path);

    void
    readOBJFile (std::string file_path, std::vector < Eigen::Vector3d >& points_vector, Eigen::Matrix3d transform_matrix, Eigen::Vector3d translation);

    void
    readDataFromOBJFileAndPCDScan(std::string source_points_path, std::string target_points_path, Eigen::Matrix3d transform_matrix, Eigen::Vector3d translation);

    void
    getDataFromModel (std::string database_path, std::string output_path, Eigen::MatrixX3d rotation, Eigen::Vector3d translation);

    void
    calculateRigidTransformation (int number_of_iterations);

    void
    applyRigidTransformation ();

    void
    writeDataToPCD (std::string file_path);

    void
    setKdTree (pcl::PointCloud<pcl::PointXYZ>::Ptr target_point_cloud_ptr);

    void
    visualizeCorrespondences ();


  private:

    std::vector < pcl::Correspondences > iteration_correspondences_vector_;



    Eigen::Matrix4d homogeneus_matrix_;

    std::vector < Eigen::Matrix4d > homogeneus_matrices_vector_;

    std::vector < Eigen::Vector3d > source_points_;
    std::vector < Eigen::Vector3d > transformed_points_;

    std::vector < Eigen::Vector4d > rigid_transformed_points_;

    pcl::search::KdTree<pcl::PointNormal> kdtree_;




    pcl::PointCloud<pcl::PointXYZRGB>::Ptr vis_source_point_cloud_ptr_;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr vis_scan_point_cloud_ptr_;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr vis_model_point_cloud_ptr_;


    pcl::PointCloud<pcl::PointNormal>::Ptr target_point_normal_cloud_ptr_;



    PositionModel* position_model_;

};

#endif // REGISTRATION_H

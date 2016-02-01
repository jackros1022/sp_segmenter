#ifndef COLLISION_ENV_H
#define COLLISION_ENV_H

#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometric_shapes/mesh_operations.h>
#include <geometric_shapes/shape_operations.h>
#include <shape_msgs/Mesh.h>
#include <moveit_msgs/CollisionObject.h>

struct objectTF {
    std::string name, frame_id;
    geometry_msgs::Pose pose;
};

class collision_environment
{
	protected:
		ros::NodeHandle nh;
		ros::Publisher add_collision_object_publisher;
		tf::TransformListener listener;
	;

	private:
		bool debug;
		std::vector<std::string> listOfTF;
		std::vector<objectTF> detectedObjectsTF;
		std::string mesh_source;
        std::string charToFind,breakChar;
        int loopInterval;
        std::string parentFrame; //parent of the TF frame that objects attached to
		int objectNameFormatIndex;
		// after breaking the list of TF to several items, which item define the object name
		// Example: with format Obj::NameOfObject::index, objectNameFormatIndex = 2. 
		// If format Obj::index::NameOfObject = 3, objectNameFormatIndex = 3.
	;

	public:
		collision_environment(const ros::NodeHandle &nh);
		void getAllObjectTF();
		void addAllCollisionObject(const bool &updateFrame = true);
};

std::vector<std::string> stringVectorSeparator (const std::string &input,
                                                const std::string &charToFind, const std::string &breakChar, const int &loopInterval, const bool &debug);

#endif
/*
 * triloader.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: hastings
 */
#include "triloader.h"
#include <fstream>
#include <vector>
void loadtriangles(Room* room, std::string filename, Vector3 displacement, Matrix3 rotation, PhongProfile prof){

    std::vector<Triangle*>* tris = new std::vector<Triangle*>();

	std::ifstream tri_file;
	tri_file.open(filename.c_str());
	if(!tri_file.is_open()){
		throw "incorrect triangle file";
	}
    int n;
    tri_file >> n;
    for(int j = 0; j < n; j++){
    	//Color c = Color::randColor();
    	//prof.diffuse = c;
    	//prof.ambient = c.mul(1 / 9);
    	double x, y, z;

    	tri_file >> x;
    	tri_file >> y;
    	tri_file >> z;
    	Vector3 v1 {x, y, z};

    	tri_file >> x;
    	tri_file >> y;
    	tri_file >> z;
    	Vector3 v2 {x, y, z};

    	tri_file >> x;
    	tri_file >> y;
    	tri_file >> z;
    	Vector3 v3 {x, y, z};
        v1 = rotation.trans(v1).add(displacement);
        v2 = rotation.trans(v2).add(displacement);
        v3 = rotation.trans(v3).add(displacement);
    	tris->push_back(new Triangle(v1, v2, v3, prof));
    }
    room->addPrimitive(new VolumeHigharchy(tris, prof));

}


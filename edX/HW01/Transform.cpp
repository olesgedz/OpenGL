// Transform.cpp: implementation of the Transform class.

#include <iostream>
#include "Transform.h"
#include "glm/ext.hpp"
#include <stdio.h>
//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
	// YOUR CODE FOR HW1 HERE
	   mat3 alongMat = mat3(
	  axis.x*axis.x, axis.x*axis.y, axis.x*axis.z,
	  axis.x*axis.y, axis.y*axis.y, axis.y*axis.z,
	  axis.x*axis.z, axis.y*axis.z, axis.z*axis.z
  );
  mat3 axisMat = mat3(
	  0, axis.z, -axis.y,
	  -axis.z, 0 , axis.x,
	  axis.y, -axis.x, 0
  );
  return cos(glm::radians(degrees))*mat3(1.0) + (1-cos(glm::radians(degrees)))*alongMat + sin(glm::radians(degrees))*axisMat;
  //  mat3 rot = mat3(cosf(radians)*mat3(1.0) + (1 - cosf(radians))*second_mat + sinf(radians)*third_mat);
	// mat3 rotation;
	// rotation =  mat3(1, 0, 0, 0, cos(radians), -sin(radians), 0, sin(radians), cos(radians)) * axis.x * mat3(cos(radians), 0, sin(radians), 0, 1, 0, -sin(radians), 0,\
	//  cos(radians)) * axis.y * mat3(cos(radians), -sin(radians), 0, sin(radians), cos(radians), 0, 0, 0, 1) * axis.z;
	// // You will change this return call
	// return rotation;
	// vec3 a = glm::normalize(axis);
	// vec3 b = vec3(0,0,1);
	// vec3 c = glm::cross(a,b);
	// b = glm::cross(c,a);

	// mat3 matr = mat3(a.x, b.x, c.x, a.y, b.y, c.y, a.z, b.z, c.z);
	// float sine = sin(glm::radians(degrees)), cosine = cos(glm::radians(degrees));
	// float x = a.x, y = a.y, z = a.z;
	// mat3 rotateM = mat3(cos(radians), -sin(radians), 0, sin(radians), cos(radians), 0, 0, 0, 1);
	// mat3 aat = mat3(x*x, y*x, z*x,
	// 							  x*y, y*y, z*y,
	// 							  x*z, y*z, z*z);

	// mat3 aStar = mat3( 0, -z,  y,
	// 								   z,  0, -x,
	// 									-y,  x,  0);


	//mat3 rotateM = mat3(1, 0, 0, 0, cos(radians), -sin(radians), 0, sin(radians), cos(radians)) * mat3(1, 0, 0,
																										// 0, -1, 0,
																										// 0, 0, 1);
																										//https://m.habr.com/ru/post/234203/
	// mat3 rotateM = glm::mat3(cosine) + (1-cosine) * aat + sine * aStar;
	// std::cout << glm::to_string(glm::mat3(cosine)) << std::endl;

}


// // Transforms the camera left around the "crystal ball" interface
// void Transform::left(float degrees, vec3& eye, vec3& up) {
// 	// YOUR CODE FOR HW1 HERE
// 	degrees = glm::radians(degrees);
// 	eye  = rotate(degrees, up) * eye;
// 	printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
// }

// // Transforms the camera up around the "crystal ball" interface
// void Transform::up(float degrees, vec3& eye, vec3& up) {
// 	// YOUR CODE FOR HW1 HERE 
// 	degrees = glm::radians(degrees);
// 	eye = rotate(degrees, up) * eye;
// 	printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));


// }



// // Your implementation of the glm::lookAt matrix
// mat4 Transform::lookAt(vec3 eye, vec3 up) {
// 	// YOUR CODE FOR HW1 HERE

// 	// You will change this return call
// 	return mat4();
// }

// mat3 Transform::rotate(const float degrees, const vec3& axis) {
//   // YOUR CODE FOR HW1 HERE

//   // You will change this return call
    
    
//    	double radians = glm::radians(degrees);
//     vec3 normAxis = glm::normalize(axis);
    
//     float oneMinusCos = 1 - cos(radians);
//     float mat11 = cos(radians)+(normAxis.x*normAxis.x)*oneMinusCos;
//     float mat12 = (normAxis.x*normAxis.y)*oneMinusCos-normAxis.z*sin(radians);
//     float mat13 = normAxis.x*normAxis.z*oneMinusCos+(normAxis.y*sin(radians));
//     float mat21 = normAxis.y*normAxis.x*oneMinusCos+normAxis.z*sin(radians);
//     float mat22 = cos(radians) + normAxis.y*normAxis.y*oneMinusCos;
//     float mat23 = normAxis.y*normAxis.z*oneMinusCos - normAxis.x*sin(radians);
//     float mat31 = normAxis.z*normAxis.x*oneMinusCos - normAxis.y*sin(radians);
//     float mat32 = normAxis.z*normAxis.y*oneMinusCos + normAxis.x*sin(radians);
//     float mat33 = cos(radians) + normAxis.z*normAxis.z*oneMinusCos;
//     return glm::transpose(mat3(vec3(mat11,mat12,mat13),
//                 vec3(mat21,mat22,mat23),
//                 vec3(mat31,mat32,mat33)
//               ));
// }

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
    
    //float radians = degrees*pi/180;
    
    //test rotate around y
//    mat3 rotMatxY = glm::transpose(mat3(vec3(cos(radians),0,sin(radians)),
//                         vec3(0,1,0),
//                         vec3(-sin(radians),0,cos(radians))));
    
   
    mat3 rotationMx= rotate(degrees, up);
    eye =rotationMx*eye;
    up = rotationMx*up;
    printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
    
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
    
    //float radians = degrees*pi/180;
//    mat3 rotMatxX = glm::transpose(mat3(vec3(1,0,0),
//                         vec3(0,cos(radians),-sin(radians)),
//                         vec3(0,sin(radians),cos(radians))));
    // vec3 w = glm::cross(up, eye);
    // mat3 rotationMx= rotate(-degrees, w);
    
    // eye =rotationMx*eye;
    //  up = rotationMx*up;

			vec3 pivot = glm::normalize(glm::cross(-up, eye));
			mat3 rotationMx = rotate(degrees, pivot);
	eye = eye * rotationMx;
	up = up * rotationMx;
    printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE

    
    vec3 w = glm::normalize(eye);
    vec3 u = glm::normalize(glm::cross(up,eye));
    vec3 v = glm::normalize(glm::cross(w,u));
  // You will change this return call
    return glm::transpose(mat4(vec4(u.x,u.y,u.z,glm::dot(u, -eye)),
                     vec4(v.x,v.y,v.z,glm::dot(v, -eye)),
                     vec4(w.x,w.y,w.z,glm::dot(w, -eye)),
                     vec4(0,0,0,1)
                     ));
}

Transform::Transform()
{

}

Transform::~Transform()
{

}

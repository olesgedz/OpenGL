// // Transform.cpp: implementation of the Transform class.

// // Note: when you construct a matrix using mat4() or mat3(), it will be COLUMN-MAJOR
// // Keep this in mind in readfile.cpp and display.cpp
// // See FAQ for more details or if you're having problems.
// #include "Transform.h"
#define GLM_ENABLE_EXPERIMENTAL 1
#include <glm/gtx/string_cast.hpp>
#include <iostream>
using namespace std;
// // Helper rotation function.  Please implement this.  
// mat3 Transform::rotate(const float degrees, const vec3& axis) 
// {
//   mat3 ret;
//   // YOUR CODE FOR HW2 HERE
//   // Please implement this.  Likely the same as in HW 1.  
//   return ret;
// }

// void Transform::left(float degrees, vec3& eye, vec3& up) 
// {
//   // YOUR CODE FOR HW2 HERE
//   // Likely the same as in HW 1.  
// }

// void Transform::up(float degrees, vec3& eye, vec3& up) 
// {
//   // YOUR CODE FOR HW2 HERE 
//   // Likely the same as in HW 1.  
// }

// mat4 Transform::lookAt(const vec3 &eye, const vec3 &center, const vec3 &up) 
// {
//   mat4 ret;
//   // YOUR CODE FOR HW2 HERE
//   // Likely the same as in HW 1.  
//   return ret;
// }

// mat4 Transform::perspective(float fovy, float aspect, float zNear, float zFar)
// {
//   mat4 ret;
//   // YOUR CODE FOR HW2 HERE
//   // New, to implement the perspective transform as well.  
//   return ret;
// }

// mat4 Transform::scale(const float &sx, const float &sy, const float &sz) 
// {
//   mat4 ret;
//   // YOUR CODE FOR HW2 HERE
//   // Implement scaling 
//   return ret;
// }

// mat4 Transform::translate(const float &tx, const float &ty, const float &tz) 
// {
//   mat4 ret;
//   // YOUR CODE FOR HW2 HERE
//   // Implement translation 
//   return ret;
// }

// // To normalize the up direction and construct a coordinate frame.  
// // As discussed in the lecture.  May be relevant to create a properly 
// // orthogonal and normalized up. 
// // This function is provided as a helper, in case you want to use it. 
// // Using this function (in readfile.cpp or display.cpp) is optional.  

// vec3 Transform::upvector(const vec3 &up, const vec3 & zvec) 
// {
//   vec3 x = glm::cross(up,zvec); 
//   vec3 y = glm::cross(zvec,x); 
//   vec3 ret = glm::normalize(y); 
//   return ret; 
// }


// Transform::Transform()
// {

// }

// Transform::~Transform()
// {

// }

#include "Transform.h"
#include <stdio.h>

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
   // printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
    
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
mat4 Transform::lookAt(const vec3& eye, const vec3 &center, const vec3& up) {
  // YOUR CODE FOR HW1 HERE

    vec3 eye1  = eye;
    vec3 center1 = center;
    vec3 up1 = up;

    vec3 w = glm::normalize(eye);
    vec3 u = glm::normalize(glm::cross(up,eye));
    vec3 v = glm::normalize(glm::cross(w,u));
   std::cout<< glm::to_string(glm::transpose(mat4(vec4(u.x,u.y,u.z,glm::dot(u, -eye)),
                     vec4(v.x,v.y,v.z,glm::dot(v, -eye)),
                     vec4(w.x,w.y,w.z,glm::dot(w, -eye)),
                     vec4(0,0,0,1)
                     ))) << std::endl;
     std::cout<< glm::to_string(glm::lookAt(eye1, center1, up1)) << std::endl;                
  // You will change this return call
    return glm::transpose(mat4(vec4(u.x,u.y,u.z,glm::dot(u, -eye)),
                     vec4(v.x,v.y,v.z,glm::dot(v, -eye)),
                     vec4(w.x,w.y,w.z,glm::dot(w, -eye)),
                     vec4(0,0,0,1)
                     ));
}

/*
	My Notes about perpective, it takes me some time to understand what's going on there.
	the perspective matrix project the frustum formed by near plane, far plane, field of view (fovy, length of y), 
	aspect (length of x) to an 1*1*2 cuboid. the projection plane is defined by fovy, because y size of projection plane is 1,
	we can determine d, which is distance to origin, by fovy.
	(Actually, fovy not only decide the y size of frustum, also decide the projection plane, and aspect is another variable to 
	determine x size of frustum, it use relative ratio between x size and y size, and the result is x' = x / aspect)
*/
mat4 Transform::perspective(float fovy, float aspect, float zNear, float zFar)
{
	float theta = fovy / 2.0 / 180.0 * pi;
	float d = 1.0 / glm::tan(theta);
	float A = -(zFar + zNear) / (zFar - zNear);
	float B = -2 * zFar * zNear / (zFar - zNear);
	mat4 perspective(d / aspect, 0.0, 0.0, 0.0,
					 0.0, d, 0.0, 0.0,
					 0.0, 0.0, A, B,
					 0.0, 0.0, -1.0, 0.0);
	return perspective;
}

mat4 Transform::scale(const float &sx, const float &sy, const float &sz) {
  // YOUR CODE FOR HW2 HERE
	return mat4(sx, 0.0, 0.0, 0.0,
			    0.0, sy, 0.0, 0.0,
				0.0, 0.0, sz, 0.0,
				0.0, 0.0, 0.0, 1.0);
}

mat4 Transform::translate(const float &tx, const float &ty, const float &tz) {
  // YOUR CODE FOR HW2 HERE
	return mat4(1.0, 0.0, 0.0, tx,
				0.0, 1.0, 0.0, ty,
				0.0, 0.0, 1.0, tz,
				0.0, 0.0, 0.0, 1.0);
}

// To normalize the up direction and construct a coordinate frame.  
// As discussed in the lecture.  May be relevant to create a properly 
// orthogonal and normalized up. 
// This function is provided as a helper, in case you want to use it. 
// Using this function (in readfile.cpp or display.cpp) is optional.  

vec3 Transform::upvector(const vec3 &up, const vec3 & zvec) {
  vec3 x = glm::cross(up,zvec) ; 
  vec3 y = glm::cross(zvec,x) ; 
  vec3 ret = glm::normalize(y) ; 
  return ret ; 
}


Transform::Transform()
{

}

Transform::~Transform()
{

}
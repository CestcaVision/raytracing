//
// Created by Song Yawei on 2022/11/24.
//

#ifndef RAYTRACING_RAY_H
#define RAYTRACING_RAY_H

#include "vec3.h"

class ray {
public:
    ray(){}
    ray(const vec3& a, const vec3& b){A=a;B=b;}
    inline vec3 origin()const{return A;}
    inline vec3 direction()const{return B;}
    inline vec3 point_at_parameter(float t) const{return A+t*B;}
public:
    vec3 A;
    vec3 B;
};


#endif //RAYTRACING_RAY_H

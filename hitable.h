//
// Created by Song Yawei on 2022/11/25.
//

#ifndef RAYTRACING_HITABLE_H
#define RAYTRACING_HITABLE_H
#include "ray.h"

class material;

struct hit_record{
    float t;
    vec3 p;
    vec3 normal;
    material *mat_ptr;
};

class hitable {
public:
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec)const=0;
};


#endif //RAYTRACING_HITABLE_H

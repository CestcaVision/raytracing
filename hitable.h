//
// Created by Song Yawei on 2022/11/25.
//

#ifndef RAYTRACING_HITABLE_H
#define RAYTRACING_HITABLE_H
#include "ray.h"

struct hit_record{
    float t;
    vec3 p;
    vec3 normal;
};

class hitable {
public:
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec)const=0;
};


#endif //RAYTRACING_HITABLE_H

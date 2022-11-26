//
// Created by Song Yawei on 2022/11/26.
//

#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H
#include "ray.h"
#include "hitable.h"

class material {
public:
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered)const = 0;
};


#endif //RAYTRACING_MATERIAL_H

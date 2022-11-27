//
// Created by Song Yawei on 2022/11/26.
//

#ifndef RAYTRACING_METAL_H
#define RAYTRACING_METAL_H
#include "material.h"

class metal:public material {
public:
    metal(const vec3& a, float f):albedo(a){
        if (f<1){
            fuzz =f;
        }else
            fuzz=1;
    }
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered)const{
        vec3 reflected = reflect(r_in.direction().make_unit_vec(),rec.normal);
        scattered = ray(rec.p,reflected+fuzz*random_in_unit_sphere());
        attenuation = albedo;
        return (dot(scattered.direction(),rec.normal)>0);
    }
public:
    vec3 albedo;
    float fuzz;
};


#endif //RAYTRACING_METAL_H

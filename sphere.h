//
// Created by Song Yawei on 2022/11/25.
//

#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H
#include "hitable.h"

class sphere: public hitable{
public:
    sphere(){}
    sphere(vec3 c, float r,material *mat):center(c),radius(r), mat_ptr(mat) {}
    virtual bool hit(const ray &r, float t_min, float t_max, hit_record& rec) const;
public:
    vec3 center;
    float radius;
    material *mat_ptr;
};

bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec)const{
    vec3 oc = r.origin()-center;
    float a = dot(r.direction(),r.direction());
    float b = 2.0*dot(oc,r.direction());
    float c = dot(oc,oc)-radius*radius;
    float discriminant = b*b -4*a*c;
    if (discriminant>0){
        float temp = (-b- sqrt(discriminant))/(2*a);
        if(temp>t_min && temp<t_max){
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p-center)/radius;
            rec.mat_ptr = mat_ptr;
            return true;
        }
        temp = (-b + sqrt(discriminant))/(2*a);
        if(temp>t_min&&temp<t_max){
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p-center)/radius;
            rec.mat_ptr = mat_ptr;
            return true;
        }
    }
    return false;
}

#endif //RAYTRACING_SPHERE_H

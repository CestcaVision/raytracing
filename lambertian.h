//
// Created by Song Yawei on 2022/11/26.
//

#ifndef RAYTRACING_LAMBERTIAN_H
#define RAYTRACING_LAMBERTIAN_H
# include "material.h"

#define random(a,b) (rand()%(b-a+1)+a)
#define random1 (float((rand()%(100)))/100.0f)


// 单位cube随机取点,返回一个在球内的点
vec3 random_in_unit_sphere()
{
    vec3 p;
    do{
        p = 2.0*vec3(random1,random1,random1) - vec3(1,1,1);
    }while (dot(p,p) >= 1.0);
    return p;
}

class lambertian:public material {
public:
    lambertian(const vec3& a):albedo(a){}
    //method
    virtual bool scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &scattered) const {
        vec3 target = rec.p + rec.normal +random_in_unit_sphere();
        scattered = ray(rec.p,target-rec.p);
        attenuation = albedo;
        return true;
    }
public:
    vec3 albedo;
};


#endif //RAYTRACING_LAMBERTIAN_H

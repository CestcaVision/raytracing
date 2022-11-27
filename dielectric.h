//
// Created by Tricrepe on 2022/11/27.
//

#ifndef RAYTRACING_DIELECTRIC_H
#define RAYTRACING_DIELECTRIC_H
#include "ray.h"
#include "material.h"
#include "hitable.h"

float schlick(float cosine, float ref_idx) {
    float r0 = (1-ref_idx) / (1+ref_idx);
    r0 = r0*r0;
    return r0 + (1-r0)*pow((1 - cosine),5);
}


bool refract(vec3 &v,vec3 &n, float ni_over_nt, vec3 &refracted) {
    vec3 uv =  v.make_unit_vec();
    float dt = dot(uv, n);
    float discriminant = 1.0 - ni_over_nt*ni_over_nt*(1-dt*dt);
    if (discriminant > 0) {
        refracted = ni_over_nt*(uv - dt*n) - sqrt(discriminant)*n;
        return true;
    }
    else
        return false;
}

class dielectric : public material {
public:
    dielectric(float ri) : ref_idx(ri) {}
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const  {
        vec3 outward_normal;
        vec3 rec_in_direction=r_in.direction();
        vec3 reflected = reflect(r_in.direction(), rec.normal);
        float ni_over_nt;
        attenuation = vec3(1.0, 1.0, 1.0);
        vec3 refracted;
        float reflect_prob;
        float cosine;
        if (dot(r_in.direction(), rec.normal) > 0) {
            outward_normal = (-1)*rec.normal;
            ni_over_nt = ref_idx;
            //         cosine = ref_idx * dot(r_in.direction(), rec.normal) / r_in.direction().length();
            cosine = dot(r_in.direction(), rec.normal) / r_in.direction().length();
            cosine = sqrt(1 - ref_idx*ref_idx*(1-cosine*cosine));
        }
        else {
            outward_normal = rec.normal;
            ni_over_nt = 1.0 / ref_idx;
            cosine = -dot(r_in.direction(), rec.normal) / r_in.direction().length();
        }
        if (refract(rec_in_direction,outward_normal,ni_over_nt,outward_normal)) {
            reflect_prob = schlick(cosine, ref_idx);
        } else
            reflect_prob = 1.0;

        // 随机数小与反射系数，设为反射光线，反之为折射光线
        if (drand48() < reflect_prob)
            scattered = ray(rec.p, reflected);
        else
            scattered = ray(rec.p, refracted);
        return true;
    }

    float ref_idx;
};

#endif //RAYTRACING_DIELECTRIC_H

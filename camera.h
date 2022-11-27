//
// Created by Song Yawei on 2022/11/26.
//

#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H
#include "ray.h"

#include "ray.h"

class camera
{
    vec3 origin;
    vec3 u,v,w;
    vec3 horizontal;
    vec3 vertical;
    vec3 lower_left_corner;
    float len_radius;

public :
    camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect, float aperture, float focus_dist)
    {
        len_radius = aperture/2;
        float theta = vfov*M_PI/180;
        float half_height = tan(theta/2);
        float half_width = aspect * half_height;
        origin = lookfrom;

        w = (lookfrom - lookat).make_unit_vec();
        u = cross(vup, w).make_unit_vec();
        v = cross(w,u);

        lower_left_corner = origin - half_width*focus_dist*u - half_height*focus_dist*v - focus_dist*w;
        horizontal = 2*half_width*focus_dist*u;
        vertical = 2*half_height*focus_dist*v;
    }

    ray get_ray(float s,float t)
    {
        vec3 rd = len_radius * random_in_unit_disk();
        vec3 offset = rd.x()*u +rd.y()*v;
        return ray(origin + offset,lower_left_corner+s*horizontal + t*vertical - origin - offset);
    }

    vec3 random_in_unit_disk()
    {
        vec3 p;
        do{
            p = 2.0*vec3(drand48(),drand48(),0)-vec3(1,1,0);
        }while (dot(p,p)>=1.0);
        return p;
    }

};


#endif //RAYTRACING_CAMERA_H

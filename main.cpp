#include <iostream>

#include "sphere.h"
#include "hitablelist.h"
#include "float.h"
#include "camera.h"
#include "random"
#define random(a,b) (rand()%(b-a+1)+a)
using namespace std;

//float hit_sphere(const vec3& center,float radius,const ray &r){
//    vec3 sphere_center = r.origin()-center;
//    float a = dot(r.direction(),r.direction());
//    float b = 2.0* dot(sphere_center,r.direction());
//    float c = dot(sphere_center,sphere_center)-radius*radius;
//    float discriminant = b*b -4*a*c;
//    if (discriminant<0){
//        return -1.0;
//    }else{
//        return (-b - sqrt(discriminant))/(2.0*a);
//    }
//}

vec3 color(const ray& r, hitable *world){
    hit_record rec;
    if (world->hit(r,0.0,FLT_MAX,rec)){
        return 0.5*vec3(rec.normal.x()+1,rec.normal.y()+1,rec.normal.z()+1);
    }else{
        vec3 unit_direction = r.direction().make_unit_vec();
        float t = 0.5*(unit_direction.y()+1.0);
        return (1.0-t)*vec3(1.0,1.0,1.0)+t*vec3(0.5,0.7,1.0);
    }
}


int main() {
    FILE* fp;
    fp=fopen("test.ppm","w");

    int x = 2000;
    int y = 1000;
    int ns = 100;
    vec3 lower_left_corner(-2.0,-1.0,-1);
    vec3 horizontal(4.0,0.0,0.0);
    vec3 vertical(0.0,2.0,0.0);
    vec3 origin(0.0,0.0,0.0);
    hitable *list[2];
    list[0] = new sphere(vec3(0,0,-1),0.5);;
    list[1] = new sphere(vec3(0,-100.5,-1),100.0);
    hitable *world= new hitablelist(list,2);
    camera cam;
    fprintf(fp,"P3\n%d %d\n255\n",x,y);
    for (int j = y -1; j >=0 ; j--) {
        for (int i = 0; i < x; i++) {
            vec3 col(0,0,0);
            for (int k = 0; k < ns; k++) {
                float ratio_x =  float(i + float(random(0,100))/100.0)/float(x);
                float ratio_y =  float(j + float(random(0,100))/100.0)/float(y);
                ray r = cam.get_ray(ratio_x,ratio_y);
                vec3 p = r.point_at_parameter(2.0);
                col = col+color(r, world);
            }


           col = col/float(ns);
           int rp = int(255.99*col.x());
           int gp = int(255.99*col.y());
           int bp = int(255.99*col.z());
           fprintf(fp,"%d %d %d\n",rp,gp,bp);
        }
    }
//    vec3 v(3.0,0.0,0.0);
//    vec3 v_unit = v.make_unit_vec();
//    std::cout << "v_x: " <<v.x()<< std::endl;
//    std::cout << "v_y: " <<v.y()<< std::endl;
//    std::cout << "v_z: " <<v.z()<< std::endl;
//    std::cout << "unit_x: " <<v_unit.x()<< std::endl;
//    std::cout << "unit_y: " <<v_unit.y()<< std::endl;
//    std::cout << "unit_z: " <<v_unit.z()<< std::endl;
    fclose(fp);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

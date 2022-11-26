//
// Created by Song Yawei on 2022/11/24.
//

#ifndef RAYTRACING_VEC3_H
#define RAYTRACING_VEC3_H
#include "math.h"

class vec3 {
public:
    vec3(){};
    vec3(float f1,float f2,float f3){e[0]=f1;e[1]=f2;e[2]=f3;};
    //method
    inline float x(){return e[0];}
    inline float y(){return e[1];}
    inline float z(){return e[2];}
    inline float length(){
        return sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
    }
    vec3 make_unit_vec();
public:
    float e[3];
};



#endif //RAYTRACING_VEC3_H
inline vec3 operator+ (const vec3& v1, const vec3& v2){
    return vec3(v1.e[0]+v2.e[0],v1.e[1]+v2.e[1],v1.e[2]+v2.e[2]);
}
inline vec3 operator-(const vec3& v1, const vec3& v2){
    return vec3(v1.e[0]-v2.e[0],v1.e[1]-v2.e[1],v1.e[2]-v2.e[2]);
}
inline vec3 operator*(const vec3& v1, const vec3& v2){
    return vec3(v1.e[0]*v2.e[0],v1.e[1]*v2.e[1],v1.e[2]*v2.e[2]);
}
inline vec3 operator*(const float f, const vec3& v){
    return vec3(f*v.e[0],f*v.e[1],f*v.e[2]);
}

inline vec3 operator/(const vec3& v1, const vec3& v2){
    return vec3(v1.e[0]/v2.e[0],v1.e[1]/v2.e[1],v1.e[2]/v2.e[2]);
}


inline vec3 operator/(const vec3& v, const float f){
    return vec3(v.e[0]/f,v.e[1]/f,v.e[2]/f);
}

inline float dot(const vec3& v1, const vec3& v2){
    return v1.e[0]*v2.e[0]+v1.e[1]*v2.e[1]+v1.e[2]*v2.e[2];
}

inline vec3 cross(const vec3& v1, const vec3& v2){
    return vec3((v1.e[1]*v2.e[2]-v1.e[2]*v2.e[1]),
                (-(v1.e[0]*v2.e[2]-v1.e[2]*v2.e[0])),
                (v1.e[0]*v2.e[1]-v1.e[1]*v2.e[0])
                );
}

inline vec3 reflect(const vec3& v, const vec3& n){
    return v-2*dot(v,n)*n;
}

inline vec3 vec3::make_unit_vec() {
    return *this/ this->length();
}


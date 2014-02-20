#pragma once

typedef float vec3 [3];

class Particle
{
    public:
        Particle(float pos_x, float pos_y, float pos_z,
                 float vel_x, float vel_y, float vel_z,
                 float r);

        vec3 pos;
        vec3 vel;

        vec3 omega;
        vec3 omega_old;
        vec3 omega_dot;

        vec3 F;

        const float r;
        const float m_inverse;
};

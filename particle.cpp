#include "particle.h"

Particle::Particle(float pos_x, float pos_y, float pos_z,
                   float vel_x, float vel_y, float vel_z,
                   float r)
    : r(r)
    , m_inverse(1)
{
    pos[0] = pos_x;
    pos[1] = pos_y;
    pos[2] = pos_z;

    vel[0] = vel_x;
    vel[1] = vel_y;
    vel[2] = vel_z;

    for (int i = 0; i < 3; i++)
    {
        omega[i] = 0;
        omega_old[i] = 0;
        omega_dot[i] = 0;

        F[i] = 0;
    }
}


#pragma once

#include "particle.h"
#include <cuda.h>

class Simulation
{
    public:

        Simulation(Particle const *particles, int N, float dt);

        int readOut(Particle* &particles) const;

        /*
         * Integration
         *
         */

        double dt;

        void predictionStep();

    private:

        const int N;
        const size_t size;
        Particle* d_particles;
};

#include "simulation.h"

#include "cuda/simulation.h"
#include "cuda/prediction_step.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Simulation::Simulation(Particle const *particles, int N, float dt)
    : dt(dt)
    , N(N)
    , size(N * sizeof(Particle))
{
    Cuda::store(d_particles, particles, size);
}

int Simulation::readOut(Particle* &result) const
{
    result = (Particle*) malloc(size);
    Cuda::read_out(d_particles, result, size);
    return N;
}

/*
 * Integration
 *
 */

void Simulation::predictionStep()
{
    Cuda::run_prediction_step(N, d_particles, dt);
}

#include "prediction_step.cuh"

namespace Cuda
{

__global__
void prediction_step(Particle *particles, float dt)
{
    Particle &p = particles[threadIdx.x];
    const unsigned int i = threadIdx.y;

    p.pos[i] += p.vel[i] * dt + 0.5 * dt * dt * p.F[i];
}

__host__
void run_prediction_step(int N, Particle *d_particles, float dt)
{
    prediction_step <<< 1, dim3(N, 3) >>>
        (d_particles, dt);
}

}

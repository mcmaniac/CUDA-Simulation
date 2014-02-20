#include <cuda.h>
#include "simulation.h"

namespace Cuda
{

__host__
void store(Particle* &dev, Particle const *particles, size_t size)
{
    cudaMalloc(&dev, size);
    cudaMemcpy(dev, particles, size, cudaMemcpyHostToDevice);
}

__host__
void read_out(Particle *dev, Particle* &res, size_t size)
{
    cudaMemcpy(res, dev, size, cudaMemcpyDeviceToHost);
}

}

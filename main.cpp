#include "simulation.h"
#include <iostream>

using namespace std;

const float dt = 0.05;

const int N = 2;
const Particle particles[N] =
{
    Particle( 0,0,0, 10,0,0, 1),
    Particle(10,0,0,  0,0,0, 1)
};

int main()
{
    Simulation sim(particles, N, dt);

    sim.predictionStep();

    /*
     * Output
     *
     */

    Particle *p;
    sim.readOut(p);

    for (int i = 0; i < N; i++)
    {
        cout
            << p[i].pos[0] << " "
            << p[i].pos[1] << " "
            << p[i].pos[2] << " "
            << p[i].r
            << endl;
    }

    delete[] p;
    return EXIT_SUCCESS;
}

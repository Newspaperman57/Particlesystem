#ifndef __SIMULATOR_MODULE
#define __SIMULATOR_MODULE

#include "Particle.h"

class SimulatorModule
{
public:
	virtual bool OnInitialize() = 0;
	virtual bool OnStart() = 0;
	virtual bool OnStop() = 0; 
	virtual bool OnTick(Particle* particles, int particleCount, double deltaTime) = 0;
};

#endif


// Will get called every tick
// Will get information about current world (particles f.x)
// Will get delta-time (To be able to control speed centrally)
// Will get called at open and close

// All methods return a boolean confirming a succesfull run
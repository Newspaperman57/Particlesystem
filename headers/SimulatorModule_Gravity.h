#ifndef __SIMULATOR_MODULE_GRAVITY
#define __SIMULATOR_MODULE_GRAVITY

#include <stdio.h>
#include "SimulatorModule.h"
#include "Particle.h"

class SimulatorModule_Gravity: public SimulatorModule
{
private:
	DVector2 gravity;
public:
	SimulatorModule_Gravity();
	~SimulatorModule_Gravity();
	bool OnInitialize();
	bool OnStart();
	bool OnStop(); 
	bool OnTick(Particle* particles, int particleCount, double deltaTime);
};

#endif


// This class will take care of down-wards gravity
// It can be configured to different newtons and different angles if needed
// This will not look at interference between particles
// Every tick this will put some force on all particles
// Particles will 
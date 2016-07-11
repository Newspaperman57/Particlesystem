#include "SimulatorModule_Gravity.h"

SimulatorModule_Gravity::SimulatorModule_Gravity() {
	printf("SimulatorModule_Gravity: Instantiated\n");
}

SimulatorModule_Gravity::~SimulatorModule_Gravity() {

}

bool SimulatorModule_Gravity::OnInitialize() {
	return true;
}

bool SimulatorModule_Gravity::OnStart() {
	gravity.Y = 9.85;
	gravity.X = 0;
	return true;
}

bool SimulatorModule_Gravity::OnStop() {
	gravity.Y = 0;
	gravity.X = 0;
	return true;
} 

bool SimulatorModule_Gravity::OnTick(Particle* particles, int particleCount, double deltaTime) {
	printf("SimulatorModule_Gravity: OnTick\n");
	// Run through all particles and add calculated velocity times deltatime
	for (int i = 0; i < particleCount; i++)
	{
	 	particles[i].AddVelocity(gravity);
	}
	return true;
}

#include <stdio.h>
#include "Simulator.h"
#include "SimulatorModule_Gravity.h"

int main( int argc, char* args[] )
{
	printf("Main started\n");
	Simulator sim = Simulator(1);
	sim.Initialize();
	sim.Start();

	// Add Gravity module
	
	SimulatorModule_Gravity* Gravity = new SimulatorModule_Gravity();

	sim.AddModule( (SimulatorModule*) Gravity );
	
	sim.NextTick();
	
	//SDL_Delay(2000);
	
	sim.Stop();
	return 0;
}
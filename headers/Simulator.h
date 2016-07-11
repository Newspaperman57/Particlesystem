#ifndef __SIMULATOR
#define __SIMULATOR

#include <stdio.h>
#include <vector>
#include "SDL_Graphics.h"
#include "Particle.h"
#include "SimulatorModule.h"

class Simulator
{
private:
	SDL_Graphics graphics;
	std::vector<SimulatorModule*> simulatorModules;
	Particle* particles;
	int particleCount;
	bool initialized;
	bool started;
public:
	Simulator(int particleCount);
	~Simulator();
	bool IsInitialized();
	bool IsStarted();
	bool Initialize();
	void Start();
	bool Stop(); 
	void NextTick();
	bool AddModule(SimulatorModule* newModule);
};

#endif
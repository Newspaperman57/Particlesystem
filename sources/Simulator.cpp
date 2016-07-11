#include "Simulator.h"

Simulator::Simulator(int particleCount) {
	particles = (Particle*)malloc( sizeof(Particle) * particleCount );
	for (int i = 0; i < particleCount; ++i)
	{
		particles[i] = Particle(0, 0);
	}
	printf("Simulator: Created\n");
	simulatorModules = std::vector<SimulatorModule*>();
}

Simulator::~Simulator() {
	printf("Simulator: Destroyed\n");
}

bool Simulator::IsStarted() {
	return started;
}

bool Simulator::IsInitialized() {
	return initialized;
}

void Simulator::Start() {
	if( !this->IsInitialized() )
		printf("ERROR: Simulator: Start was called before Initialize!\n");
	printf("Simulator: Started\n");
	if(!graphics.IsOpen()) {
		graphics.Open(Vector2(1024, 720), "Simulatorinator!");
	} else {
		printf("ERROR: Simulator: SDL_Graphics was already opened!\n");
	}
	started = true;
}

bool Simulator::Initialize() {
	printf("Simulator: Initialized\n");
	initialized = true;
	return true;
}

bool Simulator::Stop() {
	printf("Simulator: Stopped\n");
	return true;
	started = false;
}

void Simulator::NextTick() {
	printf("Simulator: Next Tick\n");
	// Call all functions in tickFunctions
	for (int i = 0; i < (int)simulatorModules.size(); i++)
	{
		simulatorModules[i]->OnTick(NULL, 0, 1);
	}
}

bool Simulator::AddModule(SimulatorModule* newModule) {
	printf("Simulator: Adding Module\n");
	if( IsInitialized() )
		newModule->OnInitialize();
	if( IsStarted() )
		newModule->OnStart();

	simulatorModules.push_back(newModule);
	return true;
}
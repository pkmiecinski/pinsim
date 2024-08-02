#include "rpisim.hpp"

RpiSim::RpiSim() 
{
    controllerPtr = std::make_shared<Controller>();
}

void RpiSim::run() 
{
    controllerPtr->Run();
}

void RpiSim::setPinState(unsigned int pinNumber, bool state)
{
    controllerPtr->SetPinState(pinNumber, state);
}

bool RpiSim::getPinState(unsigned int pinNumber)
{
    return controllerPtr->GetPinState(pinNumber);
}

void RpiSim::setPinToInput(unsigned int pinNumber)
{
    controllerPtr->SetPinInput(pinNumber);
}

void RpiSim::setPinToOutput(unsigned int pinNumber)
{
    controllerPtr->SetPinOutput(pinNumber);
}
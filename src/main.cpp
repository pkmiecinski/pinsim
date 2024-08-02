#include "rpisim/app/rpisim.hpp"
#include <thread>
#include <unistd.h>

RpiSim *rpisim;

constexpr int outputPinNumber = 3;  
constexpr int inputPinNumber = 5;
constexpr int timeToSleepLong = 500000;
constexpr int timeToSleepShort = 250000;

std::atomic<int> timeToSleep(timeToSleepLong);
std::atomic<bool> continueWork(true);

void ledset_thread_function()
{
    bool buttonState = false;
    while(continueWork)
    {
        rpisim->setPinState(outputPinNumber, (buttonState =!buttonState) ? true : false);
        usleep(timeToSleep);
    }
}

void button_thread_function()
{
    while(continueWork)
    {
        if(rpisim->getPinState(inputPinNumber))
        {
            timeToSleep = timeToSleepShort;
        }
        else
        {
            timeToSleep = timeToSleepLong;
        }
        usleep(10);
    }
}

int main(void) 
{
    rpisim = new RpiSim();
    rpisim->setPinToOutput(outputPinNumber);
    rpisim->setPinToInput(inputPinNumber);

    std::thread ledSetThread(&ledset_thread_function);
    std::thread buttonThread(&button_thread_function);

    rpisim->run();
    continueWork = false;

    ledSetThread.join();
    buttonThread.join();
 
    return EXIT_SUCCESS;
}





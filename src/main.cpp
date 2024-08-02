#include "rpisim/app/rpisim.hpp"
#include <thread>
#include <unistd.h>


RpiSim *rpisim;
std::atomic<int> timeToSleep(500000);
std::atomic<bool> continueWork(true);

void ledset_thread_function()
{
    bool buttonState = false;
    while(continueWork)
    {
        rpisim->setPinState(3, (buttonState =!buttonState) ? true : false);
        usleep(timeToSleep);
    }
}

void button_thread_function()
{
    while(continueWork)
    {
        if(rpisim->getPinState(5))
        {
            timeToSleep = 250000;
        }
        else
        {
            timeToSleep = 500000;
        }
    }
}

int main(void) 
{
    //! rpi header simulator
    rpisim = new RpiSim();
    rpisim->setPinToOutput(3);
    rpisim->setPinToInput(5);

    std::thread ledSetThread(&ledset_thread_function);
    std::thread buttonThread(&button_thread_function);

    rpisim->run();
    continueWork = false;

    ledSetThread.join();
    buttonThread.join();
 
    return EXIT_SUCCESS;
}





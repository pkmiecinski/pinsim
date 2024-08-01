#include "rpisim/controller/controller.hpp"
#include <thread>
#include <unistd.h>

Controller *controller;

void thread_function()
{
    while(1)
    {
        controller->SetPin(3, true);
        controller->SetPin(5, true);
        controller->SetPin(7, true);

        sleep(1);

        controller->SetPin(3, false);
        controller->SetPin(5, false);
        controller->SetPin(7, false);

        sleep(1);
    }
}




int main(void) 
{ 
    controller = new Controller();
    std::thread t(&thread_function);
    controller->Run();
    t.join();
 
    return EXIT_SUCCESS;
}





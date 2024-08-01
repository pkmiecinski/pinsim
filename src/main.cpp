#include "rpisim/controller/controller.hpp"
#include <thread>
#include <unistd.h>
#include <iostream>
#include <semaphore>

Controller *controller;


void thread_function()
{
    while(1)
    {
        //std::cout << "Setting pins 3, 5, 7 to true" << std::endl;
        controller->SetPin(3, true);
        controller->SetPin(5, true);
        controller->SetPin(7, true);

        //std::cout << "Sleeping for 1 second" << std::endl;

        sleep(1);

        //std::cout << "Setting pins 3, 5, 7 to false" << std::endl;
        controller->SetPin(3, false);
        controller->SetPin(5, false);
        controller->SetPin(7, false);

        //std::cout << "Sleeping for 1 second" << std::endl;
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





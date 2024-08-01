#include "rpisim/controller/controller.hpp"
#include <thread>
#include <unistd.h>
#include <iostream>

Controller *controller;


void thread_function()
{
    controller->SetPin(3, true);
    controller->SetPin(5, true);
    controller->SetPin(7, true);

    std::cout << "Sleeping for 1 second" << std::endl;

    sleep(1);

    controller->SetPin(3, false);
    controller->SetPin(5, false);
    controller->SetPin(7, false);

    sleep(1);
}




int main(void) 
{ 
    controller = new Controller();

    std::thread t(&thread_function);


  
    controller->Run();

    t.join();
 
    return EXIT_SUCCESS;
}





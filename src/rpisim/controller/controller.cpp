#include "controller.hpp"

#define COMPILE_WITH_CONTROLLER_KEY_SUPPORT

Controller::Controller()
{
    model = new Model("../config/rpi_pinout.json");
    view  = new View( model->getModel());
}

void Controller::Run()
{   
    auto screen = ScreenInteractive::FitComponent();
    std::atomic<bool> refresh_ui_continue = true;
#ifdef COMPILE_WITH_CONTROLLER_KEY_SUPPORT    
    auto catchKeyboard = CatchEvent([&](Event event) 
    {
        if (event == Event::Character('q')) 
        {
            model->getModel()->at(5).setState(true);
            return true;
        }
        if (event == Event::Character('w')) 
        {
            model->getModel()->at(5).setState(false);
            return true;
        }
        if (event == Event::Character('e'))
        {
            screen.Exit();
            refresh_ui_continue = false;
            return true;
        }
        return false;
    });
#endif
    auto component_renderer = Renderer([&] { return view->Process();} );
#ifdef COMPILE_WITH_CONTROLLER_KEY_SUPPORT        
    component_renderer |= catchKeyboard;
#endif


    std::thread refresh_ui ( [&] {
        while ( refresh_ui_continue ) {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for ( 0.001s ); 
            screen.PostEvent ( Event::Custom );
        }
    } );

    screen.Loop(component_renderer);
    refresh_ui.join();
}

void Controller::SetPinState(unsigned int pinNumber, bool state)
{
    model->getModel()->at(pinNumber).setState(state);
}

bool Controller::GetPinState(unsigned int pinNumber)
{
    return model->getModel()->at(pinNumber).getState();
}

void Controller::SetPinInput(unsigned int pinNumber)
{
    model->getModel()->at(pinNumber).setToInput();
}

void Controller::SetPinOutput(unsigned int pinNumber)
{
    model->getModel()->at(pinNumber).setToOutput();
}
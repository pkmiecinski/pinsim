#include "controller.hpp"

Controller::Controller()
{
    model = new Model("../config/rpi_pinout.json");
    view  = new View( model->getModel());
}

void Controller::Run()
{   
    auto component_renderer = Renderer([&] { return view->Process();} );
    auto screen = ScreenInteractive::FitComponent();
    std::atomic<bool> refresh_ui_continue = true;
    std::thread refresh_ui ( [&] {
        while ( refresh_ui_continue ) {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for ( 0.02s ); 
            screen.PostEvent ( Event::Custom );
        }
    } );

    screen.Loop(component_renderer);
}

void Controller::SetPin(unsigned int pinNumber, bool state)
{
    model->getModel()->at(pinNumber).setState(state);
}

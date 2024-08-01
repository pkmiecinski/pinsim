#include "controller.hpp"

Controller::Controller()
{
    model = new Model("../config/rpi_pinout.json");
    view  = new View( model->getModel());

    component_renderer = Renderer([&] { return view->Process();} );
}
void Controller::Run()
{   
    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(component_renderer);
}

void Controller::SetPin(unsigned int pinNumber, bool state)
{
    model->getModel()->at(pinNumber).setState(state);
}
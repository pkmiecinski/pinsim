#include "../model/model.hpp"
#include "../view/view.hpp"

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include "ftxui/screen/color.hpp" 

#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/event.hpp"
#include "ftxui/component/screen_interactive.hpp"

class Controller 
{
public:
    Controller();
    void Run();
    void SetPinState(unsigned int pinNumber, bool state);
    bool GetPinState(unsigned int pinNumber);
    void SetPinInput(unsigned int pinNumber);
    void SetPinOutput(unsigned int pinNumber);

 private:
    std::unique_ptr<Model> model;
    std::unique_ptr<View>  view;  

};
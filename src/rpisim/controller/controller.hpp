#include "../model/model.hpp"
#include "../view/view.hpp"

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include "ftxui/screen/color.hpp" 

#include "ftxui/component/component.hpp"  // for Renderer, CatchEvent, Horizontal, Menu, Tab
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/event.hpp"               // for Event
#include "ftxui/component/mouse.hpp"               // for Mouse
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/canvas.hpp"                    // for Canvas
#include "ftxui/screen/color.hpp"  // for Color, Color::Red, Color::Blue, Color::Green, ftxui

class Controller 
{
public:
    Controller();
    void Run();
    void SetPin(unsigned int pinNumber, bool state);
    void Tick();

 private:
    Model *model;
    View *view;  
    // ftxui::Component component_renderer;
    //ftxui::ScreenInteractive *screen;

};
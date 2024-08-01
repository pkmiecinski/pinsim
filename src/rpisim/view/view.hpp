#pragma once
#include <map>
#include "../model/cpin.hpp"
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

using namespace ftxui;

class View {
public:
    View(std::map<unsigned int, cpin>* modelPtr);
    ftxui::Element Process();


private:
    std::map<unsigned int, cpin>* rpi2x20header;

    ftxui::Elements headerTop, headerBottom, stateTop, stateBottom;
};
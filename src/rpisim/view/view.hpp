#pragma once
#include <map>
#include "../model/cpin.hpp"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include "ftxui/screen/color.hpp" 

#include "ftxui/component/component.hpp" 
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/event.hpp"
#include "ftxui/component/screen_interactive.hpp"

using namespace ftxui;

class View {
public:
    View(std::map<unsigned int, cpin>* modelPtr);
    ftxui::Element Process();

private:
    std::map<unsigned int, cpin>* rpi2x20header;

    ftxui::Elements headerTop, headerBottom, stateTop, stateBottom;
};
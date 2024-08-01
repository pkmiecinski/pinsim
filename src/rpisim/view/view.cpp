#include "view.hpp"

ftxui::Color getColor(PinType type)
{
  switch (type)
  {
    case PinType::gpio:
      return Color::Green1;
    case PinType::ground:
      return Color::GrayDark;
    case PinType::power5v:
      return Color::Red;
    case PinType::power3v3:
      return Color::Orange1;
    case PinType::id_sd:
      return Color::Yellow1;
    case PinType::id_sc:
      return Color::Yellow1;
    default:
      return Color::White;
  }
}


View::View(std::map<unsigned int, cpin>* modelPtr): rpi2x20header(modelPtr) 
{

}

ftxui::Element View::Process()
{
    headerTop.clear();
    headerBottom.clear();
    stateTop.clear();
    stateBottom.clear();

    for (auto &pin : *rpi2x20header)
    {
        Element headerElement = color(getColor(pin.second.getPinType()), text(pin.second.getName())) | borderHeavy;
        Element pinElement    = color(Color::NavajoWhite1, text("      ")) | borderRounded | bgcolor(pin.second.getState() ? (Color::Green3) : (Color::NavajoWhite1));

        if (pin.second.getPinNumber() % 2 == 0)
        {
            headerTop.push_back(headerElement);
            stateTop.push_back(pinElement);
        }
        else
        {
            headerBottom.push_back(headerElement);
            stateBottom.push_back(pinElement);
        }
    }

    return 
    vbox({
        hbox(headerTop),
        hbox(stateTop),
        hbox(stateBottom),
        hbox(headerBottom)
    });
}
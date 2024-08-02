
#include <string>
#pragma once

enum class PinType { gpio, ground, power5v, power3v3, id_sd, id_sc};


class cpin
{
  private:
    unsigned int pinNumber;
    std::string name;
    std::string type;
    PinType ePinType;
    bool isInput;
    bool isAltFunction;
    bool state;

  public:
    cpin(unsigned int pinNumber, std::string name, std::string type, bool isInput, bool altFunction)
    {
        this->pinNumber = pinNumber;
        this->name = name;
        this->type = type;
        this->ePinType = getPinType();
        this->isInput = isInput;
        this->isAltFunction = altFunction;
    }
    cpin(unsigned int pinNumber, std::string name, std::string type)
    {
        this->pinNumber = pinNumber;
        this->name = name;
        this->type = type;
        this->ePinType = getPinType();
        this->isInput = false;
        this->isAltFunction = false;
        this->state = false;
    }

    PinType getPinType();

    unsigned int getPinNumber();

    std::string getName();

    std::string getType();

    bool getIsInput();
    void setToInput();
    void setToOutput();
    bool getAlternateFunction();
    bool getState();
    void setState(bool state);
};

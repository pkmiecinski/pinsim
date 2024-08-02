#include "cpin.hpp"

PinType cpin::getPinType()
{
    if (this->type == "gpio")
    {
    return PinType::gpio;
    }
    else if (this->type == "ground")
    {
    return PinType::ground;
    }
    else if (this->type == "power5v")
    {
    return PinType::power5v;
    }
    else if (this->type == "power3v3")
    {
    return PinType::power3v3;
    }
    else if (this->type == "id_sd")
    {
    return PinType::id_sd;
    }
    else if (this->type == "id_sc")
    {
    return PinType::id_sc;
    }
    else
    {
    return PinType::gpio;
    }
}

unsigned int cpin::getPinNumber()
{
    return this->pinNumber;
}

std::string cpin::getName()
{
    return this->name;
}

std::string cpin::getType()
{
    return this->type;
}

bool cpin::getIsInput()
{
    return this->isInput;
}

bool cpin::getAlternateFunction()
{
    return this->isAltFunction;
}

bool cpin::getState()
{
    return this->state;
}

void cpin::setState(bool state)
{
    this->state = state;
}

void cpin::setToInput()
{
    this->isInput = true;
}

void cpin::setToOutput()
{
    this->isInput = false;
}
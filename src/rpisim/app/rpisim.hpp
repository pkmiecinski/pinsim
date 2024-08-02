#include <memory>
#include "../controller/controller.hpp"


class IRpiSimApp
{
    public:
        virtual void run() = 0;
};

class IGpio
{
    public:
        virtual void setPinState(unsigned int pinNumber, bool state) = 0;
        virtual bool getPinState(unsigned int pinNumber) = 0;
        virtual void setPinToInput(unsigned int pinNumber) = 0;
        virtual void setPinToOutput(unsigned int pinNumber) = 0;
};


class RpiSim : public IRpiSimApp, IGpio
{ 
public:
    RpiSim();
    void run() override;
    void setPinState(unsigned int pinNumber, bool state) override;
    bool getPinState(unsigned int pinNumber) override;
    void setPinToInput(unsigned int pinNumber) override;
    void setPinToOutput(unsigned int pinNumber) override;
private:
    std::shared_ptr<Controller> controllerPtr;
};
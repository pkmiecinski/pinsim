#include "model.hpp"

Model::Model(const std::string configFile) : jsonConfigFile(configFile) 
{
    try
    {
        std::ifstream f("../config/rpi_pinout.json");
        data = json::parse(f);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Can't open/parse config file" << e.what() << '\n';
    }
    

    rpi2x20header = new std::map<unsigned int, cpin>();
    for (auto &pin : data["pinHeader"]["pins"])
    {
        rpi2x20header->insert( std::pair<unsigned int, cpin> (pin["number"], cpin(pin["number"], pin["name"], pin["type"])));
    }
}
std::string Model::getConfigFile() const {
    return jsonConfigFile;
}

std::map<unsigned int, cpin>* Model::getModel()
{
    return rpi2x20header;
}
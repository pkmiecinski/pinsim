#pragma once 

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "cpin.hpp"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Model {
public:
    Model(const std::string jsonConfigFile);
    std::string getConfigFile() const;
    std::map<unsigned int, cpin>* getModel();

private:
    std::string jsonConfigFile;
    json data;
    std::map<unsigned int, cpin>* rpi2x20header; 
};
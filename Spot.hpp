#pragma once
#include "ISpot.hpp"
#include <iostream>

class Spot : public ISpot
{
    std::string vin;
    SpotStatus status;
    VType type;

public:
    Spot(VType vehicleType);
    Spot *assign(std::string vin, VType type);
    Spot *release();
    SpotStatus getStatus();
    std::string getVehicleNumber();
};
#pragma once
#include <iostream>

enum class SpotStatus
{
    OCCUPIED,
    AVAILABLE
};
enum class VType
{
    CAR,
    BIKE,
    TRUCK
};

class ISpot
{
public:
    virtual SpotStatus getStatus() = 0;
    virtual ISpot *assign(std::string vin, VType type) = 0;
    virtual ISpot *release() = 0;
    virtual std::string getVehicleNumber() = 0;
};

#pragma once
#include "ISpot.hpp"
#include <iostream>

class ILevel
{
public:
    virtual ~ILevel()
    {
        std::cout << "Virtual level deleted" << std::endl;
    }
    virtual void addSpot(ISpot *, int) = 0;
    virtual ISpot *findAvailableSpot() = 0;
    virtual ISpot *findSpotByVehicleNumber(std::string) = 0;
};
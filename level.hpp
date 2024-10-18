#pragma once
#include <vector>
#include "ILevel.hpp"
class Level : public ILevel
{
    std::vector<ISpot *> spots;
    int levelNumber;

public:
    Level(int levelNumber, int spotCount);
    ~Level();
    void addSpot(ISpot *spot, int index);
    ISpot *findAvailableSpot();
    ISpot *findSpotByVehicleNumber(std::string vin);
};
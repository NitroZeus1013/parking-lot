#pragma once
#include "ISpot.hpp"
#include <iostream>
#include "level.hpp"
#include <vector>

class ParkingLot
{
    std::vector<ILevel *> levels;
    int levelIndex = 0;
    static ParkingLot *instance;

public:
    ~ParkingLot();
    void addLevel(ILevel *lv);
    void assignSpot(std::string vin, VType type);
    void releaseSpot(std::string vin);
    void init(int);
    static ParkingLot *getInstance();
};
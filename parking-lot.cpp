#include "ILevel.hpp"
#include <iostream>
#include <vector>
#include "parking-lot.hpp"
#include <stdexcept>

ParkingLot *ParkingLot::instance = nullptr;

void ParkingLot::init(int levelCount)
{
    this->levels.resize(levelCount);
}

ParkingLot *ParkingLot::getInstance()
{
    if (instance == nullptr)
    {
        instance = new ParkingLot();
    }

    return instance;
}
ParkingLot::~ParkingLot()
{
    std::cout << "Called parking lot destructor " << std::endl;

    for (ILevel *lv : this->levels)
    {
        std::cout << lv << std::endl;
        delete lv;
    }
    this->levels.clear();
}
void ParkingLot::addLevel(ILevel *level)
{
    if (levelIndex >= levels.size())
    {
        throw std::invalid_argument("There are no more levels");
    }
    this->levels[levelIndex++] = level;
}

void ParkingLot::assignSpot(std::string vin, VType type)
{
    ISpot *avblSpot = nullptr;
    for (ILevel *lv : this->levels)
    {
        ISpot *sp = lv->findAvailableSpot();
        if (sp != nullptr)
        {
            avblSpot = sp;
            break;
        }
    }

    if (avblSpot != nullptr)
        avblSpot->assign(vin, type);
    else
    {
        std::cout << "No available spot" << std::endl;
    }
}

void ParkingLot::releaseSpot(std::string vin)
{
    ISpot *avblSpot = nullptr;
    for (ILevel *lv : levels)
    {
        ISpot *sp = lv->findSpotByVehicleNumber(vin);
        if (sp != nullptr)
        {
            avblSpot = sp;
            break;
        }
    }
    if (avblSpot)
    {
        avblSpot->release();
    }
    else
    {
        std::cout << "Vehicle not found. Invalid VIN number or Vehicle type" << std::endl;
    }
}

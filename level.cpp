#include <vector>
#include "level.hpp"
#include "Spot.hpp"

Level::Level(int levelNumber, int spotCount)
{
    this->levelNumber = levelNumber;
    this->spots.resize(spotCount);

    // add spots in 5,3,2 ratio
    int carsCount = spotCount * 0.5;
    int bikesCount = spotCount * 0.3;
    int truckCount = spotCount * 0.2;
    // we can use Factory here
    for (int i = 0; i < carsCount; i++)
    {
        Spot *sp = new Spot(VType::CAR);
        this->addSpot(sp, i);
    }
    for (int i = 0; i < bikesCount; i++)
    {
        Spot *sp = new Spot(VType::BIKE);
        this->addSpot(sp, carsCount + i);
    }
    for (int i = 0; i < truckCount; i++)
    {
        Spot *sp = new Spot(VType::TRUCK);
        this->addSpot(sp, i + carsCount + bikesCount);
    }
}
Level::~Level()
{
    std::cout << "Called level destructor " << std::endl;
    for (ISpot *sp : this->spots)
    {
        delete sp;
    }
    this->spots.clear();
}

void Level::addSpot(ISpot *spot, int index)
{
    this->spots[index] = spot;
}
ISpot *Level::findAvailableSpot()
{
    for (ISpot *sp : this->spots)
    {
        if (sp != nullptr && sp->getStatus() == SpotStatus::AVAILABLE)
            return sp;
    }

    return nullptr;
}
ISpot *Level::findSpotByVehicleNumber(std::string vin)
{
    for (ISpot *sp : spots)
    {
        if (sp != nullptr && sp->getVehicleNumber() == vin)
            return sp;
    }

    return nullptr;
}

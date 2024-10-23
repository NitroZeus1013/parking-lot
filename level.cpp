#include <vector>
#include "level.hpp"
#include "Spot.hpp"

// this does not follows OCP
Level::Level(int levelNumber, int spotCount, std::vector<std::pair<VType, float>> spotConfig)
{
    this->levelNumber = levelNumber;
    this->spots.resize(spotCount);

    // we can use Factory here but creation is so simple it'll add unecessary complexity
    int index = 0;
    for (std::pair<VType, float> v : spotConfig)
    {
        int requiredSpotCount = spotCount * v.second;
        for (; index < requiredSpotCount; index++)
        {
            Spot *sp = new Spot(v.first);
            this->addSpot(sp, index);
        }
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

#include <iostream>
#include "parking-lot.hpp"
int main()
{
    ParkingLot *pl = ParkingLot::getInstance();
    pl->init(3);

    std::vector<std::pair<VType, float>> spotConfig = {{VType::CAR, 0.5f}, {VType::BIKE, 0.3f}, {VType::TRUCK, 0.2f}};
    pl->addLevel(new Level(1, 10, spotConfig));
    pl->addLevel(new Level(2, 10, spotConfig));

    pl->assignSpot("MH-32-5419", VType::BIKE);
    pl->releaseSpot("MH-32-5419");

    delete pl;
}
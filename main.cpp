#include <iostream>
#include "parking-lot.hpp"
int main()
{
    ParkingLot *pl = new ParkingLot(3);
    pl->addLevel(new Level(1, 10));
    pl->addLevel(new Level(2, 10));

    pl->assignSpot("MH-32-5419", VType::BIKE);
    pl->releaseSpot("MH-32-5419");

    delete pl;
}
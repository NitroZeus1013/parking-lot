#include "ISpot.hpp"
#include <iostream>
#include "Spot.hpp"

Spot::Spot(VType vehicleType)
{
    this->type = vehicleType;
    this->status = SpotStatus::AVAILABLE;
}
Spot *Spot::assign(std::string vin, VType type)
{
    this->vin = vin;
    this->type = type;
    this->status = SpotStatus::OCCUPIED;
    return this;
}
Spot *Spot::release()
{
    this->vin = "";
    this->status = SpotStatus::AVAILABLE;
    return this;
}
SpotStatus Spot::getStatus()
{
    return this->status;
}

std::string Spot::getVehicleNumber()
{
    return this->vin;
}

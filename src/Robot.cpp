#include <iostream>

#include "Logger.hpp"
#include "Robot.hpp"

void Robot::setTarget(std::string target)
{
    target_ = target;
}

void Robot::setStorage(Molecules storage)
{
    storage_ = storage;
}

void Robot::printDebug()
{
    LOG("Target: " << target_);
    LOG("Storage: " << storage_);
}

std::string Robot::getTarget() const
{
    return target_;
}

bool Robot::hasEnoughMolecules(const Molecules& cost) const
{
    return (storage_.A >= cost.A
        && storage_.B >= cost.B
        && storage_.C >= cost.C
        && storage_.D >= cost.D
        && storage_.E >= cost.E);
}

std::string Robot::getNeededMoleculeName(const Molecules& cost) const
{
    if (storage_.A < cost.A)
    {
        return "A";
    }
    else if (storage_.B < cost.B)
    {
        return "B";
    }
    else if (storage_.C < cost.C)
    {
        return "C";
    }
    else if (storage_.D < cost.D)
    {
        return "D";
    }
    else if (storage_.E < cost.E)
    {
        return "E";
    }
    return "A";
}

bool operator==(const Robot& a, const Robot& b)
{
    return a.target_ == b.target_ && a.storage_ == b.storage_;
}
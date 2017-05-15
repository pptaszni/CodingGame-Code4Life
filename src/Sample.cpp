#include <iostream>

#include "Logger.hpp"
#include "Sample.hpp"


void Sample::setId(int id)
{
    id_ = id;
}

void Sample::setCarriedBy(int carriedBy)
{
    carriedBy_ = carriedBy;
}

void Sample::setHealth(int health)
{
    health_ = health;
}

void Sample::setCost(Molecules cost)
{
    cost_ = cost;
}

void Sample::printDebug() const
{
    LOG("id_: " << id_);
    LOG("carriedBy_: " << carriedBy_);
    LOG("health_: " << health_);
    LOG("cost_: " << cost_);
}

int Sample::getId() const
{
    return id_;
}

int Sample::getCarriedBy() const
{
    return carriedBy_;
}

Molecules Sample::getCost() const
{
    return cost_;
}

bool operator<(const Sample& a, const Sample& b)
{
    if (a.id_ == b.id_)
    {
        return false; // identical element!
    }
    if (a.carriedBy_ != b.carriedBy_)
    {
        return a.carriedBy_ < b.carriedBy_;
    }
    else if (!(a.cost_ == b.cost_))
    {
        return a.cost_ < b.cost_;
    }
    else if (a.health_ != b.health_)
    {
        return a.health_ > b.health_;
    }
    return a.id_ < b.id_;
}
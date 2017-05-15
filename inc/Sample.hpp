#ifndef SAMPLE
#define SAMPLE

#include <string>
#include "Molecules.hpp"

class Sample
{
public:
    Sample() = default;
    void setId(int id);
    void setCarriedBy(int carriedBy);
    void setHealth(int health);
    void setCost(Molecules cost);
    void printDebug() const;
    int getId() const;
    int getCarriedBy() const;
    Molecules getCost() const;
    friend bool operator<(const Sample& a, const Sample& b);
private:
    int id_;
    int carriedBy_;
    int rank_;
    std::string expertiseGain_;
    int health_;
    Molecules cost_;
};

#endif // SAMPLE

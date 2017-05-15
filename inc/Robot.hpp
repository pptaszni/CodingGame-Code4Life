#ifndef ROBOT
#define ROBOT

#include <string>
#include "Molecules.hpp"

class Robot
{
public:
    Robot() = default;
    void setTarget(std::string target);
    void setStorage(Molecules storage);
    void printDebug();
    std::string getTarget() const;
    bool hasEnoughMolecules(const Molecules& cost) const;
    std::string getNeededMoleculeName(const Molecules& cost) const;
    friend bool operator==(const Robot& a, const Robot& b);
private:
    std::string target_;
    int eta_;
    int score_;
    Molecules storage_;
    Molecules expertise_;
};

#endif // ROBOT

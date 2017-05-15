#ifndef GAME_CONTROLLER
#define GAME_CONTROLLER

#include <iostream>
#include <set>

#include "Robot.hpp"
#include "Sample.hpp"

typedef std::set<Sample> SamplesSet;

class GameController
{
public:
    void startGame();
    void loadGameData(std::istream& in, bool initial = false);
    void simpleStrategy();
    Robot getRobot();
    SamplesSet getSamples();
    void fullDebugPrint();
private:
    Robot myRobot_;
    SamplesSet samples_;
};

#endif // GAME_CONTROLLER

#include <iostream>
#include <algorithm>

#include "Logger.hpp"
#include "GameController.hpp"

void GameController::startGame()
{
    std::cerr << "Game started" << std::endl;
    loadGameData(std::cin, true);
    std::cout << "GOTO DIAGNOSIS" << std::endl;
    while(1)
    {
        simpleStrategy();
    }
}

void GameController::simpleStrategy()
{
    loadGameData(std::cin);
    auto rfound = std::find_if(samples_.rbegin(), samples_.rend(),
        [](const Sample& s) { return s.getCarriedBy() == 0; });
    if (rfound == samples_.rend())
    {
        if (myRobot_.getTarget() != "DIAGNOSIS")
        {
            std::cout << "GOTO DIAGNOSIS" << std::endl;
            return;
        }
        std::cout << "CONNECT "
            << std::to_string(samples_.begin()->getId())
            << std::endl;
        return;
    }
    if (myRobot_.hasEnoughMolecules(rfound->getCost()))
    {
        if (myRobot_.getTarget() == "LABORATORY")
        {
            std::cout << "CONNECT "
                << std::to_string(rfound->getId())
                << std::endl;
            return;
        }
        std::cout << "GOTO LABORATORY" << std::endl;
        return;
    }
    if (myRobot_.getTarget() == "MOLECULES")
    {
        std::string needed = myRobot_.getNeededMoleculeName(rfound->getCost());
        std::cout << "CONNECT " << needed << std::endl;
        return;
    }
    std::cout << "GOTO MOLECULES" << std::endl;
}

void GameController::loadGameData(std::istream& in, bool initial)
{
    samples_.clear();
    if (initial)
    {
        int projectCount;
        in >> projectCount; in.ignore();
        for (int i = 0; i < projectCount; i++)
        {
            int a;
            int b;
            int c;
            int d;
            int e;
            in >> a >> b >> c >> d >> e; in.ignore();
        }
        LOG("Initial data loaded");
    }
    std::string target;
    int eta;
    int score;
    Molecules storage;
    int expertiseA;
    int expertiseB;
    int expertiseC;
    int expertiseD;
    int expertiseE;
    in >> target >> eta >> score >> storage.A >> storage.B >> storage.C >> storage.D >> storage.E >> expertiseA >> expertiseB >> expertiseC >> expertiseD >> expertiseE; in.ignore();
    myRobot_.setTarget(target);
    myRobot_.setStorage(storage);
    LOG("First robot loaded");
    myRobot_.printDebug();
    in >> target >> eta >> score >> storage.A >> storage.B >> storage.C >> storage.D >> storage.E >> expertiseA >> expertiseB >> expertiseC >> expertiseD >> expertiseE; in.ignore();
    LOG("Second robot loaded");
    LOG(storage);
    in >> storage.A >> storage.B >> storage.C >> storage.D >> storage.E; in.ignore();
    LOG("Some strange shit loaded ");
    LOG(storage);
    int sampleCount;
    in >> sampleCount; in.ignore();
    LOG("Sample count: "+std::to_string(sampleCount));
    for (int i = 0; i < sampleCount; i++) {
        Sample newSample;
        int sampleId;
        int carriedBy;
        int rank;
        std::string expertiseGain;
        int health;
        int costA;
        int costB;
        int costC;
        int costD;
        int costE;
        in >> sampleId >> carriedBy >> rank >> expertiseGain >> health >> costA >> costB >> costC >> costD >> costE; in.ignore();
        newSample.setId(sampleId);
        newSample.setCarriedBy(carriedBy);
        newSample.setHealth(health);
        newSample.setCost({costA, costB, costC, costD, costE});
        samples_.insert(newSample);
    }
}

Robot GameController::getRobot()
{
    return myRobot_;
}

SamplesSet GameController::getSamples()
{
    return samples_;
}

void GameController::fullDebugPrint()
{
    myRobot_.printDebug();
    for (const auto& sample : samples_)
    {
        sample.printDebug();
    }
}
#include "gtest.h"
#include "gmock.h"

#include "Robot.hpp"

#include <fstream>



class RobotShould: public testing::Test
{
public:
    Robot sut_;
};


TEST_F(RobotShould, returnTrueIfHasEnoughMolecules)
{
    Molecules robotStorage = {0, 3, 0, 4, 0};
    Molecules requiredMolecules = {0, 3, 0, 3, 0};
    sut_.setStorage(robotStorage);
    EXPECT_TRUE(sut_.hasEnoughMolecules(requiredMolecules));
}

TEST_F(RobotShould, returnFalseIfDoesntHaveEnoughMolecules)
{
    Molecules robotStorage = {0, 3, 0, 4, 0};
    Molecules requiredMolecules = {0, 3, 0, 3, 1};
    sut_.setStorage(robotStorage);
    EXPECT_FALSE(sut_.hasEnoughMolecules(requiredMolecules));
}

TEST_F(RobotShould, returnCorrectNeededMoleculeName)
{
    Molecules robotStorage = {0, 3, 0, 4, 0};
    Molecules requiredMolecules = {0, 3, 0, 3, 1};
    sut_.setStorage(robotStorage);
    EXPECT_EQ("E", sut_.getNeededMoleculeName(requiredMolecules));
    requiredMolecules = {0, 4, 0, 3, 0};
    EXPECT_EQ("B", sut_.getNeededMoleculeName(requiredMolecules));
    requiredMolecules = {1, 3, 0, 4, 0};
    EXPECT_EQ("A", sut_.getNeededMoleculeName(requiredMolecules));
    requiredMolecules = {0, 3, 1, 4, 1};
    EXPECT_TRUE("C" == sut_.getNeededMoleculeName(requiredMolecules)
        || "E" == sut_.getNeededMoleculeName(requiredMolecules));
}

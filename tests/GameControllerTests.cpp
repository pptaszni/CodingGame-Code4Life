#include "gtest.h"
#include "gmock.h"

#include "GameController.hpp"

#include <fstream>

TEST(SampleTest, shouldPass)
{
    ASSERT_EQ(0,0);
}

class GameControllerShould: public testing::Test
{
public:
    GameController sut_;
};


TEST_F(GameControllerShould, loadCorectData)
{
    std::ifstream ifs;
    Robot expectedRobot;
    Sample expectedSample;

    expectedRobot.setTarget("DIAGNOSIS");
    expectedRobot.setStorage({1, 2, 3, 4, 5});
    expectedSample.setId(3);
    expectedSample.setCarriedBy(-1);
    expectedSample.setHealth(4);
    expectedSample.setCost({2, 2, 2, 2, 2});

    ifs.open(
        "data/initialData.dat",
        std::ifstream::in);
    sut_.loadGameData(ifs, true);
    ifs.close();

    EXPECT_EQ(sut_.getRobot(), expectedRobot);
    EXPECT_FALSE(*(sut_.getSamples().begin()) < expectedSample);
    EXPECT_FALSE(expectedSample < *(sut_.getSamples().begin()));
    EXPECT_EQ(expectedSample.getCost(), sut_.getSamples().begin()->getCost());
}

TEST_F(GameControllerShould, replaceModifiedSampleWithNextDataIteration)
{
    std::ifstream ifs;

    Sample expectedSample;

    expectedSample.setId(3);
    expectedSample.setCarriedBy(1);
    expectedSample.setHealth(4);
    expectedSample.setCost({2, 2, 2, 2, 2});

    ifs.open(
        "data/doubleData.dat",
        std::ifstream::in);
    sut_.loadGameData(ifs, true);
    sut_.loadGameData(ifs);
    ifs.close();

    EXPECT_FALSE(*(sut_.getSamples().rbegin()) < expectedSample);
    EXPECT_FALSE(expectedSample < *(sut_.getSamples().rbegin()));
    EXPECT_EQ(expectedSample.getCost(), sut_.getSamples().rbegin()->getCost());
}
#include "ShorSimulator.hpp"

#include <gtest/gtest.h>
#include <memory>

/**
 * These tests may have to be adjusted if something about the random-number generation changes.
 */

TEST(ShorSimTest, Factorize15EmulationTest) {
    ShorSimulator ddsim(15, 2, 3ull, true, true);

    ASSERT_EQ(ddsim.getNumberOfOps(), 0);
    ASSERT_EQ(ddsim.getName(), "shor_15_2");
    ASSERT_EQ(ddsim.getFactors().first, 0);
    ASSERT_EQ(ddsim.getFactors().second, 0);
    ASSERT_EQ(ddsim.AdditionalStatistics().at("sim_result"), "did not start");
    ddsim.Simulate(1);

    ASSERT_EQ(ddsim.getFactors().first, 3);
    ASSERT_EQ(ddsim.getFactors().second, 5);
    ASSERT_EQ(ddsim.AdditionalStatistics().at("sim_result"), "SUCCESS(3*5)");

    ASSERT_EQ(ddsim.AdditionalStatistics().at("polr_factor1"), "3");
    ASSERT_EQ(ddsim.AdditionalStatistics().at("polr_factor2"), "5");
    ASSERT_EQ(ddsim.AdditionalStatistics().at("polr_result"), "SUCCESS(3*5)");
}

TEST(ShorSimTest, Factorize15NegTest) {
    ShorSimulator ddsim(15, 2, 1ull);
    ddsim.Simulate(1);

    ASSERT_EQ(ddsim.getFactors().first, 0);
    ASSERT_EQ(ddsim.getFactors().second, 0);
    ASSERT_EQ(ddsim.AdditionalStatistics().at("sim_result"), "FAILURE");


    ASSERT_EQ(ddsim.AdditionalStatistics().at("polr_factor1"), "3");
    ASSERT_EQ(ddsim.AdditionalStatistics().at("polr_factor2"), "5");
    ASSERT_EQ(ddsim.AdditionalStatistics().at("polr_result"), "SUCCESS(3*5)");
}

TEST(ShorSimTest, Factorize15WithoutEmulationTest) {
    ShorSimulator ddsim(15, 2, 1ull, false);
    ddsim.Simulate(1);

    ASSERT_EQ(ddsim.getFactors().first, 3);
    ASSERT_EQ(ddsim.getFactors().second, 5);
}



TEST(ShorSimTest, Factorize55Test) {
    ShorSimulator ddsim(55, 2, 3ull);
    ddsim.Simulate(1);

    ASSERT_EQ(ddsim.getFactors().first, 11);
    ASSERT_EQ(ddsim.getFactors().second, 5);
}
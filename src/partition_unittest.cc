// Copyright 2018, Allan Knight.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Allan Knight nor the names of other
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A unit tester for EX05-String in CS140 at Santa Barbara City College.
//
// Author: ahknight@pipeline.sbcc.edu (Allan Knight)


// Includes for google test and the unit under test.

#include <climits>
#include <iostream>

#include <vector>
#include "algorithm.h"

#include "gtest/gtest.h"
#include "GTestNoDeath.h"

namespace {

using std::string;

using namespace ::testing_internal;

class PartitionFixture : public ::testing::Test {
protected:
    static const uint MAX_TESTED_SCORE = 10;
    static const uint MAX_OVERALL_SCORE = 10;
    static uint _testScore;

protected:
    static void TearDownTestCase() {
        if (_testScore == MAX_TESTED_SCORE) {
            std::cout << std::endl << "Your unit test score is "
                      << _testScore << " out of "
                      << MAX_TESTED_SCORE << std::endl;
        } else {
            std::cout << "Your unit test score is "
                      << _testScore << " out of "
                      << MAX_TESTED_SCORE << " ("<< (int)(_testScore - MAX_TESTED_SCORE)
                      << ")" << std::endl;
        }

        std::cout << "The assignment is worth a total of " << MAX_OVERALL_SCORE
                  << " where the remaining points" << std::endl;
        std::cout << "comes from grading related to documentation, algorithms, and other"
                  << std::endl;
        std::cout << "criteria." << std::endl << std::endl;
    }
};

uint PartitionFixture::_testScore = 0;

using std::vector;

TEST_F(PartitionFixture, TestReverseOrderedVector) {
    vector<int> ints{10, 9, 8, 7 , 6, 5, 4, 3, 2, 1};
    auto pivot = edu::vcccd::vc::csv15::partition(ints.begin(), ints.end(), 6);
    ASSERT_TRUE(std::is_partitioned(ints.begin(), ints.end(), [&] (int v) -> bool { return v <= 6; }));
    ASSERT_EQ(5, std::distance(ints.begin(), pivot));
    _testScore += 1;
}

TEST_F(PartitionFixture, TestForwardOrderedVector) {
    vector<int> ints{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto pivot = edu::vcccd::vc::csv15::partition(ints.begin(), ints.end(), 4);
    ASSERT_TRUE(std::is_partitioned(ints.begin(), ints.end(), [&] (int v) -> bool { return v <= 4; }));
    ASSERT_EQ(3, std::distance(ints.begin(), pivot));
    _testScore += 1;
}

TEST_F(PartitionFixture, TestEmptyVector) {
    vector<int> ints{};
    auto pivot = edu::vcccd::vc::csv15::partition(ints.begin(), ints.end(), 4);
    ASSERT_TRUE(std::is_partitioned(ints.begin(), ints.end(), [&] (int v) -> bool { return v <= 4; }));
    ASSERT_EQ(0, std::distance(ints.begin(), pivot));
    _testScore += 2;
}

TEST_F(PartitionFixture, TestPivotLower) {
    vector<int> ints{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto pivot = edu::vcccd::vc::csv15::partition(ints.begin(), ints.end(), 0);
    ASSERT_TRUE(std::is_partitioned(ints.begin(), ints.end(), [&] (int v) -> bool { return v <= 0; }));
    ASSERT_EQ(0, std::distance(ints.begin(), pivot));
    _testScore += 2;
}

TEST_F(PartitionFixture, TestPivotHigher) {
    vector<int> ints{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto pivot = edu::vcccd::vc::csv15::partition(ints.begin(), ints.end(), 11);
    ASSERT_TRUE(std::is_partitioned(ints.begin(), ints.end(), [&] (int v) -> bool { return v <= 11; }));
    ASSERT_EQ(0, std::distance(--ints.end(), pivot));
    _testScore += 2;
}

TEST_F(PartitionFixture, TestPivotNotInContainer) {
    vector<int> ints{1, 2, 3, 4, 5, 7, 8, 9, 10};
    auto pivot = edu::vcccd::vc::csv15::partition(ints.begin(), ints.end(), 6);
    ASSERT_TRUE(std::is_partitioned(ints.begin(), ints.end(), [&] (int v) -> bool { return v <= 6; }));
    ASSERT_EQ(4, std::distance(ints.begin(), pivot));
    _testScore += 2;
}

}

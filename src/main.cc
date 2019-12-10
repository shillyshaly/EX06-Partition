//
// Created by aknight on 10/7/19.
//

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

#include "algorithm.h"

int main(int argc, char *argv[]) {
    std::vector<int> ints{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    auto pivot = edu::vcccd::vc::csv15::partition(ints.begin(), ints.end(), 5);
    for (int val: ints) {
        std::cout << val << std::endl;
    }

    if (std::is_partitioned(ints.begin(), ints.end(), [&] (int v) -> bool { return v <= 5; })) {
        std::cout << "partitioned" << std::endl;
    } else {
        std::cout << "non-partitioned" << std::endl;
    }

    return EXIT_SUCCESS;
}
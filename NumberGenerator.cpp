//
// Created by Mackem Meya on 08.02.2022.
//

#include <random>

#include "NumberGenerator.h"

size_t NumberGenerator::generate(size_t from, size_t to) {
    if (from > to) {
        std::swap(from, to);
    }

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(from, to);

    return distribution(generator);
}

//
// Created by Mackem Meya on 15.02.2022.
//

#include "ArrayGenerator.h"
#include "NumberGenerator.h"

Array<size_t> ArrayGenerator::generate(size_t from, size_t to, size_t size) {
    Array<size_t> result{ size, 0 };

    NumberGenerator numberGenerator{ };
    for (size_t i{ 0 }; i < size; ++i) {
        result(i) = numberGenerator.generate(from, to);
    }

    return result;
}

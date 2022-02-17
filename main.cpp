#include <iostream>
#include <unordered_set>

#include "MergeSorter.h"
#include "NumberGenerator.h"
#include "ArrayGenerator.h"
#include "Array.h"
#include "Exceptions/InvalidArgumentException.h"

Array<Array<size_t>>
generateArrays(size_t numberOfArrays, size_t sizeFrom, size_t sizeTo, size_t valueFrom, size_t valueTo);

int main(int argc, char **argv) {
    if (argc != 6) {
        std::cerr << "Invalid arguments. Usage: \"" << argv[0] << "\" numberOfArrays sizeFrom sizeTo valueFrom valueTo"
                  << std::endl;
        return 1;
    }

    size_t numberOfArrays{ (size_t) std::atol(argv[1]) };
    size_t sizeFrom{ (size_t) std::atol(argv[2]) };
    size_t sizeTo{ (size_t) std::atol(argv[3]) };
    size_t valueFrom{ (size_t) std::atol(argv[4]) };
    size_t valueTo{ (size_t) std::atol(argv[5]) };

    try {
        auto result{ generateArrays(numberOfArrays, sizeFrom, sizeTo, valueFrom, valueTo) };

        for (size_t i{ 0 }; i < numberOfArrays; ++i) {
            std::cout << result(i) << std::endl;
        }
    } catch (InvalidArgumentException &e) {
        std::cerr << e.what() << std::endl;
    } catch (MemoryNotAllocatedException &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

Array<Array<size_t>>
generateArrays(size_t numberOfArrays, size_t sizeFrom, size_t sizeTo, size_t valueFrom, size_t valueTo) {
    if (sizeTo - sizeFrom + 1 < numberOfArrays) {
        throw InvalidArgumentException{ "Invalid numberOfArrays. The value must be >= (sizeTo - sizeFrom + 1)" };
    }

    NumberGenerator numberGenerator{ };
    ArrayGenerator arrayGenerator{ };
    MergeSorter<size_t> mergeSorter{ };

    Array<Array<size_t>> result{ numberOfArrays, Array<size_t>{ } };
    std::unordered_set<size_t> randomSizes{ };

    for (size_t i{ 0 }; i < numberOfArrays; ++i) {
        size_t size{ numberGenerator.generate(sizeFrom, sizeTo) };
        while (randomSizes.find(size) != randomSizes.end()) {
            size = numberGenerator.generate(sizeFrom, sizeTo);
        }
        randomSizes.insert(size);
        result(i) = arrayGenerator.generate(valueFrom, valueTo, size);

        if (i % 2 == 1) {
            mergeSorter.sort(*result(i), result(i).getSize(), [](size_t a, size_t b) {
                return a <= b;
            });
        } else {
            mergeSorter.sort(*result(i), result(i).getSize(), [](size_t a, size_t b) {
                return a >= b;
            });
        }
    }

    return result;
}

//
// Created by Mackem Meya on 15.02.2022.
//

#ifndef ARRAYGENERATOR_H
#define ARRAYGENERATOR_H

#include <iostream>

#include "IGenerator.h"
#include "Array.h"

class ArrayGenerator : public IGenerator<Array<size_t>, size_t> {
public:
    Array<size_t> generate(size_t from, size_t to, size_t size) override;
};

#endif //ARRAYGENERATOR_H

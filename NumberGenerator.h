//
// Created by Mackem Meya on 08.02.2022.
//

#ifndef NUMBERGENERATOR_H
#define NUMBERGENERATOR_H

#include <iostream>

#include "IGenerator.h"

class NumberGenerator : public IGenerator<size_t> {
public:
    size_t generate(size_t from, size_t to) override;
};

#endif //NUMBERGENERATOR_H

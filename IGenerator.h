//
// Created by Mackem Meya on 15.02.2022.
//

#ifndef GENERATOR_H
#define GENERATOR_H

template<typename T, typename... Arguments>
class IGenerator {
    virtual T generate(size_t from, size_t to, Arguments... arguments) = 0;
};

#endif //GENERATOR_H

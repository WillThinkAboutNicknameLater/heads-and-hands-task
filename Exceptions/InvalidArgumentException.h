//
// Created by Mackem Meya on 16.02.2022.
//

#ifndef INVALIDARGUMENTEXCEPTION_H
#define INVALIDARGUMENTEXCEPTION_H

#include "BaseException.h"

class InvalidArgumentException : public BaseException {
public:
    explicit InvalidArgumentException(const std::string &message) : BaseException{ message } { }
};

#endif //INVALIDARGUMENTEXCEPTION_H

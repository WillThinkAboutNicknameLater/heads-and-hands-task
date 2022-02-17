//
// Created by Mackem Meya on 16.02.2022.
//

#ifndef MEMORYNOTALLOCATEDEXCEPTION_H
#define MEMORYNOTALLOCATEDEXCEPTION_H

#include "BaseException.h"

class MemoryNotAllocatedException : public BaseException {
public:
    explicit MemoryNotAllocatedException(const std::string &message) : BaseException{ message } { }
};

#endif //MEMORYNOTALLOCATEDEXCEPTION_H

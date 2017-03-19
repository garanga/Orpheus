//-------------------------------------------------------
// Created on: Mar 18, 2017
//
// Author: Mikhail A. Volkov
// E-mail: Volkovmikhl@gmail.com
//-------------------------------------------------------

#include "exceptions.h"
#include "SymbolicConstants.hpp"
#include <iostream>

OrpheusException::Exception::Exception(OrpheusConstants::ExceptionType type   ,
                                                           std::string message):
    mType(type),
    mMessage(message)
{
}

const char* OrpheusException::Exception::what() const noexcept
{
    return mMessage.c_str();
}

void OrpheusException::Exception::print() const noexcept
{
    std::cout << mMessage << std::endl;
}

OrpheusConstants::ExceptionType OrpheusException::Exception::getType() const
{
    return mType;
}

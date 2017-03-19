//-------------------------------------------------------
// Created on: Mar 18, 2017
//
// Author: Mikhail A. Volkov
// E-mail: Volkovmikhl@gmail.com
//-------------------------------------------------------

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <string>
#include <exception>

namespace OrpheusConstants
{
    enum class ExceptionType;
}
namespace OrpheusException
{
    class Exception;
};

class OrpheusException::Exception : public std::exception
{
public:
    explicit Exception(OrpheusConstants::ExceptionType, std::string);

    const char* what() const noexcept final;
    void       print() const noexcept;

    OrpheusConstants::ExceptionType getType() const;

private:
    OrpheusConstants::ExceptionType mType;
    std::string   mMessage;
};


#endif /* EXCEPTIONS_H_ */

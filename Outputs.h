//---------------------------------------------------------------------------
// Created on: 05.03.2017.
// Author: Mikhail A. Volkov
// E-mail: Volkovmikhl@gmail.com
//---------------------------------------------------------------------------

#ifndef OUTPUTS_H_
#define OUTPUTS_H_

#include <map>
#include <vector>

namespace OrpheusConstants
{
    enum class OutputSymbols;
}

inline bool operator <  (OrpheusConstants::OutputSymbols& ,
                         OrpheusConstants::OutputSymbols&);

inline bool operator == (OrpheusConstants::OutputSymbols& ,
                         OrpheusConstants::OutputSymbols&);

class FieldOutput
{
public:
    explicit FieldOutput() {}
    ~FieldOutput() {}


    std::map<OrpheusConstants::OutputSymbols, std::vector<double> > data;
};

class ScalarOutput
{
public:
    std::map<::OrpheusConstants::OutputSymbols, std::vector<double> > data;

    explicit ScalarOutput() {}
    ~ScalarOutput() {}

};

#endif /* OUTPUTS_H_ */

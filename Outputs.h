//---------------------------------------------------------------------------
// Created on: 05.03.2017.
// Author: Mikhail A. Volkov
// E-mail: Volkovmikhl@gmail.com
//---------------------------------------------------------------------------

#ifndef OUTPUTS_H_
#define OUTPUTS_H_

#include <map>
#include <vector>

enum class OutputSymbols;

inline bool operator <  (OutputSymbols&, OutputSymbols&);
inline bool operator == (OutputSymbols&, OutputSymbols&);

class FieldOutput
{
public:
    explicit FieldOutput() {}
    ~FieldOutput() {}


    std::map<OutputSymbols, std::vector<double> > data;
};

class ScalarOutput
{
public:
    std::map<OutputSymbols, std::vector<double> > data;

    explicit ScalarOutput() {}
    ~ScalarOutput() {}

};

#endif /* OUTPUTS_H_ */

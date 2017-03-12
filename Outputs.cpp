//---------------------------------------------------------------------------
// Created on: 05.03.2017.
// Author: Mikhail A. Volkov
// E-mail: Volkovmikhl@gmail.com
//---------------------------------------------------------------------------

#include "Outputs.h"

//---Operator overloading for OutputSymbols-----------------------------------
inline bool operator < (OutputSymbols& lhv, OutputSymbols& rhv)
{
    return (int)lhv < (int)rhv;
}

inline bool operator == (OutputSymbols& lhv, OutputSymbols& rhv)
{
    return (int)lhv == (int)rhv;
}
//----------------------------------------------------------------------------

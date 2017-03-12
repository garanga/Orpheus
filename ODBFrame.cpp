//---------------------------------------------------------------------------
// Created on: 04.03.2017.
// Author: Mikhail A. Volkov
// E-mail: Volkovmikhl@gmail.com
//---------------------------------------------------------------------------

#include "includes.hpp"

ODBFrame::ODBFrame()
{

}


ODBFrame::~ODBFrame()
{

}

void ODBFrame::setFieldOutput(FieldOutput& fields)
{
    mFields = fields;
}

ScalarOutput& ODBFrame::getScalarOutput()
{
    return mScalars;
}

FieldOutput& ODBFrame::getFieldOutput()
{
    return mFields;
}

void ODBFrame::fileStreamWrite(std::ofstream& fout, int dim)
{
    for (auto it  = mScalars.data.begin();
              it != mScalars.data.end()  ; ++it)
    {
        int scalar_type = static_cast<int>(it->first);
        fout << scalar_type << "\n";
        switch (scalar_type)
        {
        case (int)OutputSymbols::T :
        {
            for (unsigned int i = 0; i < it->second.size(); ++i)
                fout << it->second.at(i) << std::endl;
            break;
        }
        }
    }

    for (auto it  = mFields.data.begin();
              it != mFields.data.end()  ; ++it)
    {
        int field_type = static_cast<int>(it->first);
        fout << field_type << "\n";
        switch (field_type)
        {
        case (int)OutputSymbols::U :
        {
            for (unsigned int i = 0; i < it->second.size(); i += dim)
            {
                for (int j = 0; j < dim; ++j)
                {
                    fout << it->second.at(i + j);
                    if (j != dim - 1)
                        fout << " ";
                }
                fout << std::endl;

            }
            break;
        }
        case (int)OutputSymbols::S :
        case (int)OutputSymbols::E :
        {

            int limit = 1;
            if (dim == 2)
                limit = 3;
            else if (dim == 3)
                limit = 6;

            for (unsigned int i = 0; i < it->second.size(); i += limit)
            {
                for (int j = 0; j < limit; ++j)
                {
                    fout << it->second.at(i + j);
                    if (j != limit - 1)
                        fout << " ";
                }
                fout << std::endl;
            }
            break;
        }
        }
    }

    fout << (int)OutputSymbols::OUTPUTEND << std::endl;

}

void ODBFrame::printData(int dim)
{
    std::cout << "data size: " << mFields.data.size() << std::endl;
    std::cout << "end first: " << (int)mFields.data.end()->first << std::endl;
    for(auto it = mFields.data.begin(); it != mFields.data.end(); ++it)
    {
        std::cout << "Data type: " << (int)it->first << std::endl;
        switch ((int)it->first)
        {
        case (int)OutputSymbols::U :
        {
            auto iter  = it->second.begin();

            while (iter != it->second.end())
            {
                for (int i = 0; i < dim; ++i, ++iter)
                    std::cout<< (*iter) << " ";
                std::cout << std::endl;
            }
            break;
        }
        case (int)OutputSymbols::S :
        {
            int limit = 1;
            if (dim == 2)
                limit = 3;
            else if(dim == 3)
                limit = 6;

            auto iter  = it->second.begin();

            while (iter != it->second.end())
            {
                for (int i = 0; i < limit; ++i, ++iter)
                    std::cout<< (*iter) << " ";
                std::cout << std::endl;
            }
            break;
        }
        default:
        {
            std::cout << "Wrong Code: " << (int)it->first << std::endl;
            if (it == mFields.data.end())
                std::cout << "Real end\n";
            break;
        }
        }
    }

}

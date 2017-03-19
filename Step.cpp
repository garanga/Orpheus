/*
 * Step.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: pavel
 */

#include "Step.hpp"
#include "includes.hpp"

#include <vector>

Step::Step(std::string mName_)
    : mName(mName_)
{

}

Step::~Step()
{

}

void Step::addOutputRequest(enums::OutputSymbols fieldType)
{
    mOutputRequest.push_back(fieldType);
}

void Step::addOutputRequest(std::vector<enums::OutputSymbols> fieldTypes)
{
    mOutputRequest.insert(mOutputRequest.end(), fieldTypes.begin(),
                              fieldTypes.end());
}

std::string Step::getName() const
{
    return mName;
}

std::vector<enums::OutputSymbols> Step::getOutputRequest() const
{
    return mOutputRequest;
}



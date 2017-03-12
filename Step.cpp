/*
 * Step.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: pavel
 */

#include "Step.hpp"

#include <vector>

Step::Step(std::string mName_)
    : mName(mName_)
{

}

Step::~Step()
{

}

void Step::addOutputRequest(OutputSymbols fieldType)
{
    mOutputRequest.push_back(fieldType);
}

void Step::addOutputRequest(std::vector<OutputSymbols> fieldTypes)
{
    mOutputRequest.insert(mOutputRequest.end(), fieldTypes.begin(),
                              fieldTypes.end());
}

std::string Step::getName() const
{
    return mName;
}

std::vector<OutputSymbols> Step::getOutputRequest() const
{
    return mOutputRequest;
}



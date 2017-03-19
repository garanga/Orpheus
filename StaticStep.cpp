/*
 * StaticStep.cpp
 *
 *  Created on: Jan 27, 2017
 *      Author: pavel
 */

#include "StaticStep.hpp"

#include "includes.hpp"
#include <string>


StaticStep::StaticStep(std::string myName,
                       double myTimeBegin,
                       double myTimeEnd,
                       double myTimeIncrement,
                       double myLoadFactorBegin,
                       double myLoadFactorEnd)
    : Step(myName),
      timeBegin(myTimeBegin),
      timeEnd(myTimeEnd),
      timeIncrement(myTimeIncrement),
      loadFactorBegin(myLoadFactorBegin),
      loadFactorEnd(myLoadFactorEnd)
{

}

StaticStep::~StaticStep()
{
    for (auto it = loads.begin(); it != loads.end(); ++it)
        delete *it;
    for (auto it = constraints.begin(); it != constraints.end(); ++it)
        delete *it;
}

void StaticStep::CopyConstraints(StaticStep& step)
{
    Constraint *tmp;
    for (auto it  = step.constraints.begin();
              it != step.constraints.end(); ++it)
    {
        tmp = new Constraint(*(*it));
        constraints.push_back(tmp);
    }
    tmp = nullptr;
}

void StaticStep::CopyLoads(StaticStep& step)
{
    Load *tmp;
    for (auto it  = step.loads.begin();
              it != step.loads.end(); ++it)
    {
        tmp = new Load(*(*it));
        loads.push_back(tmp);
    }
    tmp = nullptr;
}

DisplacementConstraint*
StaticStep::CreateDisplacementConstraint(std::string myName               ,
                                         std::vector<int> myRegion        ,
                       OrpheusConstants::DisplacementConstraintType myType,
                                         double* myValue                  )
{
    auto displacementConstraint = new DisplacementConstraint(myName  ,
                                                             myRegion,
                                                             myType  ,
                                                             myValue );
    constraints.push_back(displacementConstraint);
    return displacementConstraint;
}

ConcentratedLoad*
StaticStep::CreateConcentratedLoad(std::string myName         ,
                                   std::vector<int> myRegion  ,
                 OrpheusConstants::ConcentratedLoadType myType,
                                   double* myValue            )
{
    auto concentratedLoad = new ConcentratedLoad(myName, myRegion,
                                                 myType, myValue );
    loads.push_back(concentratedLoad);
    return concentratedLoad;
}

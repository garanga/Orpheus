/*
 * StaticStep.hpp
 *
 *  Created on: Jan 27, 2017
 *      Author: pavel
 */

#ifndef STATICSTEP_HPP_
#define STATICSTEP_HPP_


#include "Step.hpp"
#include <string>
#include <vector>

class Constraint;
class DisplacementConstraint;
class Load;
class ConcentratedLoad;

namespace OrpheusConstants
{
    enum class DisplacementConstraintType;
    enum class ConcentratedLoadType;
}

class StaticStep  : public Step
{
public:
    double timeBegin;
    double timeEnd;
    double timeIncrement;
    double loadFactorBegin;
    double loadFactorEnd;

    std::vector<Constraint*> constraints;
    std::vector<Load*>       loads;

    // Specialized constructor
    StaticStep(std::string myName,
               double myTimeBegin,
               double myTimeEnd,
               double myTimeIncrement,
               double myLoadFactorBegin,
               double myLoadFactorEnd);
    ~StaticStep();

    void CopyConstraints(StaticStep&);
    void CopyLoads(StaticStep&);

    // A method creating a DisplacementConstraint object
    DisplacementConstraint*
    CreateDisplacementConstraint(std::string                                 ,
                                 std::vector<int>                            ,
                                 OrpheusConstants::DisplacementConstraintType,
                                 double*                                     );

    // A method creating a ConcentratedLoad object
    ConcentratedLoad*
    CreateConcentratedLoad(std::string                           ,
                           std::vector<int>                      ,
                           OrpheusConstants::ConcentratedLoadType,
                           double*                               );
};


#endif /* STATICSTEP_HPP_ */

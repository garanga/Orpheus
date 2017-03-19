/*
 * Constraint.hpp
 *
 *  Created on: Feb 1, 2017
 *      Author: pavel
 */

#ifndef CONSTRAINT_HPP_
#define CONSTRAINT_HPP_


#include <iostream>
#include <vector>

class Job;
namespace OrpheusConstants
{
    enum class DisplacementConstraintType;
};

class Constraint
{
public:
    Constraint(std::string myName                                 ,
               std::vector<int> myRegion                          ,
               OrpheusConstants::DisplacementConstraintType myType,
               double* myValue                                    );

    Constraint(const Constraint&);

    virtual ~Constraint();

    OrpheusConstants::DisplacementConstraintType type;
    std::vector<int>                             region;
    double*                                      value; // Array

    friend class Job;

private:
    std::string mName;
};



#endif /* CONSTRAINT_HPP_ */

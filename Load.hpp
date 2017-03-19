/*
 * Load.hpp
 *
 *  Created on: Feb 3, 2017
 *      Author: pavel
 */

#ifndef LOAD_HPP_
#define LOAD_HPP_

#include <iostream>
#include <vector>

class Job;
namespace OrpheusConstants
{
    enum class ConcentratedLoadType;
}

class Load
{
public:
    Load(std::string                            myName  ,
         std::vector<int>                       myRegion,
         OrpheusConstants::ConcentratedLoadType myType  ,
         double*                                myValue );
    Load(const Load&);
    virtual ~Load();


    std::vector<int>                       region;
    OrpheusConstants::ConcentratedLoadType type;
    double*                                value; // Array
    friend class Job;

private:
    std::string mName;
};



#endif /* LOAD_HPP_ */

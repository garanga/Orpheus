/*
 * Isotropic.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: pavel
 */

#include "Isotropic.hpp"

#include <iostream>
#include <string>


Isotropic::Isotropic(std::string name, double young, double poisson)
    : Material(name),
      mYoung(young), mPoisson(poisson)
{
    std::cout << "The isotropic material '" << name << "' is created" << std::endl;
}

Isotropic::~Isotropic()
{

}

double Isotropic::getYoung() const
{
    return mYoung;
}

double Isotropic::getPoisson() const
{
    return mPoisson;
}

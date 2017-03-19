/*
 * Material.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: pavel
 */

#include "Material.hpp"

#include <string>


Material::Material(std::string name) :
        mName(name)
{

}

Material::~Material()
{

}

std::string
Material::getName() const
{
    return mName;
}

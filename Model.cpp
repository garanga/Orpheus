/*
 * Model.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: pavel
 */

#include "Model.hpp"

#include "includes.hpp"

#include <iostream>

Model::Model(std::string name)
    : mName(name)
{

    std::cout << "The model '" << mName << "' is created" << std::endl;

    // Creating an initial step
//    Step* step = new InitialStep("Initial");
//    steps.push_back(step);

}

Model::~Model()
{
    for (auto it = bodies.begin(); it < bodies.end(); ++it)
        delete *it;

    for (auto it = parts.begin(); it < parts.end(); ++it)
        delete *it;

    for (auto it = materials.begin(); it < materials.end(); ++it)
        delete *it;

    for (auto it = steps.begin(); it < steps.end(); ++it)
        delete *it;
}

std::string Model::getName() const
{
    return mName;
}

Body* Model::getBody(std::string name)
{
    auto it = std::find_if(bodies.begin(),bodies.end(),[&name](Body* body)
              {
                     return body->getName() == name;
              });
    return *it;
}

Part* Model::getPart(std::string name)
{
    auto it = std::find_if(parts.begin(),parts.end(),[&name](Part* part)
              {
                     return part->getName() == name;
              });
    return *it;
}

Material* Model::getMaterial(std::string name)
{
    auto it = std::find_if(materials.begin(),materials.end(),
            [&name](Material* material)
              {
                     return material->getName() == name;
              });
    return *it;
}

StaticStep* Model::getStaticStep(std::string name)
{
    auto it = std::find_if(steps.begin(),steps.end(),
            [&name](StaticStep* step)
              {
                     return step->getName() == name;
              });
    return *it;
}

Body* Model::createBody(std::string name)
{
    Body* body = new Body(name);
    bodies.push_back(body);
    return body;
}

Part* Model::createPart(std::string name)
{
    Part* part = new Part(name);
    parts.push_back(part);
    return part;
}

Material* Model::createIsotropic(std::string name, double young, double poisson)
{
    Isotropic* material = new Isotropic(name, young, poisson);
    materials.push_back(material);
    return material;
}

void Model::setPartMaterial(std::string partName, std::string materialName)
{
    auto itPart  = std::find_if(parts.begin(), parts.end(),
                   [&partName](Part* part)
                   {
                       return part->getName() == partName;
                   });

    auto itMater = std::find_if(materials.begin(), materials.end(),
                  [&materialName](Material* material)
                  {
                      return material->getName() == materialName;
                  });
    bool condMater = itMater == materials.end();
    bool condPart  = itPart  == parts.end();

    if (condMater and condPart)
        (*itPart)->setMaterial((*itMater));
    else
    {
        // Exception NOTFOUND
    }

}

StaticStep* Model::createStaticStep(std::string name,
                                    double timeBegin,
                                    double timeEnd,
                                    double timeIncrement,
                                    double loadFactorBegin,
                                    double loadFactorEnd)
{
    StaticStep* step = new StaticStep(name, timeBegin, timeEnd, timeIncrement, loadFactorBegin, loadFactorEnd);
    steps.push_back(step);
    return step;
}

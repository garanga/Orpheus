/*
 * Model.hpp
 *
 *  Created on: Jan 17, 2017
 *      Author: pavel
 */

#ifndef MODEL_HPP_
#define MODEL_HPP_

#include <string>
#include <vector>

class Body;
class Part;
class Material;
class ElementType;
class Mesh;
class StaticStep;

class Model
{
public:

    std::vector <Body*>       bodies;
    std::vector <Part*>       parts;
    std::vector <Material*>   materials;
    std::vector <StaticStep*> steps;

    //! Specialized constructor
    Model(std::string name);
   ~Model();

    std::string getName() const;
    Body*       getBody(std::string);
    Part*       getPart(std::string);
    Material*   getMaterial(std::string);
    StaticStep* getStaticStep(std::string);


    Body*     createBody(std::string name); //! A method for creating a Body object
    Part*     createPart(std::string name); //! A method for creating a Part object
    Material* createIsotropic(std::string name, double young, double poisson); //! A method for creating a Material object

    void setPartMaterial(std::string, std::string);

    StaticStep* createStaticStep(std::string name, //! A method for creating a StaticStep object
                                 double timeBegin,
                                 double timeEnd,
                                 double timeIncrement,
                                 double loadFactorBegin,
                                 double loadFactorEnd);
private:
    std::string mName;

};

#endif /* MODEL_HPP_ */

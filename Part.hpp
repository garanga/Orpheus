/*
 * Part.hpp
 *
 *  Created on: Jan 17, 2017
 *      Author: pavel
 */

#ifndef PART_HPP_
#define PART_HPP_


#include <string>
#include <vector>

class Material;
class ElementType;
struct Mesh;

namespace OrpheusConstants
{
    enum class ElementTypeEnum;
};


class Part
{
public:

    Part(std::string name);
    ~Part();

    void setSizes(double* sizes);
    void setDivisions(int* divisions);
    void setMaterial(Material*);
    void setElementType(OrpheusConstants::ElementTypeEnum, bool = false);

    // A method creating a mesh on part
    void CreateMesh(bool = true);
    void CreateMesh(ElementType* type, bool writeMesh = true);

    std::string  getName() const;
    double*      getSizes() const;
    int*         getDivisions() const;

    Mesh* mesh;

private:
    std::string  mName;
    Material*    mMaterial;
    ElementType* mElementType;
    double*      mSizes;
    int*         mDivisions;

};

#endif /* PART_HPP_ */

/*
 * Part.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: pavel
 */

#include "Part.hpp"

#include "includes.hpp"

#include <iostream>
#include <fstream>

//! A test class
/*!
 *
 * A more detailed description
 *
 */

Part::Part(std::string name)
    : mName(name)
{
    std::cout << "The part '" << name << "' is created" << std::endl;
    mesh         = nullptr;
    mDivisions   = nullptr;
    mSizes       = nullptr;
    mMaterial    = nullptr;
    mElementType = nullptr;
}

Part::~Part()
{
    if (mesh != nullptr)
        delete mesh;
    if (mElementType != nullptr)
        delete mElementType;
    if (mSizes != nullptr)
        delete [] mSizes;
    if (mDivisions != nullptr)
        delete [] mDivisions;
}

void Part::setSizes(double* sizes)
{
    mSizes = sizes;
    std::cout << "!!!!!! Part::setSizes" << std::endl;
}

void Part::setDivisions(int* divisions)
{
    mDivisions = divisions;
    std::cout << "!!!!!! Part::setDivisions" << std::endl;
}

void Part::setMaterial(Material* _material)
{
    mMaterial = _material;
}

void Part::setElementType(ElementTypeEnum _type, bool isPlaneStrain)
{
    if (mMaterial == nullptr)
    {
        // Exception NOMATERIAL
        std::cout << "material don't set" << std:: endl;
        return;
    }

    switch (static_cast<int>(_type))
    {
    case static_cast<int>(ElementTypeEnum::P4) :
    {
        mElementType = new P4(mMaterial, isPlaneStrain);
        break;
    }

    default:
    {
        //Exception UNKNOWNTYPE
        break;
    }
    };

}

void Part::CreateMesh(bool writeMesh)
{
    if (mElementType == nullptr)
    {
        // Exception NOELEMENT
        std::cout << "element don't set" << std:: endl;
        return;
    }

    CreateMesh(mElementType, writeMesh);
}

void Part::CreateMesh(ElementType* type, bool writeMesh)
{

    mesh = new Mesh;

    if (mDivisions[0] > mDivisions[1])
    {
        int cnt;

        cnt = 0;
        for (int i=0; i<mDivisions[0]+1; ++i)
        {
            for (int j=0; j<mDivisions[1]+1; ++j)
            {
                double* coord = new double[2];
                coord[0] = -mSizes[0]/2.0+mSizes[0]/mDivisions[0]*i;
                coord[1] = -mSizes[1]/2.0+mSizes[1]/mDivisions[1]*j;
                Node* node = new Node(cnt, coord);
                mesh->nodes.push_back(node);
                coord = nullptr;
                ++cnt;
            }
        }

        cnt = 0;
        for (int i=0; i<mDivisions[0]; ++i)
        {
            for (int j=0; j<mDivisions[1]; ++j)
            {
                int* connectivity = new int[4];
                connectivity[0] = (mDivisions[1]+1)*(i  )+j  ;
                connectivity[1] = (mDivisions[1]+1)*(i+1)+j  ;
                connectivity[2] = (mDivisions[1]+1)*(i+1)+j+1;
                connectivity[3] = (mDivisions[1]+1)*(i  )+j+1;
                Element* element = new Element(cnt, connectivity, type);
                mesh->elements.push_back(element);
                connectivity = nullptr;
                ++cnt;
            }
        }
    }
    else
    {
        int cnt;

        cnt = 0;
        for (int i=0; i<mDivisions[1]+1; ++i)
        {
            for (int j=0; j<mDivisions[0]+1; ++j)
            {
                double* coord = new double[2];
                coord[0] = -mSizes[0]/2.0+mSizes[0]/mDivisions[0]*j;
                coord[1] = -mSizes[1]/2.0+mSizes[1]/mDivisions[1]*i;
                Node* node = new Node(cnt, coord);
                mesh->nodes.push_back(node);
                coord = nullptr;
                ++cnt;
            }
        }


        cnt = 0;
        for (int i=0; i<mDivisions[1]; ++i)
        {
            for (int j=0; j<mDivisions[0]; ++j)
            {
                int* connectivity = new int[4];
                connectivity[0] = (mDivisions[0]+1)*(i  )+j  ;
                connectivity[1] = (mDivisions[0]+1)*(i  )+j+1;
                connectivity[2] = (mDivisions[0]+1)*(i+1)+j+1;
                connectivity[3] = (mDivisions[0]+1)*(i+1)+j  ;
                Element* element = new Element(cnt, connectivity, type);
                mesh->elements.push_back(element);
                connectivity = nullptr;
                ++cnt;
            }
        }
    }

    mesh->nodesNum = mesh->nodes.size();
    mesh->elementsNum = mesh->elements.size();

    std::cout << "The mesh is created on part '" << mName << "'" << std::endl;
    std::cout << "Number of nodes: \t" << mesh->nodesNum << std::endl;
    std::cout << "Number of elements: \t" << mesh->elementsNum << std::endl;

    if (writeMesh)
    {
        std::ofstream file1("nodes");
        file1.precision(4);
        file1.setf(std::ios::scientific);
        file1.setf(std::ios::showpos);

        file1 << (mesh->nodes).size() << std::endl;

        for (auto it = (mesh->nodes).begin(); it < (mesh->nodes).end(); it++)
        {
            double* coord = (*it)->getCoord();
            file1 << coord[0] << "\t"
                  << coord[1] << std::endl;
        }

        file1.close();

        std::ofstream file2("elements");

        file2 << (mesh->elements).size() << std::endl;

        for (auto it = (mesh->elements).begin(); it < (mesh->elements).end(); it++)
        {
            int* connect = (*it)->getConnect();
            file2 << connect[0] << "\t"
                  << connect[1] << "\t"
                  << connect[2] << "\t"
                  << connect[3] << std::endl;
        }

        file2.close();
    }
}

std::string Part::getName() const
{
    return mName;
}

double* Part::getSizes() const
{
    return mSizes;
}

int* Part::getDivisions() const
{
    return mDivisions;
}

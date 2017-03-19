//---------------------------------------------------------------------------
// Created on: 04.03.2017
// Author: Mikhail A. Volkov
// E-mail: Volkovmikhl@gmail.com
//---------------------------------------------------------------------------
#include "includes.hpp"

ODB::ODB()
{
    mDim                = -1;
    mNodesPerElement    = -1;
    mMesh               = nullptr;
    mNodes              = nullptr;
    mElements           = nullptr;
}

ODB::ODB(Mesh* mesh, int dim, int nodesPerElement)
{
    mDim               = dim;
    mNodesPerElement   = nodesPerElement;
    mMesh              = mesh;
    mNodes             = &(mesh->nodes);
    mElements          = &(mesh->elements);
}

ODB::~ODB()
{
    mMesh               = nullptr;
    mNodes              = nullptr;
    mElements           = nullptr;
}

void ODB::addFrameVector(std::string key, std::vector<ODBFrame> value)
{
    mFramesMap[key] = value;
}

void ODB::addFrame(std::string key, ODBFrame value)
{
    mFramesMap[key].push_back(value);
}

void ODB::setModelName(std::string modelName)
{
    mModelName = modelName;
}
void ODB::setPartName(std::string partName)
{
    mPartName = partName;
}

std::map<std::string, std::vector<ODBFrame>>& ODB::getFramesMap()
{
    return mFramesMap;
}

bool ODB::saveToFile(std::ofstream& fout, std::string path)
{
    fout << (int)OrpheusConstants::FileCodes::MODELNAME;
    fout << "\n" << mModelName << std::endl;
    fout << (int)OrpheusConstants::FileCodes::PARTNAME;
    fout << "\n" << mPartName  << std::endl;
    fout << (int)OrpheusConstants::FileCodes::DIMENSION;
    fout << "\n" << mDim << std::endl;
    fout << (int)OrpheusConstants::FileCodes::NODESPERELEMENT << "\n"
         << mNodesPerElement << std::endl;


    fout << (int)OrpheusConstants::FileCodes::NODES;
    fout << "\n" << mNodes->size() << "\n";
    double *tmp_coords;
    for (unsigned int i = 0; i < mNodes->size(); i++)
    {
        tmp_coords = mNodes->at(i)->getCoord();
        for (int j = 0; j < mDim; ++j)
            fout << tmp_coords[j] << " ";
        fout << std::endl;
    }
    tmp_coords = nullptr;

    fout << (int)OrpheusConstants::FileCodes::ELEMENTS;
    fout << "\n" << mElements->size() << "\n";
    int *tmp_connectivity;
    for (unsigned int i = 0; i < mElements->size(); i++)
    {
        tmp_connectivity = mElements->at(i)->getConnect();
        for (int j = 0; j < mNodesPerElement; ++j)
            fout << tmp_connectivity[j] << " ";
        fout << std::endl;
    }
    tmp_connectivity = nullptr;

    for (auto it = mFramesMap.begin(); it != mFramesMap.end(); ++it)
    {
        fout << (int)OrpheusConstants::FileCodes::STEP;
        fout << "\n" << it->first << std::endl;
        for (auto it_frame  = it->second.begin();
                  it_frame != it->second.end()  ; ++it_frame)
        {
            fout << (int)OrpheusConstants::FileCodes::FRAME << std::endl;
            it_frame->fileStreamWrite(fout, mDim);
        }
    }

    fout << (int)OrpheusConstants::FileCodes::ENDOFFILE;

    return true;
}

//---------------------------------------------------------------------------
// Created on: 04.03.2017.
// Author: Mikhail A. Volkov
// E-mail: Volkovmikhl@gmail.com
//---------------------------------------------------------------------------

#ifndef ODB_H_
#define ODB_H_

enum class FileCodes;

#include "ODBFrame.h"

#include <iostream>
#include <string>
#include <vector>

// Sample declaration--------------------------------------------------------
class Node;
class Element;
class Model;
class Mesh;

//---------------------------------------------------------------------------


class ODB
{
public:
    explicit ODB();
    explicit ODB(Mesh*, int, int);
    ~ODB();

    void addFrameVector(std::string, std::vector<ODBFrame>);
    void addFrame(std::string, ODBFrame);

    void setModelName (std::string);
    void setPartName  (std::string);

    bool saveToFile(std::ofstream&, std::string);

    std::map<std::string, std::vector<ODBFrame>>& getFramesMap();

private:
    int mDim, mNodesPerElement;

    std::string mModelName, mPartName;

    Mesh *mMesh;

    std::vector<Node*>*    mNodes;     // Clears in Mesh class
    std::vector<Element*>* mElements;  //

    std::map<std::string, std::vector<ODBFrame>> mFramesMap;
};

#endif /* ODB_H_ */

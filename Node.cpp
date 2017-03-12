/*
 * Node.cpp
 *
 *  Created on: Jan 18, 2017
 *      Author: pavel
 */

#ifndef NODE_CPP_
#define NODE_CPP_

#include "Node.hpp"

Node::Node()
{
    mId    = -1;
    mCoord = nullptr;
}

Node::Node(int myId, double* myCoord)
{
    mId    = myId;
    mCoord = myCoord;
}

Node::~Node()
{
    if (mCoord != nullptr)
        delete [] mCoord;
}

void Node::setCoord(double* coords)
{
    if (mCoord != nullptr)
        delete [] mCoord;

    mCoord = coords;
}

int Node::getId() const
{
    return mId;
}

double* Node::getCoord() const
{
    return mCoord;
}

#endif /* NODE_CPP_ */

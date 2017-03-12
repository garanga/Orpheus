/*
 * Element.cpp
 *
 *  Created on: Jan 18, 2017
 *      Author: pavel
 */

#include "Element.hpp"

#include "ElementLib/ElementType.hpp"

Element::Element()
{
    mId           = -1;
    mConnectivity = nullptr;
    mType         = nullptr;
}

Element::Element(int myId, int* myConnectivity, ElementType* myType)
{
     mId           = myId;
     mConnectivity = myConnectivity;
     mType         = myType;
}

Element::~Element()
{
    if (mConnectivity != nullptr)
        delete [] mConnectivity;
    if (mType != nullptr)
        delete mType;
}

void Element::setConnect(int* connectivity)
{
    if (mConnectivity != nullptr)
        delete [] mConnectivity;

    mConnectivity = connectivity;
}

int Element::getId() const
{
     return mId;
}

int* Element::getConnect() const
{
     return mConnectivity;
}

ElementType* Element::getType() const
{
     return mType;
}

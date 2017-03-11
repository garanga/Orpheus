/*
 * Element.hpp
 *
 *  Created on: Jan 18, 2017
 *      Author: pavel
 */

#ifndef ELEMENT_HPP_
#define ELEMENT_HPP_

class ElementType;

class Element
{

public:

    explicit Element(int, int*, ElementType*);
    ~Element();

    int          getId() const;
    int*         getConnect() const;
    ElementType* getType() const;

private:

    int          mId;
    int*         mConnectivity; // Array
    ElementType* mType;

};

#endif /* ELEMENT_HPP_ */

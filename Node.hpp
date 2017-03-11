/*
 * Node.hpp
 *
 *  Created on: Jan 18, 2017
 *      Author: pavel
 */

#ifndef NODE_HPP_
#define NODE_HPP_

class Node
{
public:
    explicit Node(int myId, double* myCoord);
    ~Node();

    int     getId() const;
    double* getCoord() const;
private:
    int     mId;
    double* mCoord; // Array
};

#endif /* NODE_HPP_ */

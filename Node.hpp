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
private:
	int mId;
	double* mCoord;
public:
	Node(int myId, double* myCoord);
	int getId() const;
	double* getCoord() const;
};

#endif /* NODE_HPP_ */

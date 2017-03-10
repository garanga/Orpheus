/*
 * Mesh.cpp
 *
 *  Created on: Jan 18, 2017
 *      Author: pavel
 */

#include "Mesh.hpp"

#include <iostream>

#include "Node.hpp"
#include "Element.hpp"
#include "Part.hpp"

Mesh::Mesh(Part* myPart, ElementType* myType)
{

	// This is my second commit


	int cnt;
	Node* node;
	double* coord;
	Element* element;
	int* connectivity;

	double* sizes = myPart->getSizes();
	int* divisions = myPart->getDivisions();

	if (divisions[0]>divisions[1])
	{
		cnt = 0;
		for (int i=0; i<divisions[0]+1; ++i)
		{
			for (int j=0; j<divisions[1]+1; ++j)
			{
				coord = new double[2];
				coord[0] = -sizes[0]/2.0+sizes[0]/divisions[0]*i;
				coord[1] = -sizes[1]/2.0+sizes[1]/divisions[1]*j;
				node = new Node(cnt, coord);
				nodes.push_back(node);

				++cnt;
				delete node;
				delete coord;

			}
		}

		cnt = 0;
		for (int i=0; i<divisions[0]; ++i)
		{
			for (int j=0; j<divisions[1]; ++j)
			{
				connectivity = new int[4];
				connectivity[0] = (divisions[1]+1)*(i  )+j   +1;
				connectivity[1] = (divisions[1]+1)*(i+1)+j   +1;
				connectivity[2] = (divisions[1]+1)*(i+1)+j+1 +1;
				connectivity[3] = (divisions[1]+1)*(i  )+j+1 +1;
				element = new Element(cnt, connectivity, myType);
				elements.push_back(element);

				++cnt;
				delete element;
				delete connectivity;

			}
		}
	}
	else
	{
		cnt = 0;
		for (int i=0; i<divisions[1]+1; ++i)
		{
			for (int j=0; j<divisions[0]+1; ++j)
			{
				coord = new double[2];
				coord[0] = -sizes[0]/2.0+sizes[0]/divisions[0]*j;
				coord[1] = -sizes[1]/2.0+sizes[1]/divisions[1]*i;
				node = new Node(cnt, coord);
				nodes.push_back(node);

				++cnt;
//				delete node;
//				delete coord;

			}
		}


		cnt = 0;
		for (int i=0; i<divisions[1]; ++i)
		{
			for (int j=0; j<divisions[0]; ++j)
			{
				connectivity = new int[4];
				connectivity[0] = (divisions[0]+1)*(i  )+j  ;
				connectivity[1] = (divisions[0]+1)*(i  )+j+1;
				connectivity[2] = (divisions[0]+1)*(i+1)+j+1;
				connectivity[3] = (divisions[0]+1)*(i+1)+j  ;
				element = new Element(cnt, connectivity, myType);
				elements.push_back(element);

				++cnt;
//				delete element;
//				delete connectivity;

			}
		}
	}

	mNumNodes = nodes.size();
	mNumElements = elements.size();

	std::cout << "The mesh is created on part '" << myPart->getName() << "'" << std::endl;
	std::cout << "Number of nodes: \t" << mNumNodes << std::endl;
	std::cout << "Number of elements: \t" << mNumElements << std::endl;

}

int Mesh::getNumNodes() const
{
	return mNumNodes;
}

int Mesh::getNumElements() const
{
	return mNumElements;
}

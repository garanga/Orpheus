/*
 * Body.h
 *
 *  Created on: Feb 27, 2017
 *      Author: pavel
 */

#ifndef BODY_HPP_
#define BODY_HPP_

#include <string>
#include <vector>

class Point;
class Line;
class ElementType;
class Mesh;

class Body
{
public:

    Body(std::string name);
   ~Body();

    void addPoint(double x1, double x2);
    void addLine(int point1No, int point2No);

    void setLineDivisions(int lineNo, int divisions);

    // A method creating a mesh on part
    void createMesh(ElementType* type);

    int                getLinesNum() const;
    std::vector<Line*> getLines() const;
    Mesh*              getMesh() const;
    std::string        getName() const;

private:
    Mesh* mMesh;
    std::string mName;

    std::vector<Point*> mPoints;
    std::vector<Line*>  mLines;
};



#endif /* BODY_HPP_ */

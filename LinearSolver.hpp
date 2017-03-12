/*
 * LinearSolver.hpp
 *
 *  Created on: Jan 27, 2017
 *      Author: pavel
 */

#ifndef LINEARSOLVER_HPP_
#define LINEARSOLVER_HPP_


#include <string>
#include <map>

class Load;
class Constraint;
class Step;
class Model;
class ODB;

#include "Eigen/Sparse"
#include "Eigen/Dense"

class LinearSolver
{
public:
    explicit LinearSolver(Model*, std::map<std::string, ODB>&);
    ~LinearSolver();

    void solve();

private:
    Model*                        mModel;
    std::map<std::string, ODB>&   mPartODBMap;

    void applyLoads(std::vector<Load*>&, Eigen::VectorXd&, const double&);
    void applyConstraints(std::vector<Constraint*>&   ,
                          Eigen::SparseMatrix<double>&,
                          Eigen::VectorXd&            ,
                          const double&               );

    void fillOutput(ODB&, Eigen::VectorXd&, Step*);

    void update(Eigen::VectorXd &u     , Eigen::MatrixXd &sigma,
                Eigen::VectorXd & force                        ) const;

    Eigen::SparseMatrix<double> calcGlobK() const;

    void updateForce(Eigen::VectorXd &u, Eigen::VectorXd &force) const;

};


#endif /* LINEARSOLVER_HPP_ */

/*
 * Solver.hpp
 *
 *  Created on: Jan 27, 2017
 *      Author: pavel
 */

#ifndef SOLVER_HPP_
#define SOLVER_HPP_


#include <string>

class Model;
class Odb;

#include "Eigen/Sparse"

class Solver
{

public:

	Solver(Model* myModel, Odb* myOdb);

	void
	solve();

private:

	Model* model_;
	Odb*   odb_;

	int itra = 70;
	int maxBisectionLevel = 5;
	double tol = 1.0e-6;
	double atol = 1.0e5;

	void update(Eigen::VectorXd &u, Eigen::MatrixXd &sigma, Eigen::VectorXd & force) const;
	Eigen::SparseMatrix<double> calcGlobK() const;
	void updateForce(Eigen::VectorXd &u, Eigen::VectorXd &force) const;

};


#endif /* SOLVER_HPP_ */

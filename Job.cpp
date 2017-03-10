/*
 * Job.cpp
 *
 *  Created on: Jan 31, 2017
 *      Author: pavel
 */
#include "Job.hpp"

#include "includes.hpp"

#include <iostream>
#include <string>
#include <vector>


Job::Job(std::string name, Model* model)
	: name_(name), model_(model)
{
	std::cout << "The job '" << name_ << "' is created" << std::endl;
	odb_ = new Odb(model);
}


Job::~Job()
{
	delete odb_;
}


std::string
Job::getName() const
{
	return name_;
}


Odb*
Job::Submit()
{
	Solver* solver = new Solver(model_, odb_);

	solver->solve();


	// A global stiffness matrix for the undeformed mesh
//	Eigen::SparseMatrix<double> globK(2*mesh->nodesNum,2*mesh->nodesNum);
//	globK = calcGlobK();












//	Eigen::Matrix<double,Eigen::Dynamic,1> globF(2*mesh->nodesNum);
//	globF = Eigen::Matrix<double,Eigen::Dynamic,1> :: Zero(2*mesh->nodesNum);
//
//	StaticStep* step;
//	step = dynamic_cast<StaticStep*>(mModel->steps[1]);
//
//
//	for (auto it = (step->constraints).begin(); it < (step->constraints).end(); ++it)	{
//
//
//
//		std::vector<int> indices;
//		std::vector<double> values;
//
//		if (static_cast<int>((*it)->mType) & static_cast<int>(DisplacementConstraintType::UX))
//		{
//			std::vector<int> region = ((*it)->mRegion);
//			for (unsigned int i=0; i<region.size(); ++i)
//			{
//				region[i] *= 2;
//				region[i] += 0;
//			}
//			indices.insert(indices.end(),region.begin(),region.end());
//			std::vector<double> value(region.size(),(*it)->mValue[0]);
//			values.insert(values.end(),value.begin(),value.end());
//		}
//
//		if (static_cast<int>((*it)->mType) & static_cast<int>(DisplacementConstraintType::UY))
//		{
//			std::vector<int> region = ((*it)->mRegion);
//			for (unsigned int i=0; i<region.size(); ++i)
//			{
//				region[i] *= 2;
//				region[i] += 1;
//			}
//			indices.insert(indices.end(),region.begin(),region.end());
//			std::vector<double> value(region.size(),(*it)->mValue[1]);
//			values.insert(values.end(),value.begin(),value.end());
//		}
//
//
//		for (int k=0; k<globK.outerSize(); ++k)
//		{
//			for (Eigen::SparseMatrix<double>::InnerIterator it1(globK,k); it1; ++it1)
//			{
//
//				for (unsigned int i=0; i<indices.size(); ++i)
//				{
//					if (it1.row() == indices[i] || it1.col() == indices[i])
//					{
//
////						it1.valueRef() = it1.row() == it1.col() ? it1.value() : 0.0;
//
//						if (it1.row() == it1.col())
//						{
//							it1.valueRef() = it1.value();
//						}
//						else
//						{
//							if (it1.col()==indices[i]) // this is the given column
//							{
//								globF(it1.row()) -= it1.value()*values[i];
//							}
//							it1.valueRef() = 0.0;
//						} /* it1.row() != it1.col() */
//
//					}
//				}
//
//
//
//			}
//		}
//
//		for (int k=0; k<globK.outerSize(); ++k)
//		{
//			for (Eigen::SparseMatrix<double>::InnerIterator it1(globK,k); it1; ++it1)
//			{
//				for (unsigned int i=0; i<indices.size(); ++i)
//				{
//					if (it1.row() == indices[i] || it1.col() == indices[i])
//					{
//						if (it1.row() == it1.col())
//						{
//								globF(it1.row()) = it1.value()*values[i];
//						}
//					}
//				}
//			}
//		}
//
//	}
//
//	std::vector<int> indices;
//	std::vector<double> values;
//
//	for (auto it = (step->loads).begin(); it < (step->loads).end(); ++it)	{
//
//		if (static_cast<int>((*it)->mType) & static_cast<int>(ConcentratedLoadType::FX))
//		{
//			std::vector<int> region = ((*it)->mRegion);
//			for (unsigned int i=0; i<region.size(); ++i)
//			{
//				region[i] *= 2;
//				region[i] += 0;
//			}
//			indices.insert(indices.end(),region.begin(),region.end());
//			std::vector<double> value(region.size(),(*it)->mValue[0]);
//			values.insert(values.end(),value.begin(),value.end());
//		}
//
//		if (static_cast<int>((*it)->mType) & static_cast<int>(ConcentratedLoadType::FY))
//		{
//			std::vector<int> region = ((*it)->mRegion);
//			for (unsigned int i=0; i<region.size(); ++i)
//			{
//				region[i] *= 2;
//				region[i] += 1;
//			}
//			indices.insert(indices.end(),region.begin(),region.end());
//			std::vector<double> value(region.size(),(*it)->mValue[1]);
//			values.insert(values.end(),value.begin(),value.end());
//		}
//
//		for (unsigned k=0; k<globF.size(); ++k)
//		{
//			for (unsigned i=0; i<indices.size(); ++i)
//			{
//
//				if (k==static_cast<unsigned>(indices[i]))
//				{
//					globF(k) = values[i];
//				}
//			}
//		}
//
//
//
//
//
//
//
//	}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//	Eigen::SimplicialLDLT<Eigen::SparseMatrix<double> > solver(globK);
//	Eigen::VectorXd displacements = solver.solve(globF);
//
//	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1" << std::endl;
//	std::cout << displacements(502*501*2+0) << std::endl;
//	std::cout << displacements(502*501*2+1) << std::endl;
//	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1" << std::endl;


	std::cout << odb_->getStepNum() << std::endl;

	for (int i = 0; i < odb_->getStepNum(); ++i)
	{
		std::cout << odb_->getStep(i)->getFrameNum() << std::endl;
	}

	{
	std::vector<double> data = odb_->getStep(0)->getFrame(0)->getFieldOutput(0)->getData();

	for (auto it = data.begin(); it < data.end(); ++it)
	{
		std::cout << *it << "  ";
	}
	std::cout << std::endl;
	}

	{
	std::vector<double> data = odb_->getStep(0)->getFrame(1)->getFieldOutput(0)->getData();

	for (auto it = data.begin(); it < data.end(); ++it)
	{
		std::cout << *it << "  ";
	}
	std::cout << std::endl;
	}

	saveOdb(odb_,"example");

	return odb_;
}


/*!
 * \f[
 *		\bm{R}^k = \iint\limits_{\Gamma_t} \bm{N}^T \bm{t} \, d\Gamma +
 *		           \iiint\limits_{\Omega} \bm{N}^T \bm{f}^b \, d\Omega -
 *		           \iiint\limits_{\Omega} \bm{B}^T \bm{\sigma}^k \, d\Omega
 * \f]
 */
//void updateSR(Eigen::MatrixXd &sigma, Eigen::VectorXd &force)
//{

//	Mesh* mesh = mModel->parts[0]->mesh;
//
//	Eigen::VectorXd sigma(3,3*3*mesh->elementsNum)
//
//	int* connectivity;
//	double* coord;
//	Eigen::Matrix<double,2,4> nodesCoordGlob; //!!!!!!!
//
//	int k,l;

//	Eigen::Matrix<double,2,2> locK;

//	for (auto it = (mesh->elements).begin(); it < (mesh->elements).end(); it++)
//	{
//		connectivity = (*it)->connectivity();
//
//		for (int i=0; i<(*it)->type()->getNumNodes(); i++)
//		{
//			coord = (mesh->nodes)[connectivity[i]]->getCoord();
//			nodesCoordGlob(0,i) = coord[0];
//			nodesCoordGlob(1,i) = coord[1];
//		}
//
//		for (int i=0; i<(*it)->type()->getNumNodes(); i++)
//		{
//			k = connectivity[i];
//			for (int j=0; j<(*it)->type()->getNumNodes(); j++)
//			{
//				l = connectivity[j];
//				locK = (*it)->type()->calcLocK(i, j, nodesCoordGlob);
//
//				triplets.push_back(T(2*k  ,2*l  ,locK(0,0)));
//				triplets.push_back(T(2*k  ,2*l+1,locK(0,1)));
//				triplets.push_back(T(2*k+1,2*l  ,locK(1,0)));
//				triplets.push_back(T(2*k+1,2*l+1,locK(1,1)));
//
//			}
//		}
//	}
//
//	Eigen::SparseMatrix<double> globK(2*mesh->nodesNum,2*mesh->nodesNum);
//
//	globK.setFromTriplets(triplets.begin(), triplets.end());
//
//	return globK;
//}



//Eigen::SparseMatrix<double> Job::calcGlobK()
//{
//
//	Mesh* mesh = mModel->parts[0]->mesh;
//
//	std::cout.precision(2);
//	std::cout.setf(std::ios::showpos);
//	std::cout.setf(std::ios::scientific);
//
//	std::vector<T> triplets;
//
//	int* connectivity;
//	double* coord;
//	Eigen::Matrix<double,2,4> nodesCoordGlob;
//
//	int k,l;
//
//	Eigen::Matrix<double,2,2> locK;
//
//	for (auto it = (mesh->elements).begin(); it < (mesh->elements).end(); it++)
//	{
//		connectivity = (*it)->connectivity();
//
//		for (int i=0; i<(*it)->type()->getNumNodes(); i++)
//		{
//			coord = (mesh->nodes)[connectivity[i]]->getCoord();
//			nodesCoordGlob(0,i) = coord[0];
//			nodesCoordGlob(1,i) = coord[1];
//		}
//
//		for (int i=0; i<(*it)->type()->getNumNodes(); i++)
//		{
//			k = connectivity[i];
//			for (int j=0; j<(*it)->type()->getNumNodes(); j++)
//			{
//				l = connectivity[j];
//				locK = (*it)->type()->calcLocK(i, j, nodesCoordGlob);
//
//				triplets.push_back(T(2*k  ,2*l  ,locK(0,0)));
//				triplets.push_back(T(2*k  ,2*l+1,locK(0,1)));
//				triplets.push_back(T(2*k+1,2*l  ,locK(1,0)));
//				triplets.push_back(T(2*k+1,2*l+1,locK(1,1)));
//
//			}
//		}
//	}
//
//	Eigen::SparseMatrix<double> globK(2*mesh->nodesNum,2*mesh->nodesNum);
//
//	globK.setFromTriplets(triplets.begin(), triplets.end());
//
////	globK.makeCompressed();
//
////	std::cout << globK << std::endl;
//
//	return globK;
//}


//
//    std::vector< Eigen::Triplet<int> > triplets;
//
//    triplets.push_back(Eigen::Triplet<int>(0, 1, 3));
//    triplets.push_back(Eigen::Triplet<int>(1, 0, 22));
//    triplets.push_back(Eigen::Triplet<int>(2, 1, 5));
//    triplets.push_back(Eigen::Triplet<int>(2, 3, 1));
//    triplets.push_back(Eigen::Triplet<int>(4, 2, 14));
//    triplets.push_back(Eigen::Triplet<int>(4, 4, 8));
//
//    A.setFromTriplets(triplets.begin(), triplets.end());
//
////    A.insert(0, 0);
//    std::cout << A;
//
////    A.makeCompressed();
//
////    std::cout << std::endl << A;
//
//
//

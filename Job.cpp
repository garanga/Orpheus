/*
 * Job.cpp
 *
 *  Created on: Jan 31, 2017
 *      Author: pavel
 */
#include "Job.hpp"

#include "includes.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


Job::Job(std::string name, Model* model)
    : mName(name), mModel(model)
{
    std::cout << "The job '" << mName << "' is created" << std::endl;
    mODB = new ODB;
}


Job::~Job()
{
    delete mODB;
}

std::string Job::getName() const
{
    return mName;
}

ODB* Job::getODB() const
{
    return mODB;
}

void Job::saveODB()
{
    std::ofstream fout;
    std::string path = mName + "-Output" + ".txt";

    fout.open(path.c_str(), std::ios::out | std::ios::binary);
    fout.setf(std::ios::scientific | std::ios::showpos);

    for (auto it = mPartODBs.begin(); it != mPartODBs.end(); ++it)
        it->second.saveToFile(fout, path);

    fout.close();
}

void Job::Submit()
{
    LinearSolver* solver = new LinearSolver(mModel, mPartODBs);

    solver->solve();
}


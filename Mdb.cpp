/*
 * Mdb.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: pavel
 */

#include "Mdb.hpp"

#include "Model.hpp"
#include "Job.hpp"

#include <algorithm>
#include <iostream>

Mdb::Mdb()
{
    std::cout << "An empty models database is created" << std::endl;
}

Mdb::~Mdb()
{
    for (auto it = mModels.begin(); it < mModels.end(); ++it)
        delete *it;
    for (auto job = mJobs.begin(); job < mJobs.end(); ++job)
        delete *job;
}

Model*
Mdb::getModel(int No) const
{
    return mModels[No];
}

Model*
Mdb::getModel(std::string name) const
{
    auto it = std::find_if(mModels.begin(),mModels.end(),[name](Model* model)
              {
                     return model->getName() == name;
              });
    return *it;
}

Job*
Mdb::getJob(int No) const
{
    return mJobs[No];
}

Job*
Mdb::getJob(std::string name) const
{
    auto it = std::find_if(mJobs.begin(),mJobs.end(),[name](Job* job)
              {
                     return job->getName() == name;
              });
    return *it;
}

Model*
Mdb::createModel(std::string myName)
{
    Model* model = new Model(myName);
    mModels.push_back(model);
    return model;
}

Job*
Mdb::createJob(std::string name, Model* model)
{
    Job* job = new Job(name, model);
    mJobs.push_back(job);
    return job;
}

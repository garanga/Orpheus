/*
 * Job.hpp
 *
 *  Created on: Jan 31, 2017
 *      Author: pavel
 */

#ifndef JOB_HPP_
#define JOB_HPP_

#include <string>
#include <map>

class Model;
class ODB;

class Job
{
public:
    Job(std::string name, Model* model);
   ~Job();

    std::string  getName() const;
    ODB*         getODB()  const;

    void saveODB();

    void Submit();

private:
    std::string                mName;
    Model*                     mModel;
    ODB*                       mODB;
    std::map<std::string, ODB> mPartODBs;
};


#endif /* JOB_HPP_ */

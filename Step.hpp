/*
 * Step.hpp
 *
 *  Created on: Feb 9, 2017
 *      Author: pavel
 */

#ifndef STEP_HPP_
#define STEP_HPP_

#include <string>
#include <vector>

namespace OrpheusConstants
{
    enum class OutputSymbols;
}

class Step
{
public:
    Step(std::string);
    virtual ~Step();

    void addOutputRequest(OrpheusConstants::OutputSymbols);
    void addOutputRequest(std::vector<OrpheusConstants::OutputSymbols>);

    std::string                getName() const;
    std::vector<OrpheusConstants::OutputSymbols> getOutputRequest() const;

private:
    std::string                mName;
    std::vector<OrpheusConstants::OutputSymbols> mOutputRequest;
};


#endif /* STEP_HPP_ */

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

enum class OutputSymbols;

class Step
{
public:
    Step(std::string);
    virtual ~Step();

    void addOutputRequest(OutputSymbols);
    void addOutputRequest(std::vector<OutputSymbols>);

    std::string                getName() const;
    std::vector<OutputSymbols> getOutputRequest() const;

private:
    std::string                mName;
    std::vector<OutputSymbols> mOutputRequest;
};


#endif /* STEP_HPP_ */

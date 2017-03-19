#include "includes.hpp"

#include <ctime>

int main()
{
    std::string modelName = "Model_1";
    std::string  partName = "Part_1";
    std::string materName = "Iso_1";
    std::string   jobName = "Job_1";


    Mdb *testMdb = new Mdb;

    try
    {
        testMdb->createModel(modelName);
        Model *currentModel = testMdb->getModel(modelName);

        // Create part
        currentModel->createPart(partName);

        double* sizes     = new double[2];
        int*    divisions = new int[2];

        sizes[0]     = 10.0;
        sizes[1]     = 10.0;

        divisions[0] =  1;
        divisions[1] =  1;

        Part *currentPart = currentModel->getPart(partName);

        currentPart->setSizes(sizes);
        currentPart->setDivisions(divisions);

        currentModel->createIsotropic(materName, 200e9, 0.25);
        currentModel->setMaterialToPart(materName, partName);
        currentPart->setElementType(OrpheusConstants::ElementTypeEnum::P4);
        currentPart->CreateMesh();

        currentModel->createStaticStep("Step-1", 0.0, 0.5, 0.1, 0.0, 0.5);
        StaticStep *currentStep = currentModel->getStatciStep("Step-1");

        // Set Output type
        currentStep->addOutputRequest(OrpheusConstants::OutputSymbols::U);

        std::vector<int> region;
        double *constraintValue;

        //---Constraint at node 1----------------------------------------------
        region.push_back(2 -1);

        constraintValue = new double[2];
        constraintValue[0] = 0.0;
        constraintValue[1] = 0.0;

        currentStep->CreateDisplacementConstraint
                            ("Constraint-1"                                   ,
                             region                                           ,
                             OrpheusConstants::DisplacementConstraintType::UXY,
                                                               constraintValue);
        region.clear();
        //---------------------------------------------------------------------

        //---Constraint at node 3----------------------------------------------
        region.push_back(2*2 - 1);

        constraintValue = new double[2];
        constraintValue[0] = 0.0;
        constraintValue[1] = 0.0;

        currentStep->CreateDisplacementConstraint
                            ("Constraint-2"                                   ,
                             region                                           ,
                             OrpheusConstants::DisplacementConstraintType::UX ,
                                                              constraintValue);
        region.clear();
        //---------------------------------------------------------------------

        //---Concentrated force at node 0--------------------------------------
        region.push_back(0*2);

        constraintValue = new double[2];
        constraintValue[0] = 0.0;
        constraintValue[1] = -200.0e6;

        currentStep->CreateConcentratedLoad("Load-1"                ,
                                            region                  ,
                          OrpheusConstants::ConcentratedLoadType::FY,
                                            constraintValue         );
        region.clear();
        //---------------------------------------------------------------------

        //---Concentrated force at node 2--------------------------------------
        region.push_back(1*2);

        constraintValue = new double[2];
        constraintValue[0] = 0.0;
        constraintValue[1] = +200.0e6;

        currentStep->CreateConcentratedLoad("Load-2"                ,
                                            region                  ,
                          OrpheusConstants::ConcentratedLoadType::FY,
                                            constraintValue         );
        region.clear();
        //---------------------------------------------------------------------
        // Create new step
        currentModel->createStaticStep("Step-2", 0.5, 1.0, 0.1, 0.5, 1.0);
        currentStep = currentModel->getStatciStep("Step-2");

        // Copy loads and constraints from previous step
        currentStep->CopyConstraints(*(currentModel->getStatciStep("Step-1")));
        currentStep->CopyLoads(*(currentModel->getStatciStep("Step-1")));

        // Set Output type
        currentStep->addOutputRequest(OrpheusConstants::OutputSymbols::U);

        testMdb->createJob(jobName, currentModel);

        time_t time1;
        time(&time1);

        testMdb->getJob(jobName)->Submit();
        testMdb->getJob(jobName)->saveODB();


        time_t time2;
        time(&time2);

        std::cout << time2-time1 << "s" << std::endl;

        std::cout << testMdb->getModel(0) << std::endl;
        std::cout << testMdb->getModel("Model_1") << std::endl;

    }

    catch (except::Exception& exc)
    {
        std::cout << "catch\n";
        std::cout << exc.what() << std::endl;
    }

    std::cout << "Delete" << std::endl;

    delete testMdb;

    std::cout << "Finish" << std::endl;

    return 0;
}



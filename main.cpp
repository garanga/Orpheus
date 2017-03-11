#include "includes.hpp"

#include <ctime>
#include <iostream>
#include <vector>

#include <Eigen/Dense>
/*
int main(int argc, char* argv[])
{
	// Model database
	Mdb* mdb;
	mdb = new Mdb();

	// Model
	Model* model;
	model = mdb->createModel("Model-1");

	// Creating a solid body
	Body* body;
	body = model->createBody("Body-1");

	body->addPoint(-5.0,-5.0);	// 0
	body->addPoint( 5.0,-5.0);	// 1
	body->addPoint( 5.0, 5.0);	// 2
	body->addPoint(-5.0, 5.0);	// 3

	body->addLine(0,1);			// 0
	body->addLine(1,2);			// 1
	body->addLine(2,3);			// 2
	body->addLine(3,0);			// 3

	for (int i = 0; i < body->getLinesNum(); ++i)
	{
		body->setLineDivisions(i, 10);
	}

	// Creating a solid geometrical model
	Part* part;
	part = model->createPart("Part-1");
	double* sizes = new double[2];
	sizes[0] = 10.0; sizes[1] = 10.0;
	part->setSizes(sizes);
	int* divisions = new int[2];
	divisions[0] =  1; divisions[1] =  1;
	part->setDivisions(divisions);

	Material* material;
	material = model->createIsotropic("Material-1", 200.0e9, 0.25);

	// Creating a discrete geometrical model

	P4* type;
	type = new P4(material);

	////////////////////////////////////
	Mesh* mesh1;
	mesh1 = body->createMesh(type);
	////////////////////////////////////

	Mesh* mesh;
	mesh = part->CreateMesh(type);

	// Creating a step for boundary conditions application

	StaticStep* step1;
//	step1 = dynamic_cast<StaticStep*>(model->CreateStaticStep("Step-1", 0.0, 0.5, 0.1, 0.0, 0.5));
	step1 = model->createStaticStep("Step-1", 0.0, 0.5, 0.1, 0.0, 0.5);

	step1->addFieldOutputRequest(FieldType::U);
	{
		std::vector<int> region;
		double* value;
		region.push_back(2  -1);
		value = new double[2];
		value[0] = 0.0; value[1] = 0.0;

		step1->CreateDispacementConstraint("Constraint-1",
			                          	   region,
										   DisplacementConstraintType::UXY,
										   value);
	}

	{
		std::vector<int> region;
		double* value;

		region.push_back(2*2-1);
		value = new double[2];
		value[0] = 0.0;
		step1->CreateDispacementConstraint("Constraint-2",
				                           region,
										   DisplacementConstraintType::UX,
										   value);
	}

	{
		std::vector<int> region;
		double* value;

		region.push_back(0*2);
		value = new double[2];
		value[1] = -200.0e6;
		step1->CreateConcentratedLoad("Load-1",
				                      region,
									  ConcentratedLoadType::FY,
									  value);
	}

	{
		std::vector<int> region;
		double* value;

		region.push_back(1*2);
		value = new double[2];
		value[1] = 200.0e6;
		step1->CreateConcentratedLoad("Load-2",
				                      region,
									  ConcentratedLoadType::FY,
									  value);
	}



	StaticStep* step2;
//	step2 = dynamic_cast<StaticStep*>(model->CreateStaticStep("Step-2", 0.5, 1.0, 0.1, 0.5, 1.0));
	step2 = model->createStaticStep("Step-2", 0.5, 1.0, 0.1, 0.5, 1.0);

	step2->addFieldOutputRequest(FieldType::U);

	{
		std::vector<int> region;
		double* value;
		region.push_back(2  -1);
		value = new double[2];
		value[0] = 0.0; value[1] = 0.0;

		step2->CreateDispacementConstraint("Constraint-1",
			                          	   region,
										   DisplacementConstraintType::UXY,
										   value);
	}

	{
		std::vector<int> region;
		double* value;

		region.push_back(2*2-1);
		value = new double[2];
		value[0] = 0.0;
		step2->CreateDispacementConstraint("Constraint-2",
				                           region,
										   DisplacementConstraintType::UX,
										   value);
	}

	{
		std::vector<int> region;
		double* value;

		region.push_back(0*2);
		value = new double[2];
		value[1] = -200.0e6;
		step2->CreateConcentratedLoad("Load-1",
				                      region,
									  ConcentratedLoadType::FY,
									  value);
	}

	{
		std::vector<int> region;
		double* value;

		region.push_back(1*2);
		value = new double[2];
		value[1] = 200.0e6;
		step2->CreateConcentratedLoad("Load-2",
				                      region,
									  ConcentratedLoadType::FY,
									  value);
	}

	Job* job;
	job = mdb->createJob("Job-1", model);

	time_t time1;
	time(&time1);

	job->Submit();


	time_t time2;
	time(&time2);

	std::cout << time2-time1 << "s" << std::endl;

	std::cout << mdb->getModel(0) << std::endl;
	std::cout << mdb->getModel("Model-1") << std::endl;

	return 0;

}
*/

int main()
{
    std::string modelName = "Model_1";
    std::string  bodyName = "Body_1";
    std::string  partName = "Part_1";
    std::string materName = "Iso_1";


    Mdb *testMdb = new Mdb;

    testMdb->createModel(modelName);
    Model *currentModel = testMdb->getModel(modelName);
/*
    currentModel->createBody(bodyName);
    // What the point?
    currentModel->getBody(bodyName)->addPoint(-5.0,-5.0);  // 0
    currentModel->getBody(bodyName)->addPoint( 5.0,-5.0);  // 1
    currentModel->getBody(bodyName)->addPoint( 5.0, 5.0);  // 2
    currentModel->getBody(bodyName)->addPoint(-5.0, 5.0);  // 3

    currentModel->getBody(bodyName)->addLine(0,1);         // 0
    currentModel->getBody(bodyName)->addLine(1,2);         // 1
    currentModel->getBody(bodyName)->addLine(2,3);         // 2
    currentModel->getBody(bodyName)->addLine(3,0);         // 3
*/
    // Create part
    currentModel->createPart(partName);

    double* sizes     = new double[2];
    int*    divisions = new int[2];

    sizes[0]     = 10.0;
    sizes[1]     = 10.0;

    divisions[0] =  1;
    divisions[1] =  1;

    currentModel->getPart(partName)->setSizes(sizes);
    currentModel->getPart(partName)->setDivisions(divisions);

    currentModel->createIsotropic(materName, 200e9, 0.25);
    currentModel->setMaterialToPart(materName, partName);
    currentModel->getPart(partName)->setElementType(ElementTypeEnum::P4);
    currentModel->getPart(partName)->CreateMesh();

    delete testMdb;

    return 0;
}

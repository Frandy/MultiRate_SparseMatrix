/*
 * GenerateMeshRestabFile.cpp
 *
 *  Created on: 5 janv. 2016
 *      Author: delpopol
 */

#include "GenerateMeshRestabFile.h"


using namespace Restab;

int GenerateMeshRestabFile::MeshRestab(std::vector<std::unique_ptr<ISolverData>>&& vect_solution){
	DataCube datacube;

	Integer num_solution = vect_solution.size();

	//====================================
	// Set Description
	//====================================

	{
	IndexDescription index;

	index.label = "components";
	index.name  = "components";

	datacube.list_of_index_description.add(index);
	}


	StringVector name(num_solution);

	for(Integer i=0; i<num_solution; i++){
			String tmp_name = "Iter";
			tmp_name +=  std::to_string(i);
			name[i] = tmp_name;
	}


	for(Integer i=1; i<=num_solution; i++){
	VariableDescription var;

	var.label = name[i-1];

	datacube.list_of_variable_description.add(var);
	}



	//====================================
	// Add Step Values
	//====================================

	MapInteger step_index_values;
	MapReal step_var_values;

	//Steps



	IntegerVector components = vect_solution[0]->getMesh();
	RealVector y = vect_solution[0]->getY();
	for (Integer i = 0; i< y.size(); ++i ){
		step_index_values.clear();
		step_var_values.clear();
		step_index_values.insert(KeyInteger("components",i+1));
		for(Integer j = 0; j < num_solution; j++){
			Bool has_succeded = vect_solution[j]->isHasSucceded();
			Bool ref = vect_solution[j]->isRefining();
			if(has_succeded == true && ref == false){
				IntegerVector components = vect_solution[j]->getMesh();
				RealVector real_comp = components.cast<Real>();
				String name_curr = name[j];
				step_var_values.insert(KeyReal(name_curr ,real_comp[i]));
			}
			else{
				String name_curr = name[j];
				step_var_values.insert(KeyReal(name_curr ,0.0));
			}
		}


		datacube.table_of_index_values.add(step_index_values);
		datacube.table_of_variable_values.add(step_var_values);

	}



	//======================================
	// Write Results
	//======================================

	String filename = "MeshResult";

	// Description

	String filenameDesc = filename + ".restab.desc";

	String text_desc = datacube.toStringDescription();
	std::cout << text_desc << "\n";

	datacube.writeDescription(filenameDesc);

	// Data

	String filenameData = filename + ".restab";

	String text_data = datacube.toStringData();
	//std::cout << text_data << "\n";

	datacube.writeData(filenameData);

	//======================================

	return 0;

}

int GenerateMeshRestabFile::MeshRestab(Real x0, Integer Nx, Real xL,std::vector<std::unique_ptr<ISolverData>>&& vect_solution){
	DataCube datacube;

	RealVector x_vect(Nx);
	x_vect.setLinSpaced(Nx,x0,xL);
	Integer num_solution = vect_solution.size();

	//====================================
	// Set Description
	//====================================

	{
	IndexDescription index;

	index.label = "x_node";
	index.name  = "numbNode";

	datacube.list_of_index_description.add(index);
	}

	{
		VariableDescription var;

		var.label ="x_value";

		datacube.list_of_variable_description.add(var);
		}

	StringVector name(num_solution);

	for(Integer i=0; i<num_solution; i++){
			String tmp_name = "Iter";
			tmp_name +=  std::to_string(i);
			name[i] = tmp_name;
	}


	for(Integer i=1; i<=num_solution; i++){
	VariableDescription var;

	var.label = name[i-1];

	datacube.list_of_variable_description.add(var);
	}



	//====================================
	// Add Step Values
	//====================================

	MapInteger step_index_values;
	MapReal step_var_values;

	//Steps



	IntegerVector components = vect_solution[0]->getMesh();
	RealVector y = vect_solution[0]->getY();
	for (Integer i = 0; i< y.size(); ++i ){
		step_index_values.clear();
		step_var_values.clear();
		step_index_values.insert(KeyInteger("x_node",i+1));
		step_var_values.insert(KeyReal("x_value",x_vect[i]));
		for(Integer j = 0; j < num_solution; j++){
			Bool has_succeded = vect_solution[j]->isHasSucceded();
			Bool ref = vect_solution[j]->isRefining();
			if(has_succeded == true && ref == false){
				IntegerVector components = vect_solution[j]->getMesh();
				RealVector real_comp = components.cast<Real>();
				String name_curr = name[j];
				step_var_values.insert(KeyReal(name_curr ,real_comp[i]));
			}
			else{
				String name_curr = name[j];
				step_var_values.insert(KeyReal(name_curr ,0.0));
			}
		}


		datacube.table_of_index_values.add(step_index_values);
		datacube.table_of_variable_values.add(step_var_values);

	}



	//======================================
	// Write Results
	//======================================

	String filename = "MeshResult";

	// Description

	String filenameDesc = filename + ".restab.desc";

	String text_desc = datacube.toStringDescription();
	std::cout << text_desc << "\n";

	datacube.writeDescription(filenameDesc);

	// Data

	String filenameData = filename + ".restab";

	String text_data = datacube.toStringData();
	//std::cout << text_data << "\n";

	datacube.writeData(filenameData);

	//======================================

	return 0;

}

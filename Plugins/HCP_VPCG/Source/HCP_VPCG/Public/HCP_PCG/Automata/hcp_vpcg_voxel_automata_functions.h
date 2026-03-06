// Copyright 2026 Dominion
// Released under the GNU license

#pragma once

#include "CoreMinimal.h"

#include <vector>

#include "Data/PCGBasePointData.h"

#include "HCP_PCG/Automata/hcp_vpcg_dt_voxel_automata.h"

#include "HCP_PCG/Objects/hcp_voxel_storage.h"

/*
	voxel_automata_hcp_functions_class

	C++ class that generates the data values of a hcp voxel data object point cloud based on the
	current state of the hcp voxel data object point cloud data values and the cellula Automata
	rules defined.

	After some testing, it is apparent that multithreading of the cellala automata generates incorrect
	and unpredictable results in the

								perform_voxel_automata_step_generation

	function. This should not occur as the output result of the cellula automata is not used as a basis
	for the iteration step, but is written to a copy of the 3D matrix to overwrite the original matrix
	data once all the cellula automata rules are completed for all cells. Evaluation of automata rules
	uses a matrix of the current state that is constant and unchanging during the process.

	Suspect that the CPU Multithreading needs a complex algorithm to perform the task correctly,
	or is simply unsuitable to be used.

	For information and detailed description of the methods and algorithims used to perform the cellular
	automata tasks, refere to the documentation in the file vw_HCP_voxel_draft_01
*/

/**
 * 
 */
class HCP_VPCG_API hcp_vpcg_voxel_automata_functions
{
public:
	//id_type          object_id;

	//log_panel_class* log_panel = NULL;

	std::vector <voxel_hcp_automata_byte_rule_struct_type> voxel_hcp_automata_rules;
	voxel_automata_generator_parameters_struct_type        voxel_automata_generator_parameters;

	//voxel_hcp_object_class* cloud = NULL;                    // Pointer to the hcp voxel data object that is to have cellula Automata rules applied to
	//voxel_hcp_object_class* voxel_automata_next_step_matrix; // Pointer to a copy of the hcp voxel data object that is to have result of cellula Automata rules applied save to
	u_long_int              max_number_steps;

	//voxel_hcp_object_class* voxel_hcp_object_to_execute = NULL;	// Pointer to the hcp voxel entity data stored in the Virtual Worlds scene data model

	//FConstPCGPointValueRanges value;

	//int get_max_voxel_automata_step_value();

	// Create an empty hcp voxel data object matrix in which to store the resultant cellula autoamata values to
	//bool create_voxel_automata_next_step_matrix();

	//bool perform_voxel_automata_generation(int automata_step);

	// generate and save cellula automata data for cellula automata generation step 
	// This procedure requires an initial voxel matrix that has initialised conditions set.
	//bool perform_voxel_automata_step_generation(int step);

	// Perform the cellula automata rules for step at hcp voxel matrix location x_index, y_index, z_index
	// and if all rules are met assign a defined value for this case, otherwise set a rules not met value
	//bool perform_voxel_automata_rules(int step, index_data_type x_index, index_data_type y_index, index_data_type z_index);

	// Return if a cellular automata rule is met for the hcp voxel matrix at location x_index, y_index, z_index
	// A cellular automata rule is met if all nieghbor hcp voxel cells rules apply
	//bool voxel_automata_rule_met(voxel_hcp_automata_byte_rule_struct_type voxel_hcp_automata_byte_rule, int step, index_data_type x_index, index_data_type y_index, index_data_type z_index);

	// Get all the voxel neighbor cell values of hcp voxel at matrix location x_index, y_index, z_index stored in a std::vector list
	std::vector<voxel_data_type> get_voxel_neighbours_state(FConstPCGPointValueRanges &hcp_vpcg_grid_values,index_data_type x_index, index_data_type y_index, index_data_type z_index, FIntVector3 matrix_dimension);

	// Get the neighbor cell status value of a hcp voxel that is at voxel matrix location x_index, y_index, z_index
	voxel_data_type get_voxel_neighbour_state(FConstPCGPointValueRanges &hcp_vpcg_grid_values,size_t neighbour, index_data_type x_index, index_data_type y_index, index_data_type z_index, FIntVector3 matrix_dimension);

	FIntVector3 get_voxel_neighbour_index_coordinates(FConstPCGPointValueRanges &hcp_vpcg_grid_values,size_t neighbour, int x_index, int y_index, int z_index);

	// Determine if hcp voxel cell index coordinate voxel_index_coordinate is valid or not
	// Ie if it is outside the volume and limits of the hcp voxel matrix 
	//bool valid_index_coordinate(FIntVector3 voxel_index_coordinate, FIntVector3 matrix_dimension);
	bool valid_index_coordinate(FConstPCGPointValueRanges &hcp_vpcg_grid_values,FIntVector3 voxel_index_coordinate, FIntVector3 matrix_dimension);

	//void assign_no_voxel_state_change(FIntVector3 voxel_data_index_coord);

	// Copy into the cellular automata data structure variabel voxel_automata_generator_parameters the cellula automata parameter values
	// that are stored in the virtual worlds scene data model that hcp voxel voxel_automata_initial_data points to
	//bool load_voxel_automata_initial_data(voxel_hcp_object_class* voxel_automata_initial_data);

	// Create an empty hcp voxel matrix
	//bool create_voxel_matrix();



};

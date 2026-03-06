// Fill out your copyright notice in the Description page of Project Settings.


#include "HCP_PCG/Automata/hcp_vpcg_voxel_automata_functions.h"


// Get all the voxel neighbor cell values of hcp voxel at matrix location x_index, y_index, z_index stored in a std::vector list
std::vector<voxel_data_type> hcp_vpcg_voxel_automata_functions::get_voxel_neighbours_state(FConstPCGPointValueRanges &hcp_vpcg_grid_values,index_data_type x_index, index_data_type y_index, index_data_type z_index, FIntVector3 matrix_dimension) {
	std::vector<voxel_data_type> neighbours_activity;
	for (size_t neighbour = 0; neighbour < NUMBER_HCP_NEIGHBOURS; neighbour++) {

		voxel_data_type voxel_state = get_voxel_neighbour_state(hcp_vpcg_grid_values, neighbour, x_index, y_index, z_index, matrix_dimension);

		neighbours_activity.push_back(voxel_state);
	}

	return neighbours_activity;
}

// Get the neighbor cell status value of a hcp voxel that is at voxel matrix location x_index, y_index, z_index
voxel_data_type hcp_vpcg_voxel_automata_functions::get_voxel_neighbour_state(FConstPCGPointValueRanges &hcp_vpcg_grid_values,size_t neighbour, index_data_type x_index, index_data_type y_index, index_data_type z_index, FIntVector3 matrix_dimension) {
	FIntVector3 voxel_neighbour_index_coord = get_voxel_neighbour_index_coordinates(hcp_vpcg_grid_values,neighbour, x_index, y_index, z_index);

	if (!valid_index_coordinate(hcp_vpcg_grid_values, voxel_neighbour_index_coord,matrix_dimension)) {
		return INVALID_VOXEL_VALUE; // *** Need to change this for a non valid value
	}

	hcp_voxel_storage voxel_object_data;

	return voxel_object_data.voxel_matrix_coordinate_activation_status(hcp_vpcg_grid_values, voxel_neighbour_index_coord,matrix_dimension);
}

FIntVector3 hcp_vpcg_voxel_automata_functions::get_voxel_neighbour_index_coordinates(FConstPCGPointValueRanges &hcp_vpcg_grid_values,size_t neighbour, int x_index, int y_index, int z_index) {
	FIntVector3 neighbor_index_coordinate;

	if (z_index % 2 == 0) {  // Even Z 
		if (y_index % 2 == 0) { // Even Y 
			switch (neighbour) {
				case 0: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index + 1; break;
				case 1: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index - 1; neighbor_index_coordinate.Z = z_index + 1; break;
				case 2: neighbor_index_coordinate.X = x_index - 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index + 1; break;


				case 3: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index + 1; neighbor_index_coordinate.Z = z_index;    break;
				case 4: neighbor_index_coordinate.X = x_index + 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index;    break;
				case 5: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index - 1; neighbor_index_coordinate.Z = z_index;    break;
				case 6: neighbor_index_coordinate.X = x_index - 1; neighbor_index_coordinate.Y = y_index - 1; neighbor_index_coordinate.Z = z_index;    break;
				case 7: neighbor_index_coordinate.X = x_index - 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index;    break;
				case 8: neighbor_index_coordinate.X = x_index - 1; neighbor_index_coordinate.Y = y_index + 1; neighbor_index_coordinate.Z = z_index;    break;

				case 9:  neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index - 1; break;
				case 10: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index - 1; neighbor_index_coordinate.Z = z_index - 1; break;
				case 11: neighbor_index_coordinate.X = x_index - 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index - 1; break;
			}
		}
		else {// Odd Y 
			switch (neighbour) {
				case 0: neighbor_index_coordinate.X = x_index + 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index + 1; break;
				case 1: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index - 1; neighbor_index_coordinate.Z = z_index + 1; break;
				case 2: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index + 1; break;

				case 3: neighbor_index_coordinate.X = x_index + 1; neighbor_index_coordinate.Y = y_index + 1; neighbor_index_coordinate.Z = z_index;    break;
				case 4: neighbor_index_coordinate.X = x_index + 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index;    break;
				case 5: neighbor_index_coordinate.X = x_index + 1; neighbor_index_coordinate.Y = y_index - 1; neighbor_index_coordinate.Z = z_index;    break;
				case 6: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index - 1; neighbor_index_coordinate.Z = z_index;    break;
				case 7: neighbor_index_coordinate.X = x_index - 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index;    break;
				case 8: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index + 1; neighbor_index_coordinate.Z = z_index;    break;

				case 9:  neighbor_index_coordinate.X = x_index + 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index - 1; break;
				case 10: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index - 1; neighbor_index_coordinate.Z = z_index - 1; break;
				case 11: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index - 1; break;
			}
		}
	}
	else { // Odd Z 
		if (y_index % 2 == 0) { // Even Y 
			switch (neighbour) {
				case 0: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index + 1; break;
				case 1: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index + 1; neighbor_index_coordinate.Z = z_index + 1; break;
				case 2: neighbor_index_coordinate.X = x_index + 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index + 1; break;

				case 3: neighbor_index_coordinate.X = x_index + 1; neighbor_index_coordinate.Y = y_index + 1; neighbor_index_coordinate.Z = z_index;    break;
				case 4: neighbor_index_coordinate.X = x_index + 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index;    break;
				case 5: neighbor_index_coordinate.X = x_index + 1; neighbor_index_coordinate.Y = y_index - 1; neighbor_index_coordinate.Z = z_index;    break;
				case 6: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index - 1; neighbor_index_coordinate.Z = z_index;    break;
				case 7: neighbor_index_coordinate.X = x_index - 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index;    break;
				case 8: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index + 1; neighbor_index_coordinate.Z = z_index;    break;

				case 9:  neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index - 1; break;
				case 10: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index + 1; neighbor_index_coordinate.Z = z_index - 1; break;
				case 11: neighbor_index_coordinate.X = x_index + 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index - 1; break;
			}
		}
		else {// Odd Y
			switch (neighbour) {
				case 0: neighbor_index_coordinate.X = x_index - 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index + 1; break;
				case 1: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index + 1; neighbor_index_coordinate.Z = z_index + 1; break;
				case 2: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index + 1; break;

				case 3: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index + 1; neighbor_index_coordinate.Z = z_index;    break;
				case 4: neighbor_index_coordinate.X = x_index + 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index;    break;
				case 5: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index - 1; neighbor_index_coordinate.Z = z_index;    break;
				case 6: neighbor_index_coordinate.X = x_index - 1; neighbor_index_coordinate.Y = y_index - 1; neighbor_index_coordinate.Z = z_index;    break;
				case 7: neighbor_index_coordinate.X = x_index - 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index;    break;
				case 8: neighbor_index_coordinate.X = x_index - 1; neighbor_index_coordinate.Y = y_index + 1; neighbor_index_coordinate.Z = z_index;    break;

				case 9:  neighbor_index_coordinate.X = x_index - 1; neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index - 1; break;
				case 10: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index + 1; neighbor_index_coordinate.Z = z_index - 1; break;
				case 11: neighbor_index_coordinate.X = x_index;     neighbor_index_coordinate.Y = y_index;     neighbor_index_coordinate.Z = z_index - 1; break;
			}
		}
	}

	return neighbor_index_coordinate;
}

// Determine if hcp voxel cell index coordinate voxel_index_coordinate is valid or not
// Ie if it is outside the volume and limits of the hcp voxel matrix 
bool hcp_vpcg_voxel_automata_functions::valid_index_coordinate(FConstPCGPointValueRanges &hcp_vpcg_grid_values,FIntVector3 voxel_index_coordinate, FIntVector3 matrix_dimension) {

	if (voxel_index_coordinate.Z < 0 || voxel_index_coordinate.Z > matrix_dimension.Z - 1) return false;
	if (voxel_index_coordinate.Y < 0 || voxel_index_coordinate.Y < 0) return false;

	if (voxel_index_coordinate.Z % 2 == 0) {// even z level
		if (voxel_index_coordinate.Y > matrix_dimension.Y - 1) return false;

		if (voxel_index_coordinate.Y % 2 == 0) { // even y coord
			if (voxel_index_coordinate.X > matrix_dimension.X - 1) return false;
		}
		else {
			if (voxel_index_coordinate.X > matrix_dimension.X - 2) return false;
		}
	}
	else {// odd z level
		if (voxel_index_coordinate.Y > matrix_dimension.Y - 2) return false;

		if (voxel_index_coordinate.Y % 2 == 0) {// even y coord
			if (voxel_index_coordinate.X > matrix_dimension.X - 2) return false;
		}
		else {
			if (voxel_index_coordinate.X > matrix_dimension.X - 1) return false;
		}
	}

	return true;
}

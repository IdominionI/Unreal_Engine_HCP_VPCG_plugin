// Copyright 2026 Dominion
// Released under the GNU license

#pragma once

#include "CoreMinimal.h"
#include "Data/PCGBasePointData.h"

#include "Math/Vector.h"

#include "HCP_PCG/Objects/hcp_vpcg_parameters.h"


class HCP_VPCG_API hcp_voxel_storage
{
public:
	hcp_voxel_storage();
	~hcp_voxel_storage();

	// ##############################################################################################
	// Functions to calculate the voxel matrix index of the storage vector that is a container or storage of a voxel cell of grid matrix coordinate (i,j,k)
	// See documentation vw_HCP_voxel_draft_01 for more details and explaination how these alogorithims were derived

	// Calculate the index of the  C++ vector modelling the voxel matrix value of layer iZ of a voxel that has coordinate (iX,iY,iZ)
	index_data_type get_z_layer_index_value(index_data_type iX, index_data_type iY, index_data_type iZ, index_data_type matrix_dimensionX, index_data_type matrix_dimensionY, index_data_type matrix_dimensionZ) {
		if (iZ % 2 == 0) // Even z level
			return (index_data_type(iY / 2) + iY % 2) * matrix_dimensionX + index_data_type(iY / 2) * (matrix_dimensionX - 1) + iX;
		else // Odd z level
			return (index_data_type(iY / 2) + iY % 2) * (matrix_dimensionX - 1) + index_data_type(iY / 2) * matrix_dimensionX + iX;
	}

	// calculate the index value of the C++ vector modelling the voxel matrix of a voxel of coordinate (iX,jY,kZ)
	index_data_type get_index_value(index_data_type iX, index_data_type iY, index_data_type iZ,index_data_type matrix_dimensionX, index_data_type matrix_dimensionY, index_data_type matrix_dimensionZ) {
		return (index_data_type(iZ / 2) + iZ % 2) * get_z_layer_total_z(matrix_dimensionX, matrix_dimensionY,0) + index_data_type(iZ / 2) * get_z_layer_total_z(matrix_dimensionX, matrix_dimensionY, 1) + get_z_layer_index_value(iX, iY, iZ, matrix_dimensionX, matrix_dimensionY, matrix_dimensionZ);
	}

	// calculate the total number of voxels cells that exist within a voxel layer iZ of a voxel matrix that has x dimension xdim, y dimension ydim
	index_data_type get_z_layer_total(index_data_type iZ, index_data_type xdim, index_data_type ydim) {
		if (iZ % 2 == 0) // Even z level
			return (index_data_type(ydim / 2) + ydim % 2) * xdim + index_data_type(ydim / 2) * (xdim - 1);
		else // Odd z level
			return (index_data_type((ydim - 1) / 2) + (ydim - 1) % 2) * (xdim - 1) + index_data_type((ydim - 1) / 2) * xdim;
	}

	// calculate the total number of voxels cells that exist within a voxel layer iZ of a voxel storage matrix
	index_data_type get_z_layer_total_z(index_data_type matrix_dimensionX, index_data_type matrix_dimensionY, index_data_type iZ) {
		return get_z_layer_total(iZ, matrix_dimensionX, matrix_dimensionY);
	}

	// calculate the total number of voxels cells that exist within a voxel matrix
	index_data_type calculate_voxel_matrix_data_size(index_data_type xdim, index_data_type ydim, index_data_type zdim) {
		return  (index_data_type(zdim / 2) + zdim % 2) * get_z_layer_total(0, xdim, ydim) + index_data_type(zdim / 2) * get_z_layer_total(1, xdim, ydim);
	}

	// calculate the total number of voxels cells that exist within a voxel storage matrix
	//index_data_type calculate_voxel_matrix_data_size(index_data_type matrix_dimensionX, index_data_type matrix_dimensionY, index_data_type matrix_dimensionZ) {
	//	return calculate_voxel_matrix_data_size(matrix_dimensionX, matrix_dimensionY, matrix_dimensionZ);
	//}

	// ###################################### END voxel matrix index   ########################################################

	// Retreive the 3 dim x,y,z coordinate that the matrix index corresponds to
	FIntVector3 get_matrix_coordinate(index_data_type matrix_index, FIntVector3 matrix_dimension) {
		FIntVector3 matrix_coord;

		index_data_type t0 = get_z_layer_total(0, matrix_dimension.X, matrix_dimension.Y);// total number for even z level
		index_data_type t1 = get_z_layer_total(1, matrix_dimension.X, matrix_dimension.Y);// total number for odd  z level

		index_data_type zt = t0 + t1; // total number for even + odd z levels

		bool even_z_level;

		if (matrix_index < t0) { // Voxel is in the even z=0 layer
			matrix_coord.Z = 0;
			even_z_level = true;
		}
		else {
			index_data_type zt_index01 = index_data_type(matrix_index / zt);
			index_data_type zt_index02 = index_data_type((matrix_index - zt_index01 * zt) / t0);

			if (zt_index02 > 0) { // Have matrix_index in the odd  z level
				matrix_coord.Z = zt_index01 * 2 + 1;
				even_z_level = false;
			}
			else {// Have matrix_index in the even z level
				matrix_coord.Z = zt_index01 * 2;
				even_z_level = true;
			}
		}

		// Get the array matrix index value of the x=0, y=0 z= matrix_coord.z voxel coordinate
		index_data_type zeroth_index = matrix_index - get_index_value(0, 0, matrix_coord.Z, matrix_dimension.X, matrix_dimension.Y, matrix_dimension.Z);

		index_data_type yt = 2 * matrix_dimension.X - 1; // Even row number of voxels + odd row of voxels of any z level

		if (even_z_level) {
			index_data_type yt_index01, yt_index02;

			yt_index01 = index_data_type(zeroth_index / yt);

			if (((zeroth_index - yt_index01 * yt) % yt) < matrix_dimension.X)
				yt_index02 = 0;
			else
				yt_index02 = 1;

			matrix_coord.Y = yt_index01 * 2 + yt_index02;
			matrix_coord.X = zeroth_index - ((index_data_type(matrix_coord.Y / 2) + matrix_coord.Y % 2) * matrix_dimension.X + index_data_type(matrix_coord.Y / 2) * (matrix_dimension.X - 1));
		}
		else {
			index_data_type yt_index01, yt_index02;

			yt_index01 = index_data_type(zeroth_index / yt);

			if (((zeroth_index - yt_index01 * yt) % yt) < matrix_dimension.X - 1)
				yt_index02 = 0;
			else
				yt_index02 = 1;

			matrix_coord.Y = yt_index01 * 2 + yt_index02;

			matrix_coord.X = zeroth_index - ((index_data_type(matrix_coord.Y / 2) + matrix_coord.Y % 2) * (matrix_dimension.X - 1) + index_data_type(matrix_coord.Y / 2) * matrix_dimension.X);
		}

		return matrix_coord;
	}

	// Calculate and return the 3D cartesian coordinate for a given i,j,k voxel matrix coordinate 
	// in local coordinates relative to the voxel matrix origin
	FVector get_voxel_cartesian_coordinate(FIntVector3 voxel_coord, double voxel_size) {
		index_data_type i = voxel_coord.X, j = voxel_coord.Y, k = voxel_coord.Z;

		float sqrt3 = sqrt(3.0f), third = 1.0f / 3.0f, z_mult = 2.0f * sqrt(6.0f) / 3.0f, sqrt3_2 = sqrt(1.5f);
		FVector voxel_cartesian_coordinate;

		// !!!!!!!!!!!!!!!!! MAJOR ERROR THAT NEEDS TO BE FIXED : NEED TO HAVE MATRIX ORIGIN VALUES ADDED TO AVOID CONFUSION AND CORRECT WHERE IN APP THIS FUNCTION IS USED !!!!!!!!!!!

		voxel_cartesian_coordinate.X = (2 * float(i) + float((j + k) % 2)) * voxel_size; // ++++
		voxel_cartesian_coordinate.Y = (sqrt3 * (float(j) + third * float(k % 2))) * voxel_size; // ++++

		voxel_cartesian_coordinate.Z = (z_mult * float(k) * voxel_size);
		//voxel_cartesian_coordinate.z = matrix_origin.x +(z_mult * float(k) *voxel_size);

		return voxel_cartesian_coordinate;
	}

	// Calculate and return the 3D cartesian coordinate for a given i,j,k voxel matrix coordinate in world  coordinates
	//FVector get_voxel_world_cartesian_coordinate(FIntVector3 voxel_matrix_coord ) {
	//	FVector  voxel_cart_coord = get_voxel_cartesian_coordinate(voxel_matrix_coord) + matrix_origin;

	//	return voxel_cart_coord;
	//}

	// Calculate and return the 3D cartesian coordinate for a given voxel matrix vector index entry in world  coordinates
	//FVector get_voxel_world_cartesian_coordinate(int index) {
	//	FVector voxel_matrix_coord = get_matrix_coordinate(index);
	//	FVector voxel_cart_coord   = get_voxel_cartesian_coordinate(voxel_matrix_coord) + matrix_origin;

	//	return voxel_cart_coord;
	//}


	// Calculate and return the index of the vector storage element for a given voxel matrix coordinate.
	index_data_type get_voxel_matrix_data_index(FIntVector3 matrix_coord, FIntVector3 matrix_dim) {
		return get_index_value(matrix_coord.X, matrix_coord.Y, matrix_coord.Z, matrix_dim.X, matrix_dim.Y, matrix_dim.Z);
	}

	// For a given set of limits of a Cartesian rectangular volume, calculate the dimensions of a voxel
	// matrix that fits within the limits of this rectangular volume.

	FIntVector3 calc_voxel_volume_dimensions(FVector GridExtents , double CellSize) {
		float x_size = GridExtents.X * 2.0f;
		float y_size = GridExtents.Y * 2.0f;
		float z_size = GridExtents.Z * 2.0f;
		float z_mult = 2.0f * sqrt(6.0f) / 3.0f;

		float x_res_step = CellSize * 2.0f;
		float y_res_step = CellSize * (3.0f / sqrt(3.0f));
		float z_res_step = CellSize * z_mult;

		int data_set_x_size, data_set_y_size, data_set_z_size;

		if (x_size / x_res_step - float((int)(x_size / x_res_step)) > 0.0)
			data_set_x_size = (int)(x_size / x_res_step) + 1;
		else
			data_set_x_size = (int)(x_size / x_res_step);

		if (y_size / y_res_step - float((int)(y_size / y_res_step)) > 0.0)
			data_set_y_size = (int)(y_size / y_res_step) + 1;
		else
			data_set_y_size = (int)(y_size / y_res_step);

		if (z_size / z_res_step - float((int)(z_size / z_res_step)) > 0.0)
			data_set_z_size = (int)(z_size / z_res_step) + 1;
		else
			data_set_z_size = (int)(z_size / z_res_step);

		return { data_set_x_size,data_set_y_size,data_set_z_size };
	}

	// +++++++++++++++++++++++++++++++++++++

	voxel_element_data_type voxel_matrix_coordinate_activation_status(FConstPCGPointValueRanges &hcp_vpcg_grid_values, index_data_type voxel_matrix_data_index) {
		if (voxel_matrix_data_index >= hcp_vpcg_grid_values.DensityRange.Num() || voxel_matrix_data_index < 0) {
			return INVALID_VOXEL_VALUE;
		}

		voxel_element_data_type voxel_value = hcp_vpcg_grid_values.DensityRange[voxel_matrix_data_index];
		return voxel_value;

		//return -1;
	}

	voxel_element_data_type voxel_matrix_coordinate_activation_status(FConstPCGPointValueRanges &hcp_vpcg_grid_values,FIntVector3 matrix_coord, FIntVector3 matrix_dimension) {
		index_data_type voxel_matrix_data_index = get_voxel_matrix_data_index(matrix_coord, matrix_dimension);

		if (voxel_matrix_data_index >= hcp_vpcg_grid_values.DensityRange.Num() || voxel_matrix_data_index < 0) return INVALID_VOXEL_VALUE;

		return voxel_matrix_coordinate_activation_status(hcp_vpcg_grid_values,voxel_matrix_data_index);

		//return -1;
	}

	// +++++++++++++++++++++++++++++++++++++

	// Obtain the voxel matrix index coordinates of the voxel matrix that a point P of cartesian coordinte
	// (x,y,z) will be found to be within the bounds of a 3D voxel cell.
	FIntVector3 hcp_voxel_cell_coord_from_cartesian(FVector matrix_origin, FVector position, double voxel_size) {
		float voxel_radius = voxel_size;
		float voxel_height = voxel_radius * (sqrt(1.5f) + sqrt(6.0f) / 3.0f);
		float grid_x, grid_y;

		float grid_z = position.Z - matrix_origin.Z;

		int level;

		if (grid_z < -sqrt(6.0f) / 3.0f)
			level = (int)((grid_z - voxel_height) / voxel_height);
		else
			level = (int)(grid_z / voxel_height);

		bool level_is_even = level % 2 == 0;

		if (level_is_even) {
			grid_x = position.X - matrix_origin.X;
			grid_y = position.Y - matrix_origin.Y;
			return get_hcp_voxel_cell_coord_even_level(grid_x, grid_y, grid_z, voxel_height, level, voxel_size);
		}
		else {
			grid_x = position.X - (matrix_origin.X + voxel_radius);
			grid_y = position.Y - (matrix_origin.Y + voxel_radius / sqrt(3.0f));
			return get_hcp_voxel_cell_coord_odd_level(grid_x, grid_y, grid_z, voxel_height, level, voxel_size);
		}
	}

	// Find the index of the one dimensional vertex vector array that a point P of cartesian coordinte
	// (x,y,z) will be within the bounds of a 3D voxel cell.
	index_data_type index_of_voxel_cell_with_cartesian_coord(FVector matrix_origin, FIntVector3 matrix_dimension, FVector position, double voxel_size) {
		FIntVector3 voxel_coord = hcp_voxel_cell_coord_from_cartesian(matrix_origin, position, voxel_size);

		if (cartesian_coord_within_matrix_bounds(voxel_coord, matrix_dimension))
			return get_voxel_matrix_data_index(voxel_coord,matrix_dimension);
		else
			return -1;
	}

	// Determine if a point P of cartesian coordinte (x,y,z) is within the limits of
	// the dimensions of the voxel matrix that is stored in the computer memory
	//bool cartesian_coord_within_matrix_bounds(float x, float y, float z) {
	bool cartesian_coord_within_matrix_bounds(FVector matrix_origin, FIntVector3 matrix_dimension, FVector position, double voxel_size) {

		FIntVector3 voxel_coord = hcp_voxel_cell_coord_from_cartesian(matrix_origin, position,voxel_size);

		return cartesian_coord_within_matrix_bounds(voxel_coord, matrix_dimension);
	}

	// Determine if a point P of cartesian coordinte (x,y,z) is within the limits of
	// the dimensions of the voxel matrix that is stored in the computer memory
	bool cartesian_coord_within_matrix_bounds(FIntVector3 voxel_coord, FIntVector3 matrix_dimension) {
		if (voxel_coord.X < 0 || voxel_coord.Y < 0 || voxel_coord.Z < 0) return false;

		if (voxel_coord.Z % 2 == 0) {// even level
			if (voxel_coord.Y % 2 == 0) {// even row
				if (voxel_coord.X >= matrix_dimension.X) return false;
			}
			else {// odd row
				if (voxel_coord.X >= matrix_dimension.X - 1) return false;
			}
		}
		else {// odd level
			if (voxel_coord.Y % 2 == 0) {// even row
				if (voxel_coord.X >= matrix_dimension.X - 1) return false;
			}
			else {// odd row
				if (voxel_coord.X >= matrix_dimension.X) return false;
			}
		}

		if (voxel_coord.Y >= matrix_dimension.Y || voxel_coord.Z >= matrix_dimension.Z) return false;

		return true;
	}

	// Calculate and return the voxel matrix coordinate of a voxel cell for a given 
	// Cartesian coordinate (grid_x, grid_y, grid_z) within an even voxel grid matrix level
	FIntVector3 get_hcp_voxel_cell_coord_even_level(float grid_x, float grid_y, float grid_z, float voxel_height, int level, double voxel_size) {
		float grid_radius = voxel_size;
		float grid_height = grid_radius * (sqrt(3.0f));
		float c = grid_radius / (sqrt(3.0f));

		int row, column;

		if (grid_y < -1.0 / sqrt(3.0))
			row = (int)((grid_y - grid_height) / grid_height);
		else
			row = (int)(grid_y / grid_height);

		bool row_is_odd = abs(row % 2) == 1;

		if (row_is_odd) {
			column = (int)floor(grid_x / (voxel_size * 2));
		}
		else {
			column = (int)floor((grid_x + grid_radius) / (voxel_size * 2));
		}


		// Position of point relative to box it is in
		float rel_y = grid_y - (row * grid_height);
		float rel_x;
		float rel_z = grid_z - (level * voxel_height);

		if (row_is_odd) {
			rel_x = grid_x - ((column * (voxel_size * 2)) + grid_radius);
		}
		else {
			rel_x = grid_x - (column * (voxel_size * 2));
		}

		float m = 1.0f / sqrt(3.0f);


		// Work out if the point is above either of the hexagon's top edges
		if (rel_y >= (m * rel_x + 2.0 * c) && rel_x < 0) { // LEFT edge
			row++;
			if (!row_is_odd) { // Have even row
				column--;
				row_is_odd = true;
				rel_x = grid_x - ((column * (voxel_size * 2)) + grid_radius);
			}
			else
				rel_x = rel_x + grid_radius;

			rel_y = grid_y - (row * grid_height);
		}
		else {
			if (rel_y >= (-m * rel_x) + 2.0 * c && rel_x >= 0) {// RIGHT edge
				row++;
				if (row_is_odd) {
					column++;
					row_is_odd = false;
					rel_x = grid_x - (column * (voxel_size * 2));
				}
				else
					rel_x = rel_x - grid_radius;

				rel_y = grid_y - (row * grid_height);
			}
		}

		FIntVector3 voxel_coord;
		voxel_coord.X = column;
		voxel_coord.Y = row;


		// Get voxel z coord
		// Find distance to upper plane of the zone that the point exists in of the voxel
		// and if it is below the plane (ie distance negative) it is in the voxel, otherwise
		// it is in the neighbouring voxel of the upper level.

		float m0 = -1 / sqrt(3.0f);//slope of line in xy plane from point point 6 to point 3
		float m1 = 1 / sqrt(3.0f);//slope of line in xy plane from point point 5 to point 2

		FVector pq_vector = { rel_x,rel_y,rel_z - sqrt(1.5f) }; //distance vector from rel_z to top voxel vertex point.

		if (rel_x >= 0 && rel_y > m0 * rel_x) {// region 0 
			FVector normal_vector = { 1.0f,1.0f / sqrt(3.0f),(2.0f * sqrt(6.0f)) / 3.0f };

			if (distance_to_plane(normal_vector, pq_vector) < 0)
				voxel_coord.Z = level;
			else {
				voxel_coord.Z = level + 1;
				if (row_is_odd)	voxel_coord.X++;
			}

			return voxel_coord;
		}

		if (rel_y <= m0 * rel_x && rel_y < m1 * rel_x) {// region 1 
			FVector normal_vector = { 0.0f,-1.0f / sqrt(3.0f),(2.0f * sqrt(6.0f)) / 3.0f };

			if (distance_to_plane(normal_vector, pq_vector) < 0)
				voxel_coord.Z = level;
			else {
				voxel_coord.Y--;
				voxel_coord.Z = level + 1;
			}

			return voxel_coord;
		}

		if (rel_x < 0 && rel_y >= m1 * rel_x) {// region 2 
			FVector normal_vector = { -1.0f,-1.0f / sqrt(3.0f),(2.0 * sqrt(6.0f)) / 3.0f };

			if (distance_to_plane(normal_vector, pq_vector) < 0)
				voxel_coord.Z = level;
			else {
				voxel_coord.Z = level + 1;
				if (!row_is_odd) voxel_coord.X--;
			}

			return voxel_coord;
		}

		return voxel_coord; // Possible bug created by this ?????
	}

	// Calculate and return the voxel matrix coordinate of a voxel cell for a given 
	// Cartesian coordinate (grid_x, grid_y, grid_z) within an odd voxel grid matrix level
	FIntVector3 get_hcp_voxel_cell_coord_odd_level(float grid_x, float grid_y, float grid_z, float voxel_height, int level, double voxel_size) {
		float grid_radius = voxel_size;
		float grid_height = grid_radius * (sqrt(3.0f));
		float c = grid_radius / (sqrt(3.0f));

		int row;
		int column;

		if (grid_y < -1.0 / sqrt(3.0))
			row = (int)((grid_y - grid_height) / grid_height);
		else
			row = (int)(grid_y / grid_height);

		bool row_is_odd = abs(row % 2) == 1;

		column = (int)floor((grid_x + grid_radius) / (voxel_size * 2));

		// Position of point relative to box it is in
		float rel_y = grid_y - (row * grid_height);
		float rel_x;
		float rel_z = grid_z - (level * voxel_height);

		if (row_is_odd) {
			rel_x = grid_x - (column * (voxel_size * 2)) + grid_radius;
		}
		else {
			rel_x = grid_x - (column * (voxel_size * 2));
		}

		float m = 1.0f / sqrt(3.0f);

		// Work out if the point is above either of the hexagon's top edges
		if (rel_y >= (m * rel_x + 2.0 * c) && rel_x < 0) { // LEFT edge
			row++;
			if (row_is_odd) { // Have even row
				column--;
				row_is_odd = true;
				rel_x = grid_x - ((column * (voxel_size * 2)) + grid_radius);
			}
			else
				rel_x = rel_x + grid_radius;

			rel_y = grid_y - (row * grid_height);
		}
		else {
			if (rel_y >= (-m * rel_x) + 2.0 * c && rel_x >= 0) {// RIGHT edge
				row++;
				if (!row_is_odd) {
					column++;
					row_is_odd = false;
					rel_x = grid_x - (column * (voxel_size * 2));
				}
				else
					rel_x = rel_x - grid_radius;

				rel_y = grid_y - (row * grid_height);
			}
		}

		FIntVector3 voxel_coord;
		voxel_coord.X = column;
		voxel_coord.Y = row;


		// Get voxel z coord
		// Find distance to upper plane of the zone that the point exists in of the voxel
		// and if it is below the plane (ie distance negative) it is in the voxel, otherwise
		// it is in the neighbouring voxel of the upper level.

		float m0 = -1 / sqrt(3.0f);//slope of line in xy plane from point point 6 to point 3
		float m1 = 1 / sqrt(3.0f);//slope of line in xy plane from point point 5 to point 2

		FVector pq_vector = { rel_x,rel_y,rel_z - sqrt(1.5f) }; //distance vector from rel_z to top voxel vertex point.

		if (rel_x <= 0 && rel_y < m0 * rel_x) { //region 0
			FVector normal_vector = { -1.0f,-1.0f / sqrt(3.0f),(2.0 * sqrt(6.0f)) / 3.0f };

			if (distance_to_plane(normal_vector, pq_vector) < 0)
				voxel_coord.Z = level;
			else {
				voxel_coord.Z = level + 1;
				if (row_is_odd) voxel_coord.X--;
			}

			return voxel_coord;
		}

		if (rel_y >= m0 * rel_x && rel_y > m * rel_x) { //region 1
			FVector normal_vector = { 0.0f,1.0f / sqrt(3.0f),(2.0 * sqrt(6.0f)) / 3.0f };

			if (distance_to_plane(normal_vector, pq_vector) < 0)
				voxel_coord.Z = level;
			else {
				voxel_coord.Y++;
				voxel_coord.Z = level + 1;
			}

			return voxel_coord;
		}

		if (rel_x > 0 && rel_y <= m1 * rel_x) {// region 2 
			FVector normal_vector = { 1.0f,1.0f / sqrt(3.0f),(2.0 * sqrt(6.0f)) / 3.0f };

			if (distance_to_plane(normal_vector, pq_vector) < 0)
				voxel_coord.Z = level;
			else {
				voxel_coord.Z = level + 1;
				if (!row_is_odd) voxel_coord.X++;
			}

			return voxel_coord;
		}

		return voxel_coord; // Possible bug created by this ?????
	}

	// Calculate the distance to a plane in 3D space from a point P with directional vector pq_vector to a point
	// Q on a plane that has a normal vector on the plane normal_vector
	float distance_to_plane(FVector normal_vector, FVector pq_vector) {
		float normal_vector_length = sqrt(normal_vector.X * normal_vector.X + normal_vector.Y * normal_vector.Y + normal_vector.Z * normal_vector.Z);

		float normal_dot_pq = FVector::DotProduct(pq_vector, normal_vector);

		return normal_dot_pq / normal_vector_length;
	}

	// +++++++++++++++++++++++++++++++++++++++++




};


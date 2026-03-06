// Copyright 2026 Dominion
// Released under the GNU license

#pragma once

#include "CoreMinimal.h"

/*
	Definitions that define the parameters values and
	data types that define the generation and display
	of a 3D HCP voxel volume.
*/

//enum class data_storage_type_enum { red, green, blue, alpha, value };

//typedef int32 voxel_element_data_type; // For color r,g,b, and alpha or voxel value data type
typedef float voxel_element_data_type; // For color r,g,b, and alpha or voxel value data type

typedef int32 index_data_type;
typedef index_data_type voxel_data_type;

#define MAX_VOXEL_VERTICES    64000000 // On a 16 gig rig have this value as a safe number as testin reveals this uses about 10 gig memory.

// Ambition to change to type char with min value -127 max value 127
#define INVALID_VOXEL_VALUE -1
#define MIN_VOXEL_VALUE     1
#define MAX_VOXEL_VALUE     255

#define DEFAULT_ACTIVE_VALUE   255
#define DEFAULT_INACTIVE_VALUE 0 
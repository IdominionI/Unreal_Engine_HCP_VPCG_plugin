![alt text](Documentation/Screen_shot01.png)

## Unreal Engine Plugin HCP_VPCG

This is a small unreal engine plugin of an adaptation of the Virtual Worlds application/demonstration project that has been worked on and off on for the past several years.
It is considered that no further work on this can be performed and thus will not be progressed or maintained beyond this release. 

## Introduction

The HCP_VPCG unreal engine plugin consists of four additional nodes to be used within the unreal engine PCG graph editor to create and display 3D hexagonal close packing matrix grids and 2D hexagonal grids.
In addition are included are unreal engine static meshes of Trapezo-rhombic dodecahedral shapes used to display 3D hexagonal close packing matrix grids as voxel grids, and example PCG graphs to demonstrate how to use the HCP_VPCG nodes within unreal engine.

## Installation:
Make sure the Enreal Engine project that this plugin is to used in is closed.

Plugin installation
1: Copy the contents of the Plugins directory into the Unreal Engine projects Plugins directory. 

Just be careful that it seems that github may have incorrectly named this Plugins directory as Plugins/HCP_VPCG and the subdirectory as Source/HCP_VPCG and thus got the directory structure completely wrong
Check that the directory structure is

Plugins with subdirectory HCP_VCPG

This HCP_VCPG subdirectory has subdirectories Resouces and Source.

If this is not the case, github has failed to configure this repository correctly and thus needs to be configured manually after downloading by creating the correct directory structure and copying files into the correct directories.


2: Start the Unreal Engine projects and follow the prompts to load the HCP_VPCG plugin.

3: Select the HCP_VPCG plugin to be used within the Unreal Engine plugins widget.

Static Mesh Installation
Copy the contents of the Content/Meshes directory into the Unreal Engine projects Content/Meshes directory.

Example PCG graphs
Copy the contents of the Content/PCG_Graphs directory into the Unreal Engine projects Content/PCG_Graphs directory.

## Documentation
In the Documentation directory of this repository is a user guide in pdf format that gives detailed information on how to use this Unreal Engine plugin PCG nodes.

// Samutracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#define _CRTDBG_MAP_ALLOC  
//#include <stdlib.h>  
//#include <crtdbg.h>  
#pragma once
#include "pch.h"
#include <iostream>
#include <glm/glm.hpp>
#include <chrono>
#include "Ray.h"
#include "Sphere.h"
#include "Plane.h"
#include "Constants.h"
#include "World.h"
#include "MultiJitteredSampler.h"

int main()
{
	//MultiJitteredSampler m = MultiJitteredSampler();
	//m.generate_samples(64, 2);
	//m.print_samples();
	auto start = std::chrono::high_resolution_clock::now();
	World w = World();
	w.build();
	w.set_resolution(400, 400, .5);

	RawImage r2 = RawImage(w.view_plane, "csg_subtraction.bmp");
	w.render_scene_perspective(r2);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Elapsed time: " << elapsed.count() << std::endl;
	r2.export_image();

	//_CrtDumpMemoryLeaks();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

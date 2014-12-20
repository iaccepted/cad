#include <cstdio>
#include <iostream>
#include <fstream>
#include "output.h"
#include "model.h"

using namespace std;

double point[3] = { 1.0, 1.0, 1.0 };

int main()
{
	ElarOperator elar;
	Model model;
	Output out;

	model.create_model(elar);//read vertex and construct the halfedge structure
	out.write(elar);//output the data by the command

	return 0;
}

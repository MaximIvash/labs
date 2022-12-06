

#include <iostream>
#include "Func.hpp"
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	ifstream in("input.txt", ios::in);
	ofstream out("output.txt", ios::out);

	int numi;
	int numj;
	vector<int> maxMin(2);
	in >> numi;
	in >> numj;


	vector<vector<int>> matrix((int)numi);
	for (int i = 0; i < numi; i++) 
	{
		matrix[i].resize((int)numj);
	}

	mi::readFromFile(matrix);

	maxMin = mi::maxAndMinNumber(matrix);
	if (mi::sumOfDigits(maxMin[0]) == mi::sumOfDigits(maxMin[1])) 
	{
		sort(begin(matrix), end(matrix), mi::comp);
	}

	for (int i = 0; i < numi; i++) 
	{
		mi::cout_vector(matrix[i]);
	}

	mi::writeToFile(matrix);

	return 0;
}


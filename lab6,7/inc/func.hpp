#pragma once
#include <vector>

using namespace std;

namespace mi
{
	bool comp(vector<int> a, vector<int> b);

	int sumOfDigits(int num);

	vector<int> maxAndMinNumber(vector<vector<int>>& matrix);

	void readFromFile(vector<vector<int>>& matrix);

	void cout_vector(vector<int> vec);

	void writeToFile(vector<vector<int>>& matrix);
}
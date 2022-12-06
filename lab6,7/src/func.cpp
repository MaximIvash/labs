#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

namespace mi
{
    bool comp(vector<int> a, vector<int> b)
    {
        int sum_a = 0;
        int sum_b = 0;
        for (int i = 0; i < size(a); i++)
        {
            sum_a = a[i];
        }
        for (int i = 0; i < size(b); i++)
        {
            sum_b = b[i];
        }
        return a < b;
    }

    vector<int> maxAndMinNumber(vector<vector<int>>& matrix)
    {
        vector<int> ret(2);
        int max = INT_MIN;
        int min = INT_MAX;
        for (int i = 0; i < size(matrix); i++)
        {
            for (int j = 0; j < size(matrix[0]); j++)
            {
                if (max < matrix[i][j])
                    max = matrix[i][j];
                if (min > matrix[i][j])
                    min = matrix[i][j];
            }
        }
        ret.clear();
        ret.push_back(max);
        ret.push_back(min);
        return ret;
    }

    int sumOfDigits(int num)
    {
        int summ = 0;
        while (num > 0) 
        {
            summ += num % 10;
            num /=  10;
        }
        return summ;
    }

    void readFromFile(vector<vector<int>>& matrix)
    {

        ifstream in("input.txt", ios::in);
        int numi;
        int numj;
        in >> numi;
        in >> numj;
        int num = 0;

        for (int i = 0; i < numi; i++) 
        {
            for (int j = 0; j < numi; j++) 
            {
                in >> matrix[i][j];
            }
        }
    }

    void writeToFile(vector<vector<int>>& matrix) 
    {
        ofstream out("output.txt", ios::out);

        for (int i = 0; i < size(matrix); i++)
        {
            for (int j = 0; j < size(matrix[0]); j++)
            {
                out << matrix[i][j] << " ";
            }
            out << "\n";
        }

    }

    void cout_vector(vector<int> vec) 
    {
        for (int i = 0; i < size(vec); i++)
        {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }

}
        

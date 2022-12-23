// lab.9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

class Triangle
{
private:
    int s_a = 0;
    int s_b = 0;
    int s_c = 0;
    int s_per = 0;
public:
    bool sides(int a, int b, int c)
    {
        if ((a <= 0) || (b <= 0) || (c <= 0))
        {
            cout << "Wrong value of the side!" << endl;
            return false;
        }
        s_a = a;
        s_b = b;
        s_c = c;
    }
    
    void SumOfSides()
    {
        s_per = s_a + s_b + s_c;
    }
    int perimeter()
    {
        return s_per;
    }
};

int main()
{
    int A, B, C;
    cout << "Enter value of the sides" << endl;
    cin >> A >> B >> C;
    Triangle ABC;
    ABC.sides(A, B, C);
    ABC.SumOfSides();
    cout << "Perimeter ABC: " << ABC.perimeter() << endl;

}
 


#include <iostream>
#include "Matrix.h"

int main(int, char**) 
{
    Matrix<double> A;
    //A = values;
    A =     
    {
        {4, 4, 4},
        {4, 4, 4},
        {4, 4, 4}
    };

    Matrix<double> B;
    B =     
    {
        {4, 4, 4},
        {4, 4, 4},
        {4, 4, 4}
    };

    A[0][0] = 16;

    Matrix<double> C = A * B;

    A.Print();
    B.Print();
    C.Print();
}   


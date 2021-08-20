#include <iostream>
#include "Matrix.h"

int main(int, char**) 
{
    std::vector<std::vector<double>> values /*First row is y, second row is x */ =
    {
        {4, 4, 4},
        {4, 4, 4},
        {4, 4, 4}
    };


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

    A.Print();

    Matrix<double> C = A + B;

    C.Print();
    A.Print();
    B.Print();
    
    C = A;
    C.Print();

    /*
    A[1][2] = 3;
    std::cout << A[1][1] << std::endl;
    std::cout << A[1][2] << std::endl;
    */
}   


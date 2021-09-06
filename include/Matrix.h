#pragma once

#include <iostream>
#include <vector>

template<class T>
class DoubleSubscript
{
    private:
        std::vector<std::vector<T>> &values;   
        int j;

    public:
        DoubleSubscript(std::vector<std::vector<T>> &_values, int _j) : values(_values)
        {
            j = _j;
        }
        
        T &operator[](int i)
        {
            return values[j][i];
        }
        
};

template<class T>
class Matrix
{
    private:        
        std::vector<std::vector<T>> values; /*First row is y, second row is x */

    public:
        Matrix()
        {

        }

        Matrix(int m, int n)
        {
            values = std::vector<std::vector<T>>(m, std::vector<T>(n, 0));
        }

        Matrix(std::vector<std::vector<T>> _values)
        {
            values = _values;
        }

        int Rows()
        {
            return this->values.size();
        }

        int Cols()
        {
            return this->values[0].size();
        }

        void Fill(T fillValue)
        {
            for(int j = 0; j < this->Rows(); j++)
            {
                for(int i = 0; i < this->Cols(); i++)
                {
                    this->values[j][i] = fillValue;
                }
            }
        }

        void Print()  // Prints matrix making it easier to debug
        {
            for(int j = 0; j < this->Rows(); j++)
            {
                for(int i = 0; i < this->Cols(); i++)
                {
                    std::cout << values[j][i] << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";
        }

        Matrix<T> &operator=(std::vector<std::vector<T>> _values)
        {
            return *this = Matrix<T>(_values);
        }

        Matrix<T> operator+(Matrix<T> B)
        {
            Matrix<T> A(values);
            if(A.Rows() == A.Rows() && A.Cols() == B.Cols())
            {
                for(int j = 0; j < A.Rows(); j++)
                {
                    for(int i = 0; i < A.Cols(); i++)
                    {
                        A.values[j][i] = A.values[j][i] + B.values[j][i];
                    }
                }
            }
            else
            {
                std::cout << "Dimensions does not add up to perform addition \n";
            }

            return A;
        }

        Matrix<T> operator*(Matrix<T> B) // Matrix multiplication 
        {
            Matrix<T> A(this->values);
            if(A.Cols() == B.Rows())
            {
                Matrix<T> C(A.Rows(), B.Cols());
                
                for(int Aj = 0; Aj < A.Rows(); Aj++)
                {
                    for(int Bi = 0; Bi < B.Cols(); Bi++)
                    {
                        T sum = 0;
                        for(int calculateIndex = 0; calculateIndex < B.Cols(); calculateIndex++)
                        {
                            sum += A[Aj][calculateIndex] * B[calculateIndex][Bi];
                        }
                        C[Aj][Bi] = sum;
                    }
                }
                return C;
            }
            else
            {
                std::cout << "Matrix multiplication failed due to incorrect dimensions. \n";
            }
        }

        DoubleSubscript<T> operator[](int j)
        {
            DoubleSubscript<T> secondSubscript(values, j);
            return secondSubscript;
        }
};
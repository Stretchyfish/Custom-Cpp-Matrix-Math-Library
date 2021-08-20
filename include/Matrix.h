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

        };

        Matrix(std::vector<std::vector<T>> _values)
        {
            values = _values;
        }

        int rows()
        {
            return this->values.size();
        }

        int cols()
        {
            return this->values[0].size();
        }

        void Print()  // Prints matrix making it easier to debug
        {
            for(int j = 0; j < values.size(); j++)
            {
                for(int i = 0; i < values[j].size(); i++)
                {
                    std::cout << values[i][j] << " ";
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
            if(A.rows() == A.rows() && A.cols() == B.cols())
            {
                for(int j = 0; j < A.values.size(); j++)
                {
                    for(int i = 0; i < A.values[j].size(); i++)
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

        Matrix<T> operator*(Matrix<T> B)
        {
            Matrix<T> A(this->values);
            if(A.cols() == B.rows())
            {

            }
        }

        DoubleSubscript<T> operator[](int j)
        {
            DoubleSubscript<T> secondSubscript(values, j);
            return secondSubscript;
        }
};
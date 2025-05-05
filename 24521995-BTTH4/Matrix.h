#pragma once

#include <iostream>
#include <vector>
#include "Vector.h"

using namespace std;

// class Vector
// {
//     friend class Matrix;
//     private:
//         int n;
//         vector<int> vec;
//     public:
//         Vector(int n = 1);
//         Vector(int n, int k);
//         ~Vector();
        
//         void Nhap();
//         void Xuat() const;

//         int GetSize() const;
//         int GetMem(int i) const;
//         void SetMem(int i ,int value);

//         Vector operator+(const Vector &other) const;
//         Vector operator*(float a) const;
//         Vector* operator=(const Vector &other);

//         bool CanAdd(const Vector &other) const;

//         friend istream& operator>>(istream &is, Vector &v);
//         friend ostream& operator<<(ostream &os, const Vector &v);
// };

// Vector::Vector(int n) : n(n)
// {
//     vec.resize(n, 0);
// }

// Vector::Vector(int n, int k) : n(n)
// {
//     vec.resize(n, k);
// }

// Vector::~Vector(){}

// void Vector::Nhap()
// {
//     cout<<"Nhap so phan tu : ";cin>>n;
//     for(int i = 0; i < n; i++)
//         cin >> vec[i];
// }

// void Vector::Xuat() const
// {
//     for(int i = 0; i < n; i++)
//         cout << vec[i] << " ";
//     cout << endl;
// }

// int Vector::GetSize() const
// {
//     return n;
// }

// int Vector::GetMem(int i) const
// {
//     return vec[i];
// }

// void Vector::SetMem(int i ,int value)
// {
//     vec[i] = value;
// }

// bool Vector::CanAdd(const Vector &other) const
// {
//     return (this->n == other.n);
// }

// Vector Vector::operator*(float a) const
// {
//     Vector result(n);
//     for(int i = 0; i < n; i++)
//         result.vec[i] = vec[i] * a;
//     return result;
// }

// Vector Vector::operator+(const Vector &other) const
// {
//     Vector result(n);
//     if(!CanAdd(other))
//         return result;
    
//     for(int i = 0; i < n; i++)
//         result.vec[i] = vec[i] + other.vec[i];
//     return result;
// }

// Vector* Vector::operator=(const Vector &other)
// {
//     if(this != &other)
//     {
//         n = other.n;
//         vec.resize(n);
//         for(int i = 0; i < n; i++)
//             vec[i] = other.vec[i];
//     }
//     return this;
// }


class Matrix
{
    // friend class Vector;
    private:
        // m x n matrix
        int m ,n;
        vector<vector<int>> matrix;
    public:
        Matrix(int r = 1, int c = 1);
        Matrix(int r, int c ,int k);
        ~Matrix();
        
        void Nhap();
        void Xuat() const;

        int GetRow() const { return m; }
        int GetCol() const { return n; }

        Matrix operator+(const Matrix &other) const;
        Matrix operator*(float a) const;
        Matrix operator*(const Matrix &other) const;
        Vector operator*(const Vector &other) const;

        bool CanAdd(const Matrix &other) const;
        bool CanMultiply(const Matrix &other) const;

        friend istream& operator>>(istream &is, Matrix &v);
        friend ostream& operator<<(ostream &os, const Matrix &v);
};

Matrix::Matrix(int r, int c) : m(r), n(c)
{
    matrix.resize(m, vector<int>(n, 0));
}

Matrix::Matrix(int r, int c ,int k) : m(r), n(c)
{
    matrix.resize(m, vector<int>(n, 0));
    Nhap();
}

Matrix::~Matrix(){}

void Matrix::Nhap()
{
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
}

void Matrix::Xuat() const
{
    for(int i = 0; i < m; i++)
    {
        cout<<"  ";
        for(int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

bool Matrix::CanAdd(const Matrix &other) const
{
    int a = matrix[0][0] + 1;
    return (this->m == other.m && this->n == other.n);
}

bool Matrix::CanMultiply(const Matrix &other) const
{
    return (this->n == other.m);
}

Matrix Matrix::operator*(float a) const
{
    Matrix result(m, n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            result.matrix[i][j] = matrix[i][j] * a;
    return result;
}

Matrix Matrix::operator+(const Matrix &other) const
{
    Matrix result(m, n);
    if(!CanAdd(other))
    {
        cout << "Khong the cong hai ma tran nay!" << endl;
        return result;
    }
    for(int i = 0; i < m; i++)
        for(int j = 0; j < other.n; j++)
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
    return result;
}

Matrix Matrix::operator*(const Matrix &other) const
{
    Matrix result(m, other.n);
    if(!CanMultiply(other))
    {
        cout << "Khong the nhan hai ma tran nay!" << endl;
        return result;
    }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < other.n; j++)
            for(int k = 0; k < n; k++)
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];

    return result;
}

Vector Matrix::operator*(const Vector &other) const
{
    Vector result(m);
    if(this->m != other.GetSize())
    {
        return result;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            result.vec[i] += matrix[i][j] * other.vec[j];
    return result;
}

istream& operator>>(istream &is, Matrix &v)
{
    v.Nhap();
    return is;
}

ostream& operator<<(ostream &os ,const Matrix &v)
{
    v.Xuat();
    return os;
}
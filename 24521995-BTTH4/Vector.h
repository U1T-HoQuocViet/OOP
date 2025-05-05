#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Vector
{
    friend class Matrix;
    private:
        int n;
        vector<int> vec;
    public:
        Vector(int n = 1);
        Vector(int n, int k);
        Vector(const Vector &v);
        ~Vector();
        
        void Nhap();
        void Xuat() const;

        int GetSize() const;
        int GetMem(int i) const;
        void SetMem(int i ,int value);

        Vector operator+(const Vector &other) const;
        Vector operator*(float a) const;
        Vector* operator=(const Vector &other);

        bool CanAdd(const Vector &other) const;

        friend istream& operator>>(istream &is, Vector &v);
        friend ostream& operator<<(ostream &os, const Vector &v);
};

Vector::Vector(int n) : n(n)
{
    vec.resize(n, 0);
}

Vector::Vector(int n, int k) : n(n)
{
    vec.resize(n, k);
}

Vector::Vector(const Vector &v)
{
    n = v.n;
    vec.resize(n);
    for(int i = 0; i < n; i++)
        vec[i] = v.vec[i];
}

Vector::~Vector(){}

void Vector::Nhap()
{
    cout<<"Nhap phan tu : "<<endl;
    for(int i = 0; i < n; i++)
        cin >> vec[i];
}

void Vector::Xuat() const
{
    for(int i = 0; i < n; i++)
        cout << vec[i] << " ";
    cout << endl;
}

int Vector::GetSize() const
{
    return n;
}

int Vector::GetMem(int i) const
{
    return vec[i];
}

void Vector::SetMem(int i ,int value)
{
    vec[i] = value;
}

bool Vector::CanAdd(const Vector &other) const
{
    return (this->n == other.n);
}

Vector Vector::operator*(float a) const
{
    Vector result(n);
    for(int i = 0; i < n; i++)
        result.vec[i] = vec[i] * a;
    return result;
}

Vector Vector::operator+(const Vector &other) const
{
    Vector result(n);
    if(!CanAdd(other))
        return result;
    
    for(int i = 0; i < n; i++)
        result.vec[i] = vec[i] + other.vec[i];
    return result;
}

Vector* Vector::operator=(const Vector &other)
{
    if(this != &other)
    {
        n = other.n;
        vec.resize(n);
        for(int i = 0; i < n; i++)
            vec[i] = other.vec[i];
    }
    return this;
}

istream& operator>>(istream &is, Vector &v)
{
    v.Nhap();
    return is;
}

ostream& operator<<(ostream &os ,const Vector &v)
{
    v.Xuat();
    return os;
}
#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

class GiaSuc
{
    public: 
        virtual void Xuat() const;

        virtual string GetLoai() const = 0;
        virtual void TiengKeu() const = 0;

        virtual int SoLuongSinh() const = 0;
        virtual int SoLitSua() const = 0;

        
};


void GiaSuc::Xuat() const
{
    cout << "Loai: " << GetLoai() << endl;
    cout << "So luong sinh: " << SoLuongSinh() << endl;
    cout << "So lit sua: " << SoLitSua() << endl;
    cout << "------------------------" << endl;
}
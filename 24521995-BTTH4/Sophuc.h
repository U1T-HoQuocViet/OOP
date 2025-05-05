#pragma once

#include <iostream>
#include <math.h>

using namespace std;

class SoPhuc
{
    private:
        float thuc, ao;
    public:
        SoPhuc(float thuc = 0, float ao = 0);
        SoPhuc(const SoPhuc &sp);
        ~SoPhuc();
        
        void Nhap();
        void Xuat() const;
        
        float GetThuc() const;
        float GetAo() const;
        
        void SetThuc(float thuc);
        void SetAo(float ao);
        
        
        SoPhuc operator+(const SoPhuc &sp) const;
        SoPhuc operator-(const SoPhuc &sp) const;
        SoPhuc operator*(const SoPhuc &sp) const;
        SoPhuc operator/(const SoPhuc &sp) const;

        SoPhuc& operator=(const SoPhuc &sp);

        bool operator==(const SoPhuc &sp) const;
        bool operator!=(const SoPhuc &sp) const;

        friend istream& operator>>(istream &is ,SoPhuc &sp);
        friend ostream& operator<<(ostream &os ,const SoPhuc &sp);
};
SoPhuc::SoPhuc(float thuc, float ao) : thuc(thuc), ao(ao) {}
SoPhuc::SoPhuc(const SoPhuc &sp) : thuc(sp.thuc), ao(sp.ao) {}
SoPhuc::~SoPhuc() {}

void SoPhuc::SetThuc(float thuc) { this->thuc = thuc; }
void SoPhuc::SetAo(float ao) { this->ao = ao; }

float SoPhuc::GetThuc() const { return thuc; }
float SoPhuc::GetAo() const { return ao; }

void SoPhuc::Nhap()
{
    cin>>thuc>>ao;
}

void SoPhuc::Xuat() const
{
    if(thuc != 0)
        cout<<thuc;
    if(ao != 0)
        if(ao > 0)
            cout<<"+"<<ao<<"i";
        else
            cout<<ao<<"i";

}

SoPhuc SoPhuc::operator+(const SoPhuc &sp) const
{
    return SoPhuc(thuc + sp.thuc ,ao + sp.ao);
}

SoPhuc SoPhuc::operator-(const SoPhuc &sp) const
{
    return SoPhuc(thuc - sp.thuc ,ao - sp.ao);
}


SoPhuc SoPhuc::operator*(const SoPhuc &sp) const
{
    return SoPhuc(thuc * sp.thuc - ao * sp.ao ,thuc * sp.ao + ao * sp.thuc);
}

SoPhuc SoPhuc::operator/(const SoPhuc &sp) const
{
    float d = sp.thuc * sp.thuc + sp.ao * sp.ao;
    return SoPhuc((thuc * sp.thuc + ao * sp.ao) / d ,(ao * sp.thuc - thuc * sp.ao) / d);
}

SoPhuc& SoPhuc::operator=(const SoPhuc &sp)
{
    
    thuc = sp.thuc;
    ao = sp.ao;

    return *this;
}

bool SoPhuc::operator==(const SoPhuc &sp) const
{
    return (thuc == sp.thuc && ao == sp.ao);
}

bool SoPhuc::operator!=(const SoPhuc &sp) const
{
    return !(*this == sp);
}

istream& operator>>(istream &is ,SoPhuc& sp)
{
    sp.Nhap();
    return is;
}

ostream& operator<<(ostream &os ,const SoPhuc& sp)
{
    sp.Xuat();
    return os;
}

#include <iostream>

using namespace std;

int UocSoChungLN(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}

class PhanSo
{
    private:    
        int tuso;
        int mauso;

    public:

        PhanSo(int = 0, int = 1);
        PhanSo(const PhanSo &);
        ~PhanSo();

        int GetTuso() const { return tuso; }
        int GetMauso() const { return mauso; }

        bool KiemTraHopLe() const { return mauso != 0; }
        float GiaTri() const { return double(tuso)/mauso; }

        void Nhap();
        void RutGon();
        void Xuat() const;

        PhanSo operator+(const PhanSo & other);
        PhanSo operator-(const PhanSo & other);
        PhanSo operator*(const PhanSo & other);
        PhanSo operator/(const PhanSo & other);

        bool operator==(const PhanSo & other) const;

        bool operator>(const PhanSo & other) const;
        bool operator<(const PhanSo & other) const;

        // PhanSo& operator=(const PhanSo & other);

        friend istream& operator>>(istream &, PhanSo &);
        friend ostream& operator<<(ostream &, const PhanSo &);

} typedef PS;

PhanSo::PhanSo(int tuso, int mauso)
{
    this->tuso = tuso;
    if(mauso == 0)
        mauso = 1;
    this->mauso = mauso;
    RutGon();
}

PhanSo::PhanSo(const PhanSo &other) : tuso(other.tuso), mauso(other.mauso) {}
PhanSo::~PhanSo() {}

void PhanSo::Nhap()
{
    cout<<"Nhap phan so : "<<endl;
    do
    {
        cin>>tuso>>mauso; 
    } while (!KiemTraHopLe());
    RutGon();
}

void PhanSo::RutGon()
{
    if(tuso == 0)
    {
        return;
    }
    int ucln = UocSoChungLN(tuso ,mauso);

    mauso /= ucln;
    tuso /= ucln;

    if(mauso < 0)
    {
        tuso *= -1;
        mauso *= -1;
    }
}

void PhanSo::Xuat() const
{
    if(tuso == 0)
    {
        cout<<0<<endl;
        return;
    }

    if(mauso == 1)
        cout<<tuso;
    else
        cout<<tuso<<"/"<<mauso;
}

PhanSo PhanSo::operator+(const PhanSo &other)
{
    PhanSo result;
    result.tuso = this->tuso * other.mauso + this->mauso * other.tuso;
    result.mauso = this->mauso * other.mauso;
    result.RutGon();
    return result;
}

PhanSo PhanSo::operator-(const PhanSo &other)
{
    PhanSo result;
    result.tuso = this->tuso * other.mauso - this->mauso * other.tuso;
    result.mauso = this->mauso * other.mauso;
    result.RutGon();
    return result;
}

PhanSo PhanSo::operator*(const PhanSo &other)
{
    PhanSo result;
    result.tuso = this->tuso * other.tuso;
    result.mauso = this->mauso * other.mauso;
    result.RutGon();
    return result;
}

PhanSo PhanSo::operator/(const PhanSo &other)
{
    PhanSo result;
    result.tuso = this->tuso * other.mauso;
    result.mauso = this->mauso * other.tuso;
    if(result.mauso == 0)
        result.mauso = 1;
    result.RutGon();
    return result;
}

bool PhanSo::operator==(const PhanSo &other) const
{
    return (this->GiaTri() == this->GiaTri());
}

bool PhanSo::operator>(const PhanSo &other) const
{
    return (this->GiaTri() > this->GiaTri());
}
bool PhanSo::operator<(const PhanSo &other) const
{
    return (this->GiaTri() < this->GiaTri());
}

istream& operator>>(istream &is, PhanSo &ps)
{
    ps.Nhap();
    return is;
}

ostream& operator<<(ostream &os,const PhanSo &ps)
{
    ps.Xuat();
    return os;
}

#include <iostream>
#include <cmath>

using namespace std;

#define MAX 100

class Dathuc
{
    private:
        int bac;
        float heso[MAX];
    public:
        Dathuc(int = 0);
        ~Dathuc() {}

        void Nhap();
        void Xuat() const;

        float Calculate(float x) const;

        void CongDathuc(const Dathuc &d);
        void TruDaThuc(const Dathuc &d);
};

Dathuc::Dathuc(int n) { this->bac = n; }
void Dathuc::Nhap()
{
    cout << "Nhap he so cho da thuc bac " << bac << " : " << endl;
    for(int i = bac; i >= 0; i--)
    {
        cout << "Bac "<<i<<" :";cin >> heso[i];
    }   
}

void Dathuc::Xuat() const
{
    for(int i = bac; i >= 0; i--)
    {
        if(heso[i] != 0)
        {
            if(heso[i] > 0)
            {
                if(heso[i] == 1)
                    cout << (i != bac ? "+" : "") << (i != 0 ? "" : "1");
                else
                    cout<<(i != bac ? "+" : "")<<heso[i];
            }
            else
                if(heso[i] == -1)
                    cout << (i != 0 ? "-" : "-1");
                else
                    cout << heso[i];
                
            if(i == 1)
                cout << "x";
            else if(i == 0)
                cout << "";
            else
                cout << "x^" << i;
        }
    }
    cout << endl;
}

float Dathuc::Calculate(float x) const
{
    float s = 0;
    for(int i = bac; i >= 0; i--)
    {
        s += heso[i] * pow(x, i);
    }
    return s;
}

int min(int a, int b){ return (a < b) ? a : b;}

int max(int a, int b){ return (a > b) ? a : b;}

void Dathuc::CongDathuc(const Dathuc &d)
{
    bac = max(bac, d.bac);
    int _s = -1;
    for(int i = bac; i >= 0; i--)
    {
        heso[i] += d.heso[i];
        if(heso[i] != 0 && _s == -1)
            _s = i;
    }
    bac = _s;
}

void Dathuc::TruDaThuc(const Dathuc &d)
{
    bac = max(bac, d.bac);
    int _s = -1;
    for(int i = bac; i >= 0; i--)
    {
        heso[i] -= d.heso[i];
        if(heso[i] != 0 && _s == -1)
            _s = i;
    }
    bac = _s;
}

int main()
{
    Dathuc d1(4), d2(3);
    d1.Nhap();
    d2.Nhap();

    cout << "Da thuc 1: ";
    d1.Xuat();
    cout << "Da thuc 2: ";
    d2.Xuat();

    cout<<"Gia tri cua da thuc 1 tai x = 2: " << d1.Calculate(2) << endl;

    d1.CongDathuc(d2);
    cout << "Tong 2 da thuc: ";
    d1.Xuat();

    d1.TruDaThuc(d2);
    cout << "Hieu 2 da thuc: ";
    d1.Xuat();

    return 0;
}


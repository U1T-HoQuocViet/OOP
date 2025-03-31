#include <iostream>

using namespace std;


class SoPhuc
{
    private:    
        float thuc;
        float ao;

    public:
        void Nhap() 
        { 
            cin>>thuc>>ao; 
        }
        
        void Xuat()
        {
            if(thuc != 0)
            {
                cout<<thuc;
            }

            if(ao != 0)
            {
                if(ao > 0 && thuc != 0)
                    cout<<"+";
                cout<<ao<<"i";
            }
            cout<<endl;
        }

        SoPhuc operator+(SoPhuc other)
        {
            SoPhuc a;
            a.thuc = thuc + other.thuc;
            a.ao = ao + other.ao;
            return a;
        }
        SoPhuc operator-(SoPhuc other)
        {
            SoPhuc a;
            a.thuc = thuc - other.thuc;
            a.ao = ao - other.ao;
            return a;
        }
        SoPhuc operator*(SoPhuc other)
        {
            SoPhuc a;
            a.thuc = thuc*other.thuc - ao*other.ao;
            a.ao = thuc*other.ao + ao*other.ao;
            return a;
        }
        SoPhuc operator/(SoPhuc other)
        {
            SoPhuc a;
            float _t = other.thuc*other.thuc + other.ao*other.ao; 
            a.thuc = (thuc*other.thuc + ao*other.ao)/_t;
            a.ao = (ao*other.thuc - thuc*other.ao)/_t;
            return a;
        }
} typedef SP;


int main()
{
    SP a ,b;
    cout<<"Nhap so phuc A :"<<endl;a.Nhap();
    cout<<"Nhap so phuc B :"<<endl;b.Nhap();

    cout<<"Tong A va B: ";(a+b).Xuat();
    cout<<"Hieu A va B: ";(a-b).Xuat();
    cout<<"Tich A va B: ";(a*b).Xuat();
    cout<<"Thuong A va B: ";(a/b).Xuat();
}
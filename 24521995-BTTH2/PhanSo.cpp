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
        
        float Value()
        {
            return double(tuso)/mauso;
        } 

        bool KiemTraHopLe()
        {
            return mauso != 0;
        }

        void Nhap() 
        { 
            cout<<"Nhap phan so : "<<endl;
            do
            {
                cin>>tuso>>mauso; 
            } while (!KiemTraHopLe());
        }

        void RutGon()
        {
            // if(mauso == 0)
            // {
            //     cout<<"Khong hop le"<<endl;
            //     return;
            // }

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
        
        void Xuat()
        {
            // if(mauso == 0)
            // {
            //     cout<<"Khong hop le"<<endl;
            //     return;
            // }
            if(tuso == 0)
            {
                cout<<0<<endl;
                return;
            }
            RutGon();
        
            if(mauso == 1)
                cout<<tuso;
            else
                cout<<tuso<<"/"<<mauso;
        }

        PhanSo operator+(PhanSo other)
        {
            PhanSo a;
            a.tuso = tuso * other.mauso + other.tuso * mauso;
            a.mauso = mauso * other.mauso;
            return a;
        }
        PhanSo operator-(PhanSo other)
        {
            PhanSo a;
            a.tuso = tuso * other.mauso - other.tuso * mauso;
            a.mauso = mauso * other.mauso;
            return a;
        }
        PhanSo operator*(PhanSo other)
        {
            PhanSo a;
            a.tuso = tuso * other.tuso;
            a.mauso = mauso * other.mauso;
            return a;
        }
        PhanSo operator/(PhanSo other)
        {
            PhanSo a;
            a.tuso = tuso * other.mauso;
            a.mauso = mauso * other.tuso;
            return a;
        }

        void SoSanh(PhanSo other)
        {
            if(this->Value() > other.Value())
            {
                this->Xuat();
                cout<<" lon hon ";
                other.Xuat();
                cout<<endl;
            }
            else if(this->Value() == other.Value())
            {
                cout<<"Hai phan so bang nhau"<<endl;
            }
            else
            {
                this->Xuat();
                cout<<" be hon ";
                other.Xuat();
                cout<<endl;
            }
        }
} typedef PS;

int main()
{
    PhanSo a ,b;
    a.Nhap();
    cout<<"Phan so A :";a.Xuat();
    cout<<endl;
    b.Nhap();
    cout<<"Phan so B :";b.Xuat();
    cout<<endl;
    a.SoSanh(b);

    cout<<"Tong A va B : ";(a+b).Xuat();cout<<endl;
    cout<<"Hieu A va B : ";(a-b).Xuat();cout<<endl;
    cout<<"Tich A va B : ";(a*b).Xuat();cout<<endl;
    cout<<"Thuong A va B : ";(a/b).Xuat();cout<<endl;

}
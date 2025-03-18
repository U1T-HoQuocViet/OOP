#include "MyLib.cpp"

// thực hiện các toán tử đối với phân số
int main()
{
    PS ps_1 ,ps_2;
    cout<<"Nhap phan so 1 :"<<endl;
    NhapPS(ps_1);
    cout<<"Nhap phan so 2 :"<<endl;
    NhapPS(ps_2);

    cout<<"Tong 2 phan so : ";XuatPS(ps_1 + ps_2);
    cout<<"Hieu 2 phan so : ";XuatPS(ps_1 - ps_2);
    cout<<"Tich 2 phan so : ";XuatPS(ps_1 * ps_2);
    cout<<"Thuong 2 phan so : ";XuatPS(ps_1 / ps_2);
}
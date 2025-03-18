#include "MyLib.cpp"

//nhập và xuất phân số đã được rút gọn
int main()
{
    PS ps;
    cout<<"Nhap phan so : "<<endl;
    NhapPS(ps);
    cout<<"--> ";XuatPS(ps);
    return 0;
}
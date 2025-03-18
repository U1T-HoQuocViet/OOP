#include "MyLib.cpp"


//tìm phân số lớn hơn trong 2 phân số
int main()
{
    PS ps_1 ,ps_2;
    cout<<"Nhap phan so 1 :"<<endl;
    NhapPS(ps_1);
    cout<<"Nhap phan so 2 :"<<endl;
    NhapPS(ps_2);

    if(ps_1.Value() == ps_2.Value())
    {
        cout<<"Hai phan so bang nhau.";
        return 0;
    }
    cout<<"Phan so lon hon : ";
    if(ps_1.Value() > ps_2.Value())
        XuatPS(ps_1);
    else
        XuatPS(ps_2);

    return 0;
}
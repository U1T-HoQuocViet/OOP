// #include <iostream>
#include "MyLib.cpp"

// using namespace std;


// xuất ngày sau ngày cần tìm
void getNextDay(Date a)
{
    a.d += 1;
    if(a.d > getDay(a.m ,a.y))
    {
        a.d %= getDay(a.m ,a.y);
        a.m += 1;
    }

    if(a.m > 12)
    {
        a.m %= 12;
        a.y += 1;
    }
    cout<<"Ngay hom sau :"<<XuatNgay(a)<<endl;
}
// xuất ngày trước ngày cần tìm
void getPrevDay(Date a)
{
    a.d -= 1;
    if(a.d <= 0)
    {
        a.m -= 1;
        if(a.m <= 0)
        {
            a.y -= 1;
            a.m = 12;
        }
        a.d = getDay(a.m ,a.y);
    }
    
    cout<<"Ngay hom truoc :"<<XuatNgay(a)<<endl;
}

int main()
{

    Date a;
    cout<<"Nhap ngay"<<endl;
    NhapNgay(a);
    getNextDay(a);
    getPrevDay(a);

    cout<<"Thu tu ngay trong nam : "<<dateOfYear(a);
    return 0;
}

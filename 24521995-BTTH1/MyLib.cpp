#include <bits/stdc++.h>
// #include <iomanip>
// #include <iostream>
// #include <math.h>
// #include <vector>
// #include <string.h>

using namespace std;
#include <iostream>

using namespace std;


//--------------------------
struct PhanSo
{
    int tuso;
    int mauso;
    //tra ve gia tri phan so
    double Value()
    {
        return double(tuso)/mauso;
    }
} typedef PS;

PS operator+(PS ps_1 ,PS ps_2)
{
    PS a;
    a.tuso = ps_1.tuso * ps_2.mauso + ps_2.tuso * ps_1.mauso;
    a.mauso = ps_1.mauso * ps_2.mauso;
    return a;
}
PS operator-(PS ps_1 ,PS ps_2)
{
    PS a;
    a.tuso = ps_1.tuso * ps_2.mauso - ps_2.tuso * ps_1.mauso;
    a.mauso = ps_1.mauso * ps_2.mauso;
    return a;
}
PS operator*(PS ps_1 ,PS ps_2)
{
    PS a;
    a.tuso = ps_1.tuso * ps_2.tuso;
    a.mauso = ps_1.mauso * ps_2.mauso;
    return a;
}
PS operator/(PS ps_1 ,PS ps_2)
{
    PS a;
    a.tuso = ps_1.tuso * ps_2.mauso;
    a.mauso = ps_1.mauso * ps_2.tuso;
    return a;
}

//tìm ước chung lớn nhất của 2 số
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

//nhập tử và mẫu cho phân số
void NhapPS(PS & ps) 
{ 
    do
    {
        cin>>ps.tuso>>ps.mauso; 
    } while (ps.mauso == 0);
}

//rút gọn phân số bằng cách tìm ucln
void RutGonPS(PS & ps)
{
    if(ps.mauso == 0 || ps.tuso == 0)
    {
        cout<<"Khong hop le";
        return;
    }

    int ucln = UocSoChungLN(ps.tuso ,ps.mauso);

    ps.mauso /= ucln;
    ps.tuso /= ucln;

    if(ps.mauso < 0)
    {
        ps.tuso *= -1;
        ps.mauso *= -1;
    }    
}

//xuat giá trị của phân số dưới dạng tử/mẫu
void XuatPS(PS ps)
{
    if(ps.mauso == 0)
    {
        cout<<"Khong hop le";
        return;
    }
    if(ps.tuso == 0)
    {
        cout<<0<<endl;
        return;
    }

    RutGonPS(ps);

    if(ps.mauso == 1)
        cout<<ps.tuso;
    else
        cout<<ps.tuso<<"/"<<ps.mauso;

    cout<<endl;
}




//--------------------------------------
bool isAlpha(char c)//kiểm tra chữ cái
{
    return (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A');
}

bool isNum(char c)//kiểm trae chữ số
{
    return c <= '9' && c >= '0';
}

bool isSpace(char c)//kiểm tra khoảng trắng
{
    return c == ' ';
}

//---------------
struct Time
{
    int m ,h;
};
//nhập giờ và phút
void NhapGio(Time & t)
{
    cin>>t.h>>t.m;
}
//trả về chuỗi biểu thị thời gian (h:m)
string XuatGio(Time t)
{
    return to_string(t.h)+":"+to_string(t.m);
}

//kiểm tra tính hợp lệ của thời gian nhập vào
bool IsValid(Time t)
{
    if(t.h < 0 || t.h > 23)
        return false;
    if(t.m < 0 || t.m > 59)
        return false;
    return true;
}

//---------------------------------------------

struct Date
{
    int d ,m ,y;
};
//toán tử so sánh 2 ngày bằng nhau
bool operator==(Date a ,Date b)
{
    return (a.d == b.d) && (a.m == b.m) && (a.y == b.y);
}

//nhập ngày, tháng ,năm cụ thể
void NhapNgay(Date & date)
{
    // cout<<"Nhap ngay :"<<endl;
    cin>>date.d>>date.m>>date.y;
}

//trả chuỗi biểu thị ngày (d/m/y)
string XuatNgay(Date date)
{
    return to_string(date.d) + "/" + to_string(date.m) + "/" + to_string(date.y);
}

//trả về số ngày của tháng đó (tính cả năm nhuận)
int getDay(int m ,int y)
{
    int daysofmonth[]{31 ,28 ,31 ,30 ,31 ,30 ,31 ,31 ,30 ,31 ,30 ,31};
    if(m > 12 || m < 1)
        return -1;
    return daysofmonth[m - 1] + ((y%4 == 0 && y%100 != 0 && m == 2)?1:0);
}

//trả về thứ tự của ngày trong năm
int dateOfYear(Date date)
{
    int res = 0;
    for(int i = 1; i < date.m; i++)
        res += getDay(i ,date.y);
    return res + date.d;
}
//kiểm tra 1 ngày có hợp lệ không
bool IsValid(Date date)
{
    if(date.d < 0|| date.d > getDay(date.m ,date.y))
        return false;
    if(date.m < 0 || date.m > 12)
        return false;
    return true;
}

//kiểm tra khoảng cách giữa 2 ngày a và b
// nếu a > b trả về 0
int KhoangCachNgay(Date a ,Date b)
{
    int d_a = dateOfYear(a);
    int d_b = dateOfYear(b);
    if(a.y < b.y)
        return (b.y - a.y - 1) * 365 + (365 - d_a) + d_b;
    else
        return 0;
    return max(d_b-d_a ,0);
}
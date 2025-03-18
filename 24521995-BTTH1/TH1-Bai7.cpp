// #include <iostream>
// #include <vector>
// #include <string>
// #include <bits/stdc++.h>
// using namespace std;
#include "MyLib.cpp"


struct HocSinh
{
    string ten;
    float toan ,van ,anh;
    //tính điểm trung bình (toán * 2 + văn + anh)/4
    float dtb()
    {
        return (toan*2 + van + anh)/4;
    }

    //xếp loại dựa trên điểm trung bình
    string xeploai()
    {
        float _dtb = dtb();
        if(_dtb <= 10 && _dtb >= 8)
            return "Gioi";
        else if(_dtb >= 6.5)
            return "Kha";
        else if(_dtb >= 5)
            return "Trung Binh";
        return "Yeu"; 
    }

} typedef HS;

//kiểm tra tên hợp lệ
bool IsValidName(string s)
{
    for(char c : s)
    {
        if(!isAlpha(c) && !isSpace(c))
            return false;
    }
    return true;
}

//kiểm tra điểm hợp lệ
bool IsValidPoint(int i)
{
    return i <= 10 && i >= 0;
}

// nhập điểm cho học sinh 
void NhapDiem(string a ,float & diem)
{
    do
    {
        cout<<a;
        cin>>diem;
    }
    while(!IsValidPoint(diem));
}

//nhập thông tin học sinh
void NhapHS(HS & hs)
{
    cin.ignore();
    do
    {
        cout<<"Ten hoc sinh : ";
        getline(cin ,hs.ten);
    } while (!IsValidName(hs.ten));
    
    NhapDiem("Nhap diem toan : " ,hs.toan);
    NhapDiem("Nhap diem van : " ,hs.van);
    NhapDiem("Nhap diem anh : " ,hs.anh);
}

//nhập số học sinh và thông tin từng học sinh
void NhapDSHS(vector<HS> & dshs ,int & n)
{
    cout<<"So hoc sinh : ";
    cin>>n;
    
    for(int i = 0; i < n; i++)
    {
        HS temp;NhapHS(temp);
        dshs.push_back(temp);
    }
        
}

//Đầu vào : thông tin học sinh
//xuất thông tin học sinh bao gồm : tên , điểm trung bình và xếp loại
void XuatHS(HS hs)
{
    cout<<" + "<<hs.ten<<endl;
    cout<<"Diem trung binh : "<<hs.dtb()<<endl;
    cout<<"Xep loai : "<<hs.xeploai()<<endl;
    cout<<"------------------"<<endl;
}

//Đầu vào : danh sách học sinh
//xuất danh sách học sinh
void XuatDSHS(vector<HS> dshs)
{
    for(HS hs : dshs)
        XuatHS(hs);
}

//Đầu vào :  danh sách học sinh
// Đầu ra : học sinh có điểm TB cao nhất
// Tìm học sinh có điểm trung bình cao nhất
HS DTBCaoNhat(vector<HS> dshs ,int n)
{
    HS res = dshs[0];
    for(int i = 1; i < n; i++)
    {
        if(res.dtb() < dshs[i].dtb())
            res = dshs[i];
    }
    return res;
}


//Đầu vào : danh sách học sinh , tên của học sinh cần tìm
// Xuất ra thông tin của những học sinh cần tìm
void TimKiemTheoTen(vector<HS> dshs ,int n)
{
    cout<<" - Tim kiem hoc sinh theo ten :"<<endl;
    string search;
    cin.ignore();
    cout<<"Tim kiem : ";
    getline(cin ,search);
    transform(search.begin(), search.end(), search.begin(),::tolower);
    vector<HS> res;
    for(int i = 0; i < n; i++)
    {
        //kiểm tra tên cuối của học sinh có gần giống với thông tin nhập vào hay không
        size_t last = dshs[i].ten.find_last_of(' ');
        string last_name = dshs[i].ten.substr(last + 1);
        transform(last_name.begin(), last_name.end(), last_name.begin(),::tolower);
        if(last_name.find(search) != string::npos)
            res.push_back(dshs[i]);
    }

    for(HS hs : res)
        XuatHS(hs);

}


//Đầu vào : danh sách học sinh
//Xuất ra danh sách học sinh có điểm toán dưới 5
void DSHSDiemToanThapNhat(vector<HS> dshs ,int n)
{
    cout<<" - Danh sach hoc sinh co diem toan thap nhat : "<<endl;
    vector<HS> res;
    for(int i = 0; i < n; i++)
    {
        if(dshs[i].toan < 5)
            res.push_back(dshs[i]);
    }

    for(HS hs : res)
    {
        cout<<" + "<<hs.ten<<endl;
        cout<<"---> Diem toan : "<<hs.toan<<endl;
        cout<<"------------------"<<endl;
    }
}

int main()
{
    vector<HS> dshs;
    int n;
    NhapDSHS(dshs ,n);
    XuatDSHS(dshs);

    cout<<" - Hoc sinh co DTB cao nhat : "<<endl;
    XuatHS(DTBCaoNhat(dshs ,n));

    DSHSDiemToanThapNhat(dshs ,n);

    TimKiemTheoTen(dshs ,n);
}
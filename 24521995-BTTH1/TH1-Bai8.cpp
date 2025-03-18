#include "MyLib.cpp"

struct ChuyenBay
{
    string ma_chuyen_bay;
    Date ngay_bay;
    Time gio_bay;

    string noi_xuat_phat;
    string noi_den;
} typedef flight;

//kiểm tra mã chuyến bay có hợp lệ không
bool IsValid(string s)
{
    if(s.size() > 5)
        return false;

    for(int i = 0; i < s.size(); i++)
        if(!(isAlpha(s[i]) || isNum(s[i])))
            return false;
    return true;
}

//kiểm tra điểm đến có hợp lệ không
bool IsValidDest(string s)
{
    if(s.size() > 20)
        return false;

    for(int i = 0; i < s.size(); i++)
        if(!isAlpha(s[i]) && !isSpace(s[i]) )
            return false;
            
    return true;
}

//Nhập thông tin chuyến bay
void NhapChuyenBay(flight & flight)
{
    do
    {
        cout<<"Nhap ma chuyen bay : ";
        getline(cin ,flight.ma_chuyen_bay);
    }while(!IsValid(flight.ma_chuyen_bay));

    do
    {
        cout<<"Nhap ngay bay : "<<endl;
        NhapNgay(flight.ngay_bay);
    }while(!IsValid(flight.ngay_bay));

    do
    {
        cout<<"Nhap gio bay : "<<endl;
        NhapGio(flight.gio_bay);
    }while(!IsValid(flight.gio_bay));
    cin.ignore();
    do
    {
        cout<<"Nhap diem xuat phat : ";
        getline(cin ,flight.noi_xuat_phat);
    }while(!IsValidDest(flight.noi_xuat_phat));

    do
    {
        cout<<"Nhap diem den : ";
        getline(cin ,flight.noi_den);
    }while(!IsValidDest(flight.noi_den));
}

//Nhập danh sách chuyến bay
void NhapDSChuyenBay(vector<flight> & a ,int & n)
{
    cin>>n;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        flight temp;
        NhapChuyenBay(temp);
        a.push_back(temp);
    }
}

//Đầu vào : chuyến bay
//Xuất thông tin chuyến bay
void XuatChuyenBay(flight fl)
{
    cout<<" - Ma chuyen bay : "<<fl.ma_chuyen_bay<<endl;
    cout<<" - Thong tin chuyen bay :"<<endl;
    cout<<"  + Ngay bay : "<<XuatNgay(fl.ngay_bay)<<endl;
    cout<<"  + Gio bay  : "<<XuatGio(fl.gio_bay)<<endl;
    cout<<"  + Noi di / Noi den : "<<fl.noi_xuat_phat<<" / "<<fl.noi_den<<endl;
    cout<<"------------------------"<<endl;
}

//Đầu vào : danh sách chuyến bay
//Xuất danh sách và thông tin từng chuyến bay
void XuatDSChuyenBay(vector<flight> a)
{
    for(flight fl : a)
    {
        XuatChuyenBay(fl);
    }
}

//Đầu vào : nơi xuất phát cần tìm
//Xuất danh sách chuyến bay cần tìm 
void TimKiemTheoNoiDi(vector<flight> a)
{
    vector<flight> res;
    cout<<" * Tim kiem chuyen bay theo noi xuat phat : ";
    string search;
    getline(cin ,search);

    for(int i = 0; i < a.size(); i++)
        if(a[i].noi_xuat_phat == search)
            res.push_back(a[i]);

    XuatDSChuyenBay(res);
    // return res;
}

//Đầu vào : nơi đến cần tìm
//Xuất danh sách chuyến bay cần tìm 
void TimKiemTheoNoiDen(vector<flight> a)
{
    vector<flight> res;
    cout<<" * Tim kiem chuyen bay theo noi ha canh : ";
    string search;
    getline(cin ,search);

    for(int i = 0; i < a.size(); i++)
        if(a[i].noi_den == search)
            res.push_back(a[i]);
    
    XuatDSChuyenBay(res);
    // return res;
}

//Đầu vào : mã chuyến bay cần tìm
//Xuất danh sách chuyến bay cần tìm 
void TimKiemTheoMa(vector<flight> a)
{
    vector<flight> res;
    cout<<" * Tim kiem chuyen bay theo ma : ";
    string search;
    getline(cin ,search);

    for(int i = 0; i < a.size(); i++)
        if(a[i].ma_chuyen_bay == search)
            res.push_back(a[i]);

    XuatDSChuyenBay(res);
}

//Đầu vào : ngày bay và nơi đến cần tìm
//Xuất danh sách chuyến bay cần tìm 
void TimKiemTheoThoiGianVaDiemDenCuThe(vector<flight> a)
{
    vector<flight> res;
    cout<<" * Tim kiem chuyen bay theo thoi gian va diem den cu the "<<endl;    
    Date ngay_can_tim;
    cout<<"Ngay can tim : "<<endl;NhapNgay(ngay_can_tim);
    cin.ignore();
    string noi_di_can_tim;
    cout<<"Noi den can tim : ";getline(cin ,noi_di_can_tim);


    for(int i = 0; i < a.size(); i++)
        if(a[i].noi_den == noi_di_can_tim && a[i].ngay_bay == ngay_can_tim)
            res.push_back(a[i]);
    
    XuatDSChuyenBay(res);
    // return res;
}

//Đầu vào : danh sách chuyến bay cần sắp xếp
//Đầu ra : danh sách chuyến bay đã sắp xếp theo thời gian bay
vector<flight> SapXepChuyenBay(vector<flight> a)
{
    vector<flight> res;
    copy(a.begin() ,a.end() ,back_inserter(res));

    sort(res.begin() ,res.end() ,[](flight l ,flight r)
    {
        if(dateOfYear(l.ngay_bay) == dateOfYear(r.ngay_bay))
            return (l.gio_bay.h*60 + l.gio_bay.m) < (r.gio_bay.h*60 + r.gio_bay.m);
        return dateOfYear(l.ngay_bay) < dateOfYear(r.ngay_bay);
    });

    return res;
}

//Đầu vào : nơi xuất phát và nơi đến của chuyến bay cần tìm
//Đầu ra : danh sách chuyến bay đi từ nơi xuất phát và nơi đến cần tìm
void SoLuongChuyenBay(vector<flight> a)
{
    cout<<" * So luong chuyen bay theo noi xuat phat va diem den cu the"<<endl;
    string diem_xuat_phat;
    cout<<"Diem xuat phat : ";getline(cin ,diem_xuat_phat);
    string diem_den;
    cout<<"Diem den : ";getline(cin ,diem_den);

    int res = 0;
    for(int i = 0; i < a.size(); i++)
        if(a[i].noi_den == diem_den && a[i].noi_xuat_phat == diem_xuat_phat)
            res++;
    
    cout<<"--> Co "<<res<<" chuyen bay xuat phat tu "<<diem_xuat_phat<<" den "<<diem_den<<endl;
    // return res;
}

int main()
{
    int n;//cin>>n;
    vector<flight> a;

    NhapDSChuyenBay(a ,n);
    cout<<" * Danh sach chuyen bay da duoc sap xep :"<<endl;
    XuatDSChuyenBay(SapXepChuyenBay(a));

    TimKiemTheoMa(a);
    TimKiemTheoNoiDi(a);
    TimKiemTheoNoiDen(a);

    TimKiemTheoThoiGianVaDiemDenCuThe(a);
    SoLuongChuyenBay(a);

    return 0;
}

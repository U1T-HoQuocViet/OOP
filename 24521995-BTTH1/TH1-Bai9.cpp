#include "MyLib.cpp"

int Size(unsigned long long n)
{
    int i = 0;
    while(n != 0)
    {
        n/= 10;i++;
    }
        
    return i;
}

struct SoTietKiem
{
    string ma_so;
    string loai_tiet_kiem;
    string ten_khach_hang;
    unsigned long long CMND; //8 byte
    Date ngay_mo_so;
    int so_tien_gui;
}typedef STK;


//kiểm tra mã số hợp lệ 
bool IsValid(string s)
{
    if(s.size() > 5)
        return false;

    for(int i = 0; i < s.size(); i++)
        if(!isAlpha(s[i]) && !isNum(s[i]))
            return false;
    return true;
}

//kiểm tra tên hợp lệ
bool IsValidName(string s)
{
    if(s.size() > 30)
        return false;

    for(int i = 0; i < s.size(); i++)
        if(!(isAlpha(s[i]) || isSpace(s[i])))
            return false;
    return true;
}

//nhập thông tin số tài khoản
void NhapSTK(STK & stk)
{
    cin.ignore();
    do
    {
        cout<<"Nhap ma so : ";
        getline(cin ,stk.ma_so);
    }while(!IsValid(stk.ma_so));

    do
    {
        cout<<"Nhap loai tiet kiem : ";
        getline(cin ,stk.loai_tiet_kiem);
    }while(stk.loai_tiet_kiem.size() > 10);

    do
    {
        cout<<"Ten khach hang : ";
        getline(cin ,stk.ten_khach_hang);
    }while(!IsValidName(stk.ten_khach_hang));

    int size;
    do
    {
        cout<<"Nhap so CMND : ";
        cin>>stk.CMND;
        size = Size(stk.CMND);
    }while(!(size == 9 || size == 12));

    do
    {
        cout<<"Ngay mo so : "<<endl;
        NhapNgay(stk.ngay_mo_so);
    }while(!IsValid(stk.ngay_mo_so));

    do
    {
        cout<<"So tien can gui : ";
        cin>>stk.so_tien_gui;
    }while(stk.so_tien_gui <= 0);
}

//nhập danh sách và thông tin từng khách hàng
void NhapDSKhachHang(vector<STK> & a ,int & n)
{
    cout<<"So luong khach hang can mo so : ";cin>>n;
    for(int i = 0; i < n; i++)
    {
        STK temp;
        NhapSTK(temp);
        a.push_back(temp);
    }
}

//xuất dữ liệu khách hàng
void XuatDuLieuKH(STK stk)
{
    cout<<" - Ten khach hang : "<<stk.ten_khach_hang<<endl;
    cout<<"  + So CMND : "<<stk.CMND<<endl;
    cout<<"  + Ma so tiet kiem : "<<stk.ma_so<<endl;
    cout<<"  + Loai tiet kiem : "<<stk.loai_tiet_kiem<<endl;
    cout<<"  + Ngay mo so : "<<XuatNgay(stk.ngay_mo_so)<<endl;
    cout<<"  + So tien da gui : "<<to_string(stk.so_tien_gui)<<" (vnd)"<<endl;
    cout<<"---------------------------"<<endl;
}

//xuất danh sách và thông tin khách hàng
void XuatDSKH(vector<STK> a) 
{
    for(STK stk : a)
        XuatDuLieuKH(stk);
}

//Đầu vào : lãi suát(%)/năm và ngày hiện tại
// Đầu ra : lãi suât thu được
//tính lãi suất thu được dựa trên lãi suất năm và ngày hiện tại so với ngày gửi tiết kiệm
int LaiSuatThuDuoc(STK stk)
{
    cout<<"Nhap lai suat theo nam (%) : ";
    float lai_suat;cin>>lai_suat;

    Date ngay_hien_tai;
    cout<<"Nhap ngay hien tai : ";
    NhapNgay(ngay_hien_tai);

    int day_dist = KhoangCachNgay(stk.ngay_mo_so ,ngay_hien_tai);

    int temp;
    if(stk.loai_tiet_kiem == "dai han")
        temp = day_dist/(6*30);
    else if(stk.loai_tiet_kiem == "ngan han")
        temp = day_dist/30;

    float tien_lai = stk.so_tien_gui * (lai_suat/100 ) * (day_dist*30)/265.0;
    return tien_lai;
}

//Đầu vào : số CMND cần tìm
//tìm kiếm khách hàng dựa trên số CMND
void TimKiemTheoCMND(vector<STK> ds)
{
    cout<<"Nhap so CMND can tim : ";
    unsigned long long search;cin>>search;
    for(STK stk : ds)
        if(stk.CMND == search)
        {
            XuatDuLieuKH(stk);
            return;
        }
}

//Đầu vào : mã số thẻ cần tìm
//tìm kiếm thông tin KH dựa trên mã số tài khoản
void TimKiemTheoMaSo(vector<STK> ds)
{
    cout<<"Nhap ma so can tim : ";
    string search;
    getline(cin ,search);
    for(STK stk : ds)
        if(stk.ma_so == search)
        {
            XuatDuLieuKH(stk);
            return;
        }
}

//Đầu vào : ngày cần tìm
//Đầu ra : danh sách khách hàng mở thẻ trong ngày cụ thể
// tìm kiếm khách hàng mở thẻ trong ngày cần tìm
vector<STK> DanhSachNgayMoSTK(vector<STK> ds)
{
    vector<STK> res;
    cout<<"Nhap ngay mo so can liet ke : "<<endl;
    Date search;
    NhapNgay(search);
    for(STK stk : ds)
        if(stk.ngay_mo_so == search)
            res.push_back(stk);

    return res;
}

//sắp xếp danh sách khách hàng theo số tiền gửi 
void SapXepTheoSoTienGui(vector<STK> & ds)
{
    cout<<"Sap xep danh sach so tien gui giam dan"<<endl;
    sort(ds.begin() ,ds.end() ,[](STK l ,STK r)
    {
        return l.so_tien_gui > r.so_tien_gui; 
    });
}

//sắp xếp danh sách khách hàng theo ngày mở thẻ
void SapXepTheoNgayMoSo(vector<STK> & ds)
{
    cout<<"Sap xep danh sach theo ngay gui tang dan"<<endl;
    sort(ds.begin() ,ds.end() ,[](STK l ,STK r)
    {
        return KhoangCachNgay(l.ngay_mo_so ,r.ngay_mo_so) > 0;
    });
}



int main()
{
    vector<STK> a;int n;
    NhapDSKhachHang(a ,n);

    XuatDSKH(a);

    TimKiemTheoCMND(a);
    cin.ignore();
    TimKiemTheoMaSo(a);

    XuatDSKH(DanhSachNgayMoSTK(a));

    SapXepTheoNgayMoSo(a);
    XuatDSKH(a);

    SapXepTheoSoTienGui(a);
    XuatDSKH(a);

    return 0;
}
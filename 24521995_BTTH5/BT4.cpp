#include <vector>
#include "GiaoDichDat.h"
#include "GiaoDichCanHo.h"
#include "GiaoDichNhaPho.h"

int TrungBinhCanHoChungCu(vector<GiaoDichCanHo*>& ds_gd_canho) 
{
    if (ds_gd_canho.empty()) return 0;

    int tong = 0;
    for (GiaoDichCanHo* gd : ds_gd_canho) {
        tong += gd->ThanhTien();
    }
    return tong / ds_gd_canho.size();
}

GiaoDichNhaPho* TimGiaoDichNhaPhoCaoNhat(vector<GiaoDichNhaPho*>& ds_gd_nhapho) 
{
    GiaoDichNhaPho* max = nullptr;
    for (GiaoDichNhaPho* gd : ds_gd_nhapho) 
    {
        if (max == nullptr || max->ThanhTien() < gd->ThanhTien()) 
            max = gd;
    }
    return max;
}

bool KiemTraGiaoDich(GiaoDichBDS* gd)
{
    return (gd->GetNgayGiaoDich().GetMonth() == 12 && gd->GetNgayGiaoDich().GetYear() == 2024);

}

void XuatCacGiaoDich(vector<GiaoDichDat*>& ds_gd_dat, vector<GiaoDichCanHo*>& ds_gd_canho, vector<GiaoDichNhaPho*>& ds_gd_nhapho) 
{
    cout << " - Cac giao dich bat dong san vao thang 12 nam 2024 :\n";
    for(GiaoDichDat* gd : ds_gd_dat) 
        if(KiemTraGiaoDich(gd)) 
            cout << *gd;

    for(GiaoDichCanHo* gd : ds_gd_canho) 
        if(KiemTraGiaoDich(gd)) 
            cout << *gd;
    
    for(GiaoDichNhaPho* gd : ds_gd_nhapho) 
        if(KiemTraGiaoDich(gd)) 
            cout << *gd;



}



int main() {
    int n;
    vector<GiaoDichDat*> ds_gd_dat;
    vector<GiaoDichCanHo*> ds_gd_canho;
    vector<GiaoDichNhaPho*> ds_gd_nhapho;

    cout << " - Nhap so luong giao dich dat: "; cin >> n;cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "+ Nhap giao dich dat thu " << i + 1 << ":\n";
        GiaoDichDat* a = new GiaoDichDat;
        cin >> *a;
        ds_gd_dat.push_back(a);
    }

    cout << " - Nhap so luong giao dich can ho: "; cin >> n;cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "+ Nhap giao dich can ho thu " << i + 1 << ":\n";
        GiaoDichCanHo* a = new GiaoDichCanHo;
        cin >> *a;
        ds_gd_canho.push_back(a);
    }

    cout << " - Nhap so luong giao dich nha pho: "; cin >> n;cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "+ Nhap giao dich nha pho thu " << i + 1 << ":\n";
        GiaoDichNhaPho* a = new GiaoDichNhaPho;
        cin >> *a;
        ds_gd_nhapho.push_back(a);
    }

    cout << " - Tong so luong cac giao dich bat dong san : " << ds_gd_dat.size() + ds_gd_canho.size() + ds_gd_nhapho.size() << endl;

    cout << " - Trung binh thanh tien can ho chung cu: " << TrungBinhCanHoChungCu(ds_gd_canho) << endl;

    
    GiaoDichNhaPho* max_nhapho = TimGiaoDichNhaPhoCaoNhat(ds_gd_nhapho);
    if (max_nhapho) {
        cout << " - Giao dich nha pho co thanh tien cao nhat:\n"<< *max_nhapho;
    }

    XuatCacGiaoDich(ds_gd_dat, ds_gd_canho, ds_gd_nhapho);

    return 0;
}
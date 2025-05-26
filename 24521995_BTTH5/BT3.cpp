#include <vector>
#include "GiaoDichVang.h"
#include "GiaoDichNgoaiTe.h"

GiaoDichVang* TimGiaoDichCaoNhat(vector<GiaoDichVang*>& ds_gd)
{
    GiaoDichVang* max = nullptr;
    for(GiaoDichVang* gd : ds_gd)
        if(max == nullptr || max->ThanhTien() < gd->ThanhTien())
            max = gd;
        // else if(max->ThanhTien() < gd->ThanhTien())
        //     max = gd;
    return max;
}

GiaoDichNgoaiTe* TimGiaoDichEuroThapNhat(vector<GiaoDichNgoaiTe*>& ds_gd)
{
    GiaoDichNgoaiTe* min = nullptr;
    for(GiaoDichNgoaiTe* gd : ds_gd)
    {
        if(gd->GetLoaiTien() == "EUR")
        {
            if(min == nullptr || min->ThanhTien() > gd->ThanhTien())
                min = gd;
        }
    }
    return min;
}

void XuatGiaoDichCoThanhTienCao(vector<GiaoDichVang*>& ds_gd_vang, vector<GiaoDichNgoaiTe*>& ds_gd_ngoaite)
{
    cout << " - Cac giao dich vang co thanh tien cao hon 1000000000:\n";
    for(GiaoDichVang* gd : ds_gd_vang)
    {
        if(gd->ThanhTien() > 1000000000)
        {
            cout << *gd << "--> Thanh Tien : " << gd->ThanhTien() << endl;
        }
            
    }

    cout << " - Cac giao dich ngoai te co thanh tien cao hon 1000000000:\n";
    for(GiaoDichNgoaiTe* gd : ds_gd_ngoaite)
    {
        if(gd->ThanhTien() > 1000000000)
            cout << *gd << "--> Thanh Tien : " << gd->ThanhTien() << endl;
    }
}



int main()
{
    int n;
    vector<GiaoDichVang*> ds_gd_vang;
    vector<GiaoDichNgoaiTe*> ds_gd_ngoaite;

    cout << " - Nhap so luong giao dich vang: ";cin >> n;cin.ignore();
    for(int i = 0; i < n; i++)
    {
        cout << "+ Nhap giao dich vang thu " << i + 1 << ":\n";
        GiaoDichVang* a = new GiaoDichVang;
        cin>>*a;
        ds_gd_vang.push_back(a);
    }

    cout << " - Nhap so luong giao dich ngoai te: ";cin >> n;cin.ignore();
    for(int i = 0; i < n; i++) 
    {
        cout << "+ Nhap giao dich ngoai te thu " << i + 1 << ":\n";
        GiaoDichNgoaiTe* a = new GiaoDichNgoaiTe;
        cin>>*a;
        ds_gd_ngoaite.push_back(a);
    }

    GiaoDichVang* gd_cao_nhat = TimGiaoDichCaoNhat(ds_gd_vang);
    GiaoDichNgoaiTe* gd_euro_thap_nhat = TimGiaoDichEuroThapNhat(ds_gd_ngoaite);

    if(gd_cao_nhat)
    {
        cout << " - Giao dich vang co thanh tien cao nhat:\n";
        cout << *gd_cao_nhat;
    }

    if(gd_euro_thap_nhat)
    {
        cout << " - Giao dich ngoai te co thanh tien Euro thap nhat:\n";
        cout << *gd_euro_thap_nhat;
    }

    XuatGiaoDichCoThanhTienCao(ds_gd_vang, ds_gd_ngoaite);

    return 0;

}
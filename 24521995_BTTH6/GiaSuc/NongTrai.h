#pragma once

#include "Cuu.h"
#include "Bo.h"
#include "De.h"
#include <vector>
#include <iostream>

using namespace std;

class NongTrai
{
    private:
        vector<GiaSuc*> ds_gia_suc;
        int so_luong_gia_suc;

    public:
        ~NongTrai();

        void NhapDanhSachGiaSuc();

        void SoLuongTungLoai() const;
        int TongSoLitSuaDaCho() const;

};

NongTrai::~NongTrai()
{
    for (GiaSuc* gs : ds_gia_suc)
        delete gs;
    ds_gia_suc.clear();
}

void NongTrai::NhapDanhSachGiaSuc()
{
    cout << "Nhap so luong gia suc: ";
    cin >> so_luong_gia_suc;
    cin.ignore();
    for (int i = 0; i < so_luong_gia_suc; ++i)
    {
        int loai_gia_suc;
        cout << "Nhap loai gia suc (1: Cuu, 2: Bo, 3: De): ";
        cin >> loai_gia_suc;
        cin.ignore();
        GiaSuc* gs = nullptr;
        if (loai_gia_suc == 1)
            gs = new Cuu();
        else if (loai_gia_suc == 2)
            gs = new Bo();
        else if (loai_gia_suc == 3)
            gs = new De();
        else
        {
            cout << "Loai gia suc khong hop le! Vui long nhap lai.\n";
            --i;
            continue;
        }
        ds_gia_suc.push_back(gs);
    }
}

void NongTrai::SoLuongTungLoai() const
{
    int so_cuu = 0, so_bo = 0, so_de = 0;
    for (const GiaSuc* gs : ds_gia_suc)
    {
        if (gs->GetLoai() == "Cuu")
            so_cuu++;
        else if (gs->GetLoai() == "Bo")
            so_bo++;
        else if (gs->GetLoai() == "De")
            so_de++;
    }
    cout << "So luong Cuu: " << so_cuu << endl;
    cout << "So luong Bo: " << so_bo << endl;
    cout << "So luong De: " << so_de << endl;
}

int NongTrai::TongSoLitSuaDaCho() const
{
    int tong_sua = 0;
    for (const GiaSuc* gs : ds_gia_suc)
    {
        tong_sua += gs->SoLitSua();
    }
    return tong_sua;
}


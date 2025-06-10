#include "GiaSuc.h"

class Bo : public GiaSuc
{

    public:

        string GetLoai() const override;
        void TiengKeu() const override;

        int SoLuongSinh() const override;
        int SoLitSua() const override;
};

string Bo::GetLoai() const
{
    return "Bo";
}

void Bo::TiengKeu() const
{
    cout << "Bo keu mooooooooooooo" << endl;
}

int Bo::SoLuongSinh() const
{
    
    return rand() % 10 + 1;
}

int Bo::SoLitSua() const
{
    return rand() % 21;
}


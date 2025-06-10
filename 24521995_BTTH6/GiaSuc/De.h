#include "GiaSuc.h"

class De : public GiaSuc
{

    public:

        string GetLoai() const override;
        void TiengKeu() const override;

        int SoLuongSinh() const override;
        int SoLitSua() const override;
};

string De::GetLoai() const
{
    return "De";
}

void De::TiengKeu() const
{
    cout << "De keu ehhhhehhhhhhhh" << endl;
}

int De::SoLuongSinh() const
{
    
    return rand() % 10 + 1;
}

int De::SoLitSua() const
{
    return rand() % 11;
}


#include "GiaSuc.h"

class Cuu : public GiaSuc
{

    public:

        string GetLoai() const override;
        void TiengKeu() const override;

        int SoLuongSinh() const override;
        int SoLitSua() const override;
};

string Cuu::GetLoai() const
{
    return "Cuu";
}

void Cuu::TiengKeu() const
{
    cout << "Cuu keu beeehheeh" << endl;
}

int Cuu::SoLuongSinh() const
{
    
    return rand() % 10 + 1;
}

int Cuu::SoLitSua() const
{
    return rand() % 6;
}


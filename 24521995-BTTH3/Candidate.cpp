#include <vector>
#include "Date.cpp"

class Candidate
{
    private:
        int ma_sv;
        string name;
        Date birth;
        float toan, van, anh;
    public:
        Candidate(int = 0, string = "", Date = Date(), float = 0, float = 0, float = 0);
        Candidate(const Candidate &c);
        ~Candidate() {}

        void SetDiem(float toan = -1,float van = -1,float anh = -1) 
        { 
            this->toan = (toan == -1) ? this->toan : toan;
            this->van = (van == -1) ? this->van : van;
            this->anh = (anh == -1) ? this->anh : anh; 
        }

        int GetMaSV() const { return ma_sv; }
        string GetName() const { return name; }
        Date GetBirth() const { return birth; }
        float GetToan() const { return toan; }
        float GetVan() const { return van; }
        float GetAnh() const { return anh; }


        void Nhap();
        void Xuat() const;

        float TongDiem() const;

        friend istream &operator>>(istream &is, Candidate &c);
        friend ostream &operator<<(ostream &os, const Candidate &c);
};



Candidate::Candidate(int ma_sv, string name, Date birth, float toan, float van, float anh)
{
    this->ma_sv = ma_sv;
    this->name = name;
    this->birth = birth;
    this->toan = toan;
    this->van = van;
    this->anh = anh;
}

Candidate::Candidate(const Candidate &c)
{
    this->ma_sv = c.ma_sv;
    this->name = c.name;
    this->birth = c.birth;
    this->toan = c.toan;
    this->van = c.van;
    this->anh = c.anh;
}

void Candidate::Nhap()
{
    cout <<"Nhap thong tin sinh vien: " << endl;
    cout <<"+ Ma sinh vien: "; cin >> ma_sv;
    cout <<"+ Ho ten: "; cin.ignore(); getline(cin, name);
    cout <<"+ Ngay sinh: "<<endl; cin>>birth;
    cout <<"+ Diem toan: "; cin >> toan;
    cout <<"+ Diem van: "; cin >> van;
    cout <<"+ Diem anh: "; cin >> anh;
}

void Candidate::Xuat() const
{
    cout << "Ma sinh vien: " << ma_sv << endl;
    cout << "Ho ten: " << name << endl;
    cout << "Ngay sinh: " << birth << endl; 
    cout << "Diem toan: " << toan << endl;
    cout << "Diem van: " << van << endl;
    cout << "Diem anh: " << anh << endl;
}

float Candidate::TongDiem() const
{
    return (toan + van + anh);
}

istream &operator>>(istream &is, Candidate &c)
{
    c.Nhap();
    return is;
}

ostream &operator<<(ostream &os, const Candidate &c)
{
    c.Xuat();
    return os;
}


/// --------------------------
class ListCandidate
{
    private:
        vector<Candidate> dsCandidate;
    public:
        ListCandidate() {}
        ~ListCandidate() {}

        void Nhap();
        void Xuat() const;

        void XuatTheoDiem() const;
        Candidate SVDiemCaoNhat() const;

        void SapXepSVGiamDanTheoDiem();
};

void ListCandidate::Nhap()
{
    int n;
    cout << "Nhap so luong sinh vien: "; cin >> n;
    dsCandidate.resize(n);
    cin.ignore();
    for(int i = 0; i < n; i++)
        cin >> dsCandidate[i];
}

void ListCandidate::Xuat() const
{
    // cout << " - Danh sach sinh vien: " << endl;
    for(int i = 0; i < dsCandidate.size(); i++)
        cout << dsCandidate[i] << endl;
}

void ListCandidate::XuatTheoDiem() const
{
    cout << " - Danh sach sinh vien co diem tong diem >= 15: " << endl;
    for(int i = 0; i < dsCandidate.size(); i++)
        if(dsCandidate[i].TongDiem() >= 15)
            cout << dsCandidate[i] << endl;
}

Candidate ListCandidate::SVDiemCaoNhat() const
{
    int max = 0;
    for(int i = 1; i < dsCandidate.size(); i++)
        if(dsCandidate[i].TongDiem() > dsCandidate[max].TongDiem())
            max = i;
    return dsCandidate[max];
}

void ListCandidate::SapXepSVGiamDanTheoDiem()
{
    for(int i = 0; i < dsCandidate.size() - 1; i++)
        for(int j = i + 1; j < dsCandidate.size(); j++)
            if(dsCandidate[i].TongDiem() < dsCandidate[j].TongDiem())
                swap(dsCandidate[i], dsCandidate[j]);
}

int main()
{
    Candidate a;
    ListCandidate list;
    list.Nhap();
    cout << " - Danh sach sinh vien: " << endl;
    list.Xuat();
    // cout << " - Danh sach sinh vien co diem tong diem >= 15: " << endl;
    list.XuatTheoDiem();
    cout << " - Sinh vien co diem cao nhat: " << list.SVDiemCaoNhat().GetName() << endl;
    cout << " - Danh sach sinh vien sau khi sap xep giam dan theo diem: " << endl;
    list.SapXepSVGiamDanTheoDiem();
    list.Xuat();
}
#include <iostream>
#include <vector>
#include <cstdlib>
#include "util.cpp"

using namespace std;

class cArray
{
    private:
        vector<int> arr;
        int n;
        const int MAX_RANGE = 100;
    public:
        cArray();
        cArray(int);
        ~cArray();

        void TaoPhanTuNgauNhien(int);
        void Xuat() const;

        int Count(int) const;
        bool KiemTraTangDan() const;
        int SoLeNhoNhat() const;
        int SoNguyenToLonNhat() const;

        void SapXepTangDan();

};

cArray::cArray() {}
cArray::cArray(int n) 
{
    TaoPhanTuNgauNhien(n); 
}
cArray::~cArray() {}

void cArray::TaoPhanTuNgauNhien(int n)
{
    srand(time(0));
    this->n = n; 
    arr.resize(n);
    for(int i = 0; i < n; i++)
        arr[i] = rand()%MAX_RANGE + 1; // 1 -> 100
}

void cArray::Xuat() const
{
    cout << "Cac phan tu trong mang la: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int cArray::Count(int x) const
{
    int count = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] == x)
            count++;
    return count;
}

bool cArray::KiemTraTangDan() const
{
    for(int i = 0; i < n - 1; i++)
        if(arr[i] > arr[i + 1])
            return false;
    return true;
}

int cArray::SoLeNhoNhat() const
{
    int min = MAX_RANGE + 1;
    for(int i = 0; i < n; i++)
        if(arr[i] % 2 != 0)
            if(arr[i] < min)
                min = arr[i];
    return min;
}

int cArray::SoNguyenToLonNhat() const
{
    int max = -1;
    for(int i = 0; i < n; i++)
        if(IsPrime(arr[i]))
            if(arr[i] > max)
                max = arr[i];
    return max;
}

void cArray::SapXepTangDan()
{
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
}

int main()
{
    cArray arr(10);
    arr.Xuat();cout<<endl;
    cout << "So phan tu 5: " << arr.Count(5) << endl;
    cout << "Mang co tang dan: " << (arr.KiemTraTangDan() ? "Co" : "Khong") << endl;
    cout << "So le nho nhat: " << arr.SoLeNhoNhat() << endl;
    cout << "So nguyen to lon nhat: " << arr.SoNguyenToLonNhat() << endl;

    arr.SapXepTangDan();
    cout << "Mang sau khi sap xep tang dan: ";arr.Xuat();cout<<endl;

    return 0;
}
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

#define eps 1e-5
// #define long double ld

// Đầu vào : x
// Đầu ra : sin(x)
// tính sin(x) với độ chính xác eps
double Sin(double x)
{
    double giai_thua = 1;
    double luy_thua = x;

    double T = x;
    double res = x;

    // int Dau = 1;

    int i = 3;
    while(T > eps)
    {
        luy_thua *= x*x;
        giai_thua *= i*(i-1);

        T = luy_thua/giai_thua;
        // Dau *= -1;
        res += ((i/2 % 2)*-1 + 0.5) * 2 * T;
        // res += Dau * T;
        i += 2;
    }
    return res;
}

int main()
{
    float x;cin>>x;
    cout<<setprecision(5)<<"sin("<<x<<") = "<<Sin(x);
    return 0;
}

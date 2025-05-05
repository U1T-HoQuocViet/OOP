#include "Matrix.h"

int main()
{
    Matrix a(2 ,2) ,b(2 ,2);
    Vector c(2);
    cout<<"-Nhap ma tran A : "<<endl;cin>>a;
    cout<<"-Nhap ma tran B : "<<endl;cin>>b;
    cout<<"-Nhap Vector C : "<<endl;cin>>c;

    cout<<"A x C :"<<endl<<"  "<<a*c;
    cout<<"A x B : "<<endl<<a*b;
}
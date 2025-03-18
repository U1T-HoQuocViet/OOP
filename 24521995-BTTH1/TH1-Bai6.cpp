#include <iostream>
#include <vector>

using namespace std;
// nhập mảng và số phần tử
void NhapMang(int * a ,int n_a)
{
    for(int i = 0; i < n_a; i++)
        cin>>a[i];
}

//xuất mảng
void XuatMang(int * a ,int n_a)
{
    for(int i = 0; i < n_a; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}


// tìm số phần tử A là con của phần tử B
int main()
{
    
    int a[100] ,b[100] ,n_a ,n_b;
    int res = 0;

    vector<int> _s;

    cin>>n_a>>n_b;
    NhapMang(a ,n_a);
    NhapMang(b ,n_b);

    //lặp qua từng phần tử của mảng b
    for(int i = 0; i < n_b - n_a + 1;i++)
    {
        int p_a = 0,p_b = i;

        //khi phần tử của B trùng với giá trị đầu của A
        // thì lặp qua từng phần tử của A
        while(a[p_a] == b[p_b])
        {
            //nếu tới cuối phần tử của A thì tăng res lên 1
            //đồng thời lưu chỉ số đầu tiên trùng nhau
            if(p_a + 1 >= n_a)
            {
                res += 1;
                _s.push_back(i);
                break;
            }
            p_a++;
            p_b++;
        }
    }

    cout<<"A : ";XuatMang(a ,n_a);
    cout<<"B : ";XuatMang(b ,n_b);

    cout<<"So lan xuat hien : "<<res<<endl;

    if(res == 0)
        return 0;
    cout<<"Chi so cua nhung lan xuat hien : ";
    for(int a : _s)
        cout<<a<<" ";

    return 0;
}

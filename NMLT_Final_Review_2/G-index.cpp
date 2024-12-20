//Cre: Cao Minh Anh Khoa
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n,g=0;
    long long sum=0;
    cin>>n;
    vector<int>a(n);
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>=pow(i+1,2))
        {
            g=i+1;
        }
    }
    cout<<g;
    return 0;
}
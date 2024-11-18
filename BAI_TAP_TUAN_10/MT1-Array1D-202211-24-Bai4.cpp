#include <iostream>
#include<algorithm>
using namespace std;
int n, a[103], count_1, count_2;
int main()
{
    cin >> n;
    for(int i=0; i<n; ++i)   cin >> a[i];
    for(int i=0; i<n; ++i)
        if(a[i]!=0)
        {
            while (a[i]%2 == 0)
            {
                a[i]/=2;
                count_1++;
            }
            while (a[i]%5 == 0)
            {
                a[i]/=5;
                count_2++;
            }
        }
    cout << min(count_1, count_2);
    
}
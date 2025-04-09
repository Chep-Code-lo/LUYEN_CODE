#include <iostream>
#include<vector>
using namespace std;
const long long k = 1e6+1, MAXN = 1e9+7;
int n,x; 




long long result(const vector<long long> c)
{
    vector<long long> dp(x+1,0); dp[0] =1;
    if(n == 1) return (x % c[0] == 0)? 1:0;
    for(int i : c)
    {
        for(int j = i; j <= x;j++)
        {
            dp[j] = dp[j] + dp[j-i];
            dp[j] %= MAXN;
        }
    }
    return dp[x];
}

int main()
{
    cin >> n >> x;
    vector<long long> c(n);
    for(int i =0;i < n;i++) 
    {
        cin >> c[i];
        
    }
    cout << result(c);
    return 0;
}
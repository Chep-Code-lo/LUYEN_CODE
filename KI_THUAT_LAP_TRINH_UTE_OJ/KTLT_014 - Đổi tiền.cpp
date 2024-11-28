#include<iostream>
#include<vector>
using namespace std;
int n, m, a[105], dp[1000005], chose[1000005];
vector<int>count(105, 0);
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=m; ++i) dp[i] = 1e9, chose[i] = -1;
    dp[0] = 0;
    for(int i=1; i<=n; ++i)
        for(int j=a[i]; j<=m; ++j)
            if(dp[j] > dp[j-a[i]] + 1){
                dp[j] = dp[j-a[i]] + 1;
                chose[j] = i;
            }
    if(dp[m] == 1e9) cout << "-1";
    else{
        cout << dp[m] << "\n";
        /*int x = m;
        while(x > 0 && chose[x] != -1){
            count.push_back(a[chose[x]]);
            count[chose[x]]++;
            x -= a[chose[x]];
        }
        for(int i=1; i<=n; ++i){
            if(count[i] > 0)
                cout << a[i] << " "<< count[i] << "\n";
        }*/
    }
}


#include <bits/stdc++.h>
#include <vector>
//#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int main (){
    file_chuan("TASK");
    int n;
    cin>>n;
    int a[1001];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<bool> prime(100001,true);
    prime[0]=prime[1]=false;
    for (int i=2;i<=sqrt(100001);i++){
        if (prime[i]){
            for (int j=i*i;j<100001;j+=i){
                prime[j]=false;
            }
        }
    }
    vector<int> aftercheckprime;
    for (int i=0;i<n;i++){
        if (prime[a[i]]){
            aftercheckprime.push_back(a[i]);    
            // cerr<<a[i]<<" ";
        }
    }
    int len=aftercheckprime.size();
    if (aftercheckprime.empty()){
        cout<<0;
        return 0;
    }
    int res = 1;
    vector<int> dp(len,0);
    for (int i=0;i<len;i++){
        dp[i] = 1;
        for (int j=0;j<i;j++){
            if (aftercheckprime[i]>=aftercheckprime[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        res = max(res, dp[i]);
    }
    cout<<res;
    
}

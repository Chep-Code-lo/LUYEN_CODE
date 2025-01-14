//Author: Chép-Code-Lỏ
//Github: @Chep-Code-lo
#include<iostream>
#include<unordered_map>
//#define int long long
using namespace std;
const int N = 1e5;
int n, count, k;
long a[N+1];
unordered_map<int, int>freq;
signed main(){
    cin >> n >> k;
    for(int i=0; i<n; ++i)  cin >> a[i];
    for(int l=0,r=0; r<n; ++r){
       freq[a[r]]++;
        while(freq.size() > k){
            freq[a[l]]--;
            if(freq[a[l]] == 0) freq.erase(a[l]);
            l++;
        }
        count+=(r-l+1);
    }
    cout << count;
}
/*7 3
2 6 4 3 6 8 3*/
#include<iostream>
using namespace std;
int n, ans, a[1003];
int main(){
    cin >> n;
    //if(n == 1)  cout << 0;
    {
        for(int i=1; i<=n; ++i) cin >> a[i];
        for(int i=1; i<n; ++i){
            int count = 0;
            for(int j=i+1; j<=n; ++j)
                if(a[i] <= a[j]){
                    count++;
                    break;
                }
            if(count == 0) ans++;   
        }
    }
    cout << ans << "\n";

}
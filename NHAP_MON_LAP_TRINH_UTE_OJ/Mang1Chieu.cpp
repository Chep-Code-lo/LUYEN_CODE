#include<iostream>
#include<algorithm>
using namespace std;
bool is_prime(int x){
    if(x <= 1) return false;
    if(x <= 3) return true;
    if(x%2 == 0 || x%3 == 0) return false;
    for(int i=5; i*i<=x; i+=6)
        if(x%i == 0 || x%(i+2) == 0) return false;
    return true;
}
int n, flag_1, flag_0, minn = 1e9, a[102], b[102];
long long sum_prime;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i){
        if(abs(a[i]) < abs(minn) && a[i] != 0)
            minn = a[i];
        cout << a[i] << " ";
    }  
    cout << "\n";
    for(int i=0; i<n; ++i){
        b[i] = a[i];
        if(is_prime(a[i])){
            sum_prime += a[i];
            cout << a[i] << " ";
        } 
    }
    if(sum_prime == 0)  cout << "KHONG CO";
    cout << "\n" << sum_prime << "\n";
    if(minn == 1e9) cout << "KHONG CO" << "\n";
    else cout << minn << "\n";
    bool check = true;
    for(int i=1; i<n; ++i)
        if(a[i] < a[i-1]){
            check = false;
            break;
        }
    if(check)   cout << "TANG" << "\n";
    if(!check)  cout << "KHONG TANG" << "\n";
    sort(a, a+n, greater<int>());
    for(int i=0; i<n; ++i)
        cout << a[i] << " ";
}
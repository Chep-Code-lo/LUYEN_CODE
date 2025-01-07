#include<iostream>
#include<vector>
#define int long long
using namespace std;
int d;
bool check_d(vector<int>&a){
    int n = a.size();
    if(n < 2) return true;
    int d = a[1] - a[0];
    for(int i=2; i<n; ++i)
        if(a[i] - a[i-1] != d)  return false;
    return true;
}
int count(int d){
    int cnt = 0;
    for(int i=0; i<=d; ++i){
        int hour = 12 + (i/60);
        int minutes = i%60;
        if(hour > 12) hour -= 12;
        vector<int>digits;
        if(hour < 10)   digits.push_back(hour);
        else{
            digits.push_back(hour/10);
            digits.push_back(hour%10);
        }
        if(minutes < 10){
            digits.push_back(0);
            digits.push_back(minutes);
        }
        else{
            digits.push_back(minutes/10);
            digits.push_back(minutes%10);
        }  
        if(check_d(digits)) cnt++;
    }
    return cnt;
}
signed main(){
    cin >> d;
    if(d <= 720)
        cout << count(d);
    else{
        int x = d/720;
        int r = count(d%720);
        cout << x*count(720) + r;
    }
}
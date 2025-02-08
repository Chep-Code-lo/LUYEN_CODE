#include<iostream>
using namespace std;
int n, cnt, a[21];
long long s;
void backtrack(int pos, long long sum, int temp){
    if(pos == n){
        if(temp && sum == s)    cnt++;
        return;
    }
    backtrack(pos+1, sum, temp);
    backtrack(pos+1, sum+a[pos], 1);
}
int main(){
    cin >> n >> s;
    for(int i=0; i<n; ++i)  cin >> a[i];
    backtrack(0,0,0);
    cout << cnt;
}
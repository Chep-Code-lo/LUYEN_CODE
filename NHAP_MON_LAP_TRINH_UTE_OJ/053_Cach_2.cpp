#include<iostream>
#include<algorithm>
using namespace std;
struct Data
{
    int st, end;
    bool operator<(const Data &other) const{
        return st < other.st;
    }
}a[600000];
int n, m, cnt, indexx;
long long ans;
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        int s, t; cin >> s >> t;
        if(s > t){
            a[indexx++] = {t, 0};
            a[indexx++] = {s, 1}; 
        }
    }
    sort(a, a+indexx);
    for(int i=0; i<indexx; ++i){
        if(cnt > 0) ans += a[i].st - a[i-1].st;
        if(a[i].end == 0) cnt++;
        else cnt--;
    }
    cout << m + 2LL*ans;
}

//Author: Chép-Code-Lỏ
//Github: @Chep-Code-lo
#include<iostream>
#define int long long
using namespace std;
int W, H, N;
bool check(int mid){
    int w = mid/W;
    int h = mid/H;
    return w*h >= N;
}
signed main(){
    cin >> W >> H >> N;
    int l=0, r=17;
    /*while(!check(r)) r *= 2;
    r++;
    cout << r;*/
    while(r-l > 1){
        int mid = (l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }
    cout << r;
}
/*2 3 10*/
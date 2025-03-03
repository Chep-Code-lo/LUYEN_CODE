
#include <iostream>
#include <vector>
#include <algorithm>
//#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int x, k;
vector<int> arr = {10, 5, 8, 3, 2, 7, 6, 4}; 
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
    x = 4, k = 8;
}
bool linear_search(int target){
    for(int i=0; i<arr.size(); ++i)
        if(arr[i] == target)
            return true;
    return false;
}
bool binary_search(int target){
    sort(arr.begin(), arr.end());
    int l = 0, r = arr.size()-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(arr[mid] == target)
            return true;
        else if(arr[mid] < target)
            l = mid + 1;
        else r = mid - 1;
    }
    return false;
}
void solve(){
    faster
    //file("");
    input();
    if(linear_search(x))
        cout << "Tìm thấy bằng linear serch\n";
    else cout << "Không tìm thấy bằng linear serch\n";
    if(binary_search(k))
        cout << "Tìm thấy bằng binary serch\n";
    else cout << "Không tìm thấy bằng binary serch\n";

}
signed main(){
    solve();
    time();
}

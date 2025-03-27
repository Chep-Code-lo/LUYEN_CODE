#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
/*  Ý tưởng : - Ta sẽ luôn chọn trạm xa nhất để tiết kiệm nhiên liệu vì chỉ khi đi tối đa C km cho phép thì sẽ rút ngắn số lần tiếp nhiên liệu
             - Nếu không tìm được trạm nào đó phù hợp -> không thể đi hết
             - Nếu dừng ở trạm nào đó mà chưa đi hết quãng đường -> tăng số lần tiếp nhiên liệu
    Thuật toán : - Ta thêm điểm xuất phát và đích đến 
                 - Tìm trạm xa nhất có thể đi được trong phạm vi C km
                 - Không thể tiến thêm nữa -> không thể đến đích - > ans = -1
                 - Tìm được trạm phù hợp -> tăng số lần tiếp nhiên liệu

*/
int min_refuels(int n, int L, int C, vector<int>& stations){
    stations.insert(stations.begin(), 0);  
    stations.push_back(L);  
    int refuels = 0;  
    int current_position = 0;  
    while(current_position < L){
        int next_position = current_position;
        for(int i = 0; i < stations.size(); ++i)
            if(stations[i] <= current_position + C) next_position = stations[i];
            else break;
        if(next_position == current_position) return -1;  
        if(next_position < L) refuels++;
        current_position = next_position;
    }
    return refuels;
}
int n, L, C;
vector<int> stations;
void input(){
    cin >> n >> L >> C;
    stations.resize(n);
    for(int i = 0; i < n; ++i) cin >> stations[i];
}
void solve(){
    int result = min_refuels(n, L, C, stations);
    cout << result << endl;
}
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
signed main(){
    faster  
    input();  
    solve();  
    time();   
}

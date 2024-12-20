#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long long m, pos_start, pos_end, sum_dis, ans;
vector<pair<long long, long long>> cur;
vector<pair<long long, long long>> add;
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        long long st, end; cin >> st >> end;
        if(st > end)    add.push_back({end, st});
    }  
    sort(add.begin(), add.end());
    if(!add.empty()){
        pos_start = add[0].first, pos_end = add[0].second;
        for(int i=1; i<(int)add.size(); ++i){
            long long start = add[i].first, end = add[i].second;
            if(start <= pos_end){
                if(end > pos_end) pos_end = end;
            }else{
                cur.push_back({pos_start, pos_end});
                pos_start = start;
                pos_end = end;
            }
        }
        cur.push_back({pos_start, pos_end});
        //cout << pos_start << " " << pos_end << "\n";
    }
    //for(auto it : cur)
        //cout << it.first << " " << it.second << "\n";
    for(auto it : cur)
        sum_dis += (it.second - it.first);
    ans = m + 2LL*sum_dis;
    cout << ans;
}
/*8 15
1 12
3 1
3 9
4 2
7 13
12 11
14 11
14 13*/
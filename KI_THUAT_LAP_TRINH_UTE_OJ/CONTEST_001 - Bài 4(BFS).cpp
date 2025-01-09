#include<bits/stdc++.h>
using namespace std;
int n, m, k, matrix[1000][1000];
vector<pair<int, int>>add;
bool compare(pair<int, int>&a, pair<int, int>&b){
    if(a.first != b.first)  return a.first < b.first;
    return a.second < b.second;

}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)  cin >> matrix[i][j];
    cin >> k;
    for(int i=0; i<n; ++i){
        int count=0;
        for(int j=0; j<m; ++j)  count += matrix[i][j];
        add.push_back({count, i+1});
    }
    sort(add.begin(), add.end(), compare);
    cout << add[k-1].second;
}
/*4 4
1 0 0 0 
1 1 1 1
1 0 0 0
1 1 0 0
2
*/
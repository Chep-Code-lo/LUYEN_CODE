#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int t, n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; ++i){
            int x; cin >> x;
            pq.push(x);
        } 
        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int res = (x+y)/2;
            pq.push(res);
        }
        cout << pq.top() << "\n";
    }
}
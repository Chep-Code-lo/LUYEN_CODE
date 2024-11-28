#include<iostream>
using namespace std;
int h, W, res, left_h[505], right_h[505], w[505];
int main(){
    cin >> h >> W;
    for(int i=0; i<W; ++i)  cin >> w[i];
    left_h[0] = w[0];
    for(int i=0; i<W; ++i)
        left_h[i] = max(left_h[i-1], w[i]);
    /*for(int i=0; i<W; ++i)
        cout << left_h[i] << " ";*/
    right_h[W-1] = w[W-1];
    for(int i=W-2; i>=0; --i)
        right_h[i] = max(right_h[i+1], w[i]);
    /*for(int i=0; i<W; ++i)
        cout << right_h[i] << " ";*/
    for(int i=0; i<W; ++i)
        if(min(left_h[i], right_h[i]) - w[i] > 0)
            res += min(left_h[i], right_h[i]) - w[i];
    cout << res;

}
/*
4 4
3 0 1 4

left 3 3 3 4 

4 4 4 4 right

*/
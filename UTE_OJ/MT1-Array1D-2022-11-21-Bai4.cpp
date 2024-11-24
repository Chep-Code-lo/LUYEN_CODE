#include <iostream>
using namespace std;
int n, count, pos = -1, maxx, arr[103];
int main() {
    cin >> n;
    for(int i=0; i<n; ++i) cin >> arr[i];
    for(int i=0; i<n; ++i)
        for(int j=i+1; j<n; ++j){
            if(arr[i] == arr[j]) count++;
            if(count > maxx){
                maxx = count;
                pos = i;
            }
        }
    cout << pos;
}

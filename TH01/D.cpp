#include<iostream>
#include<vector>
using namespace std;
int n, pos = -1e9, pos_1;
float a[303], x;
vector<int>b;
int main(){
    cin >> n >> x;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i)
        if(x == a[i])
            pos = i;
    if(pos != -1e9)
        cout << pos;
    else{
        if(x < a[0]){
            cout << x << " ";
            for(int i=1; i<n; ++i)
                cout << a[i] << " ";
        }
        else if(x > a[n-1]){
            for(int i=0; i<n-1; i++)
                cout << a[i] << " ";
            cout << x;
        }
        else{
            for(int i=0; i<n; ++i){
                if(x > a[i])
                    b.push_back(a[i]);
                if(x < a[i]){
                    b.pop_back();
                    b.push_back(x);
                    b.push_back(a[i+1]);
                    pos_1 = i+1;
                    break;
                }
            }
            for(int i=pos_1+1; i<n; ++i)
                b.push_back(a[i]);
            for(auto x : b)
                cout << x << " ";
        }
    }
}
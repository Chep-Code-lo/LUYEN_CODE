#include<iostream>
using namespace std;
bool Symmetry_Number(int x){
    int reverse = 0, temp = x;
    while(x){
        reverse = reverse*10 + x%10;
        x /= 10;
    }
    return reverse == temp;
}
int n, x, maxx = -1;
int main(){
    cin >> n;
    for(int x, i=0; i<n; ++i) cin >> x, maxx = max(maxx, Symmetry_Number(x) ? x : -1);
    cout << maxx; 
}
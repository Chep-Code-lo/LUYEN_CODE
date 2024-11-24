#include<iostream>
using namespace std;
int limit, pos, maxx, arry[1003];
bool check_1 = true, check_2 = true;
int main(){
    cin >> limit;
    for(int i=0; i<limit; ++i) cin >> arry[i], maxx = max(maxx, arry[i]);
    for(int i=limit-1; i>=0; --i)
        if(maxx == arry[i]){
            pos = i;
            break;
        }
    for(int i=0; i<pos; ++i)
        if(arry[i] >= arry[i+1]){
            check_1 = false;
            break;
        }
    for(int i=pos; i<limit-1; ++i)
        if(arry[i] <= arry[i+1]){
            check_2 = false;
            break;
        }
    cout << (check_1 && check_2 ? "YES" : "NO");
}
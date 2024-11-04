#include<iostream>
#include<algorithm>
using namespace std;
int limit, arry[1003];
int main(){
    cin >> limit;
    for(int i=0; i<limit; ++i) cin >> arry[i];
    sort(arry, arry+limit);
    for(int i=limit-2; i>=0; --i)
        if(arry[limit-1] != arry[i]){
            cout << arry[i];
            break;
        }
}
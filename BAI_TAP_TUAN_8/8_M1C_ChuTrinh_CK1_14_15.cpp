#include<iostream>
using namespace std;
int limit, unknown, arry[102];
int main(){
    cin >> limit >> unknown;
    for(int i=0; i<limit; ++i) cin >> arry[i];
    if(arry[0] != arry[limit-1]){
        cout << "-1";
        return 0;
    }
    else{
        unknown =unknown%limit;
        for(int i=unknown; i<limit; ++i)
            cout << arry[i] << " ";
        for(int i=1; i<=unknown; ++i)
            cout << arry[i] << " ";
    }
}
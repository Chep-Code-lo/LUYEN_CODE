#include<iostream>
using namespace std;
int limit, count, index = 1, arry_1[1003], arry_2[1003];
int main(){
    cin >> limit;
    for(int i=1; i<=limit; ++i) cin >> arry_1[i];
    for(int i=limit; i>=1; --i)
        arry_2[index++] = arry_1[i]; 
    for(int i=1; i<=limit; ++i)
        if(arry_1[i] != arry_2[i]){
            count++;
            break;
        } 
    cout << (count == 0 ? "YES" : "NO");
}
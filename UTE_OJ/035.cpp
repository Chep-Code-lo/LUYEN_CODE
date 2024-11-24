#include<iostream>
using namespace std;
int limit, result, arry_1[1003], arry_1_2[1003];
int main(){
    cin >> limit;
    for(int i=1; i<=limit; ++i) cin >> arry_1[i];
    arry_1_2[0] = 0;
    for(int i=1; i<=limit; ++i){
        if(arry_1[i] > 0)
            arry_1_2[i] = max(arry_1_2[i-1], arry_1_2[i-1]+1);
        else arry_1_2[i] = 0;
    }
    for(int i=1; i<=limit; ++i)
        result = max(result, arry_1_2[i]);
    cout << result << "\n";
}
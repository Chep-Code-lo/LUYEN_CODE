#include<iostream>
using namespace std;
int n, index_d, index_a, index, x[1003], d[1003], a[1003], result[1003];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> x[i];
        if(x[i] > 0) d[index_d++] = x[i];
        else a[index_a++] = x[i];
    }
    int i=0, j=0;
    while(i < index_a & j < index_d){
        result[index++] = a[i++];
        result[index++] = d[j++];
    }
    while(i < index_a){
        result[index++] = a[i++];
    }
    while(j < index_d){
        result[index++] = d[j++];
    }
    for(int i=0; i<n; ++i) cout << result[i] << " ";
}
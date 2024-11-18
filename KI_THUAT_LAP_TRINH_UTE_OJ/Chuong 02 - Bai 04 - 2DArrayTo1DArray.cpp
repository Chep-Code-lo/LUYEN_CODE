#include<iostream>
#define N int(1e5+1)
using namespace std;
int limit_1, limit_2, matrix[10000][10000], arry[N];
void printf(){
    int index = 0;
    for(int i=0; i<limit_1; ++i)
        for(int j=0; j<limit_2; ++j)
            arry[index++] = matrix[i][j];
    for(int i=0; i<limit_1*limit_2; ++i)
        cout << arry[i] << " "; 
}
signed main(){
    cin >> limit_1 >> limit_2;
    for(int i=0; i<limit_1; ++i)
        for(int j=0; j<limit_2; ++j) cin >> matrix[i][j];
    printf();
}
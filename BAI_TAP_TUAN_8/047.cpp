#include<iostream>
using namespace std;
int limit_1, limit_2, num=1, matrix[102][102];
int main(){
    cin >> limit_1 >> limit_2;
    int top=0, left=0, bottom=limit_1 - 1, right=limit_2 - 1;
    while(left <= right && top <= bottom){
        for(int i=left; i<=right; ++i)
            matrix[top][i] = num++;
        ++top;
        for(int i=top; i<=bottom; ++i)
            matrix[i][right] = num++;
        --right;
        if(top <= bottom){
            for(int i=right; i>=left; --i)
                matrix[bottom][i] = num++;
            --bottom;
        }
        if(left <= right){
            for(int i=bottom; i>=top; --i)
                matrix[i][left] = num++;
            ++left; 
        }
    }
    for(int i=0; i<limit_1; ++i){
        for(int j=0; j<limit_2; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}
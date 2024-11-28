#include <iostream>
#include<algorithm>
using namespace std;
int limit_1, limit_2, matrix[102][102];
int main() 
{
    cin >> limit_1 >> limit_2;
    for(int i=0; i<limit_1; ++i)
        for(int j=0; j<limit_2; ++j) cin >> matrix[i][j];
    int mid = limit_1/2;
    cout << *max_element(matrix[mid], matrix[mid] + limit_2);
}
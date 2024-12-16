#include <iostream>
#include <climits>
using namespace std;
int m, n, max_i = -1, max_j = -1;
int a[105][105], max_value = INT_MIN;
int main() {
    cin >> m >> n;
    for(int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)   cin >> a[i][j];
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j){
            bool is_lovy = true;
            if(i > 0 && a[i][j] >= a[i-1][j])
                is_lovy = false;
            if(i < m-1 && a[i][j] >= a[i+1][j])
                is_lovy = false;
            if(j > 0 && a[i][j] >= a[i][j-1])
                is_lovy = false;
            if(j < n-1 && a[i][j] >= a[i][j+1])
                is_lovy = false;
            if (is_lovy && a[i][j] > max_value){
                max_value = a[i][j];
                max_i = i;
                max_j = j;
            }
        }
    if(max_i==-1 && max_j==-1)  cout << -1 ;
    else    cout << max_i  << " " << max_j;
}

/*3 4 
3   1   5   6 
4   6   2   7
8   3  7   6 */

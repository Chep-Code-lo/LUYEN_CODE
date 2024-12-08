#include <iostream>
#include <climits>
using namespace std;
int m, n, min_i = -1, min_j = -1;
double a[105][105], min_value = INT_MAX;
int main() {
    cin >> m >> n;
    for(int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)   cin >> a[i][j];
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j){
            bool is_lovy = true;
            if(a[i][j] <= a[i-1][j])
                is_lovy = false;
            if(a[i][j] <= a[i+1][j])
                is_lovy = false;
            if(a[i][j] <= a[i][j-1])
                is_lovy = false;
            if(a[i][j] <= a[i][j+1])
                is_lovy = false;
            if (is_lovy && a[i][j] < min_value){
                min_value = a[i][j];
                min_i = i;
                min_j = j;
            }
        }
    if(min_i == -1 && min_j == -1)  cout << -1 ;
    else    cout << min_i  << " " << min_j;
}

/*3 4 
3   9   5   6 
4   6   8   7
8   11  7   10 */

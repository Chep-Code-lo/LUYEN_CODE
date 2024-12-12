#include <iostream>
#include<algorithm>
using namespace std;
int n1, n2, f[2005][2005];
string s1, s2;
int main()
{
    cin >> s1 >> s2;
    n1 = s1.size(), n2= s2.size();
    s1 = "#" + s1;
    s2 = "#" + s2;
    for(int i=1; i<=n1; ++i)
        for(int j=1; j<=n2; ++j){
            if(s1[i] == s2[j]) f[i][j] = f[i-1][j-1] + 1;
            f[i][j] = max({f[i][j], f[i-1][j], f[i][j-1]});
        } 
    cout << f[n1][n2];   
}
    
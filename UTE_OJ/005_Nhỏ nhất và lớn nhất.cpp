#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int mi=min(a,min(b,c)) ;
    int ma=max(a,max(b,c));
    cout<<mi<<endl;
    cout<<ma<<endl;
    return 0;
}
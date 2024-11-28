#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(max(a,c)<=min(b,d)){
        cout<<"YES"<<endl;}
    else{
        cout<<"NO"<<endl;}
    return 0;
}
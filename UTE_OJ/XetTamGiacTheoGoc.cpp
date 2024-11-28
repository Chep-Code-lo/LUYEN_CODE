#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b;
	c=180-a-b;
    int t;
	if(a==90||b==90||c==90){
		t=1;
        if(b==c||a==b||a==c) 
        t=0;}
	else {t=3;
    if(a>90||b>90||c>90){
    t=2;}
}
    cout<<t;}
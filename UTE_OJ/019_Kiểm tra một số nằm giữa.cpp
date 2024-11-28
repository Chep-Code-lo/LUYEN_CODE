#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    if((x>=10&&x<=20)&&(y<10||y>20)||(y>=10&&y<=20)&&(x<10||x>20)){
    	cout<<"1"<<endl;}
    else{cout<<"0"<<endl;}
    return 0;
	}
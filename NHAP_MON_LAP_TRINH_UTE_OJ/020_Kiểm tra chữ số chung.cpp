#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
    cin>>a>>b;
	 int a1=a/10;
	 int a2=a%10;
	 int b1=b/10;
	 int b2=b%10;
	
	if ((a1==b1&&a2!=b2)||(a1==b2&&a2!=b1)||(a2==b1&&a1!=b2)||(a2==b2&&a1!=b1)){
		cout<<"1";}
	else{
		cout<<"0";}
        return 0;
	}
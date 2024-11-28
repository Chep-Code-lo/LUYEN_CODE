#include <bits/stdc++.h>
using namespace std;
int main(){
    int x=0;
	int a,b,c,d;
	cin>>x>>a>>b>>c>>d;
    int td=0;
    if(x>=0&&x<=50){
    	td=a*x;}
    else if(x>=51&&x<=100){
    	td=50*a+(x-50)*b;}
    else if(x>=101&&x<=150){
    	td=50*a+50*b+(x-100)*c;}
    else {	td=50*a+50*b+50*c+(x-150)*d;}
    cout<<td;
    return 0;
    }
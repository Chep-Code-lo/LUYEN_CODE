#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long s=0;
	for(int i= 1; i<=n;i++){
        if(i<10){
            s+=i*10+i;}
        else if(i<100){
            s+=i*100+i;}
        else if(i<1000){
            s+=i*1000+i;}
        else{s+=i*10000+i;}
        }
		cout<<s<<endl;
		return 0;
		}
#include <bits/stdc++.h>
using namespace std;
int main(){
	float dqt,dck,dtb,hp;
	cin>>dqt>>dck;
	dtb=(dqt+dck)/2;
	hp=4*235000;
	if(dtb>=8.0&&dqt>=7&&dck>=7){
		cout<<"1"<<endl;}
	else if(dtb<8.0&&dtb>=6.5&&dqt>=6&&dck>=6||(dtb>=8.0)){
		cout<<"2"<<endl;}
	else if((dtb<6.5&&dtb>=5.0)||(dtb<8.0&&dtb>=6.5)){
		cout<<"3"<<endl;}
	else{
		cout<<hp<<endl;}
	return 0;
}
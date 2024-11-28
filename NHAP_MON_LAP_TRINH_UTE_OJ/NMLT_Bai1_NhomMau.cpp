/*Cre: Phan Khánh Anh*/
#include<iostream>
using namespace std;
int main(){
	int x, y, sum;
	cin >> x >> y;
	if(x==1 && y==1 || x==1 && y==8 || x==8 && y==1 )
		sum=9;	
	else if(x==1 && y==2 || x==2 && y==1 )
		sum=15;		
	else if(x==1 && y==4 || x==4 && y==1 || x==4 && y==2 || x==4 && y==4 || x==2 && y==4)
		sum=7;		
	else if(x==2 && y==2 || x==2 && y==8 || x==8 && y==2 )
		sum=10;			
	else if(x==4 && y==8 || x==8 && y==4)
		sum=3;			
	else if(x==8 && y==8)
		sum=8;			
	cout << sum;	
}
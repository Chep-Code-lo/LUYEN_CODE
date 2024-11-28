#include <bits/stdc++.h>
using namespace std;
bool is_leap_year(int y){
	return ((y%4==0&&y%100!=0)||(y%400==0));}
	
int days(int m, int y){
	int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (m==2&&is_leap_year(y))
	return 29;
	return days[m];}
	
bool is_valid_date(int d, int m, int y){
	if(m<1||m>12)
	return 0;
	return d>=1&&d<=days(m,y);}
	
void get_next_day(int d,int m, int y){
	d++;
	if (d>days(m,y)	){d=1;
	m++;
	if(m>12){m=1;
	y++;}}
	cout<<d;}
	
int main(){
    int d,m,y;
    cin>>d>>m>>y;
    if(!is_valid_date(d,m,y))
    	cout<<"0"<<endl;
    else{
    	get_next_day(d,m,y);
	}
    }
    
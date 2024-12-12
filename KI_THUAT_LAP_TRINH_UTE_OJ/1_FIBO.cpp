#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string tinhFibo(int n);
string tinhTong(string A, string B);
int main()
{
	int n;
	cin>>n;
	string KQ = tinhFibo(n);
	cout<<KQ;
	return 0;
}
string tinhFibo(int n)
{
	string A="0";
	string B="1";
	for (int i=1;i<=n;i++)
	{
		string C = tinhTong(A,B);
		A = B;
		B = C;
	}
	return A;
}
string tinhTong(string A, string B)
{
	string T="";
	while (A.length()<B.length())
		A = "0" + A;
	while (A.length()>B.length())
		B = "0" + B;
	int nho = 0;
	for (int i=A.length()-1; i>=0; i--)
	{
		int so = (A[i]-'0') + (B[i]-'0') + nho;
		nho = so / 10;
		so = so % 10;
		stringstream ss;
		ss << so;
		T = ss.str() + T;	
	}	
	if (nho == 1)
		T = "1" + T;
	return T;
}

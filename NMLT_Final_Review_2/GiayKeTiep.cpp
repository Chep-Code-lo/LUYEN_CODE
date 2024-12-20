//Cre: Cao Minh Anh Khoa
#include <iostream>
using namespace std;
int main()
{
    int h,m,s;
    cin>>h>>m>>s;
    s++;
    if(s==60)
    {
        s=0;
        m++;
        if(m==60)
        {
            h++;
            m=0;
            if(h==24)
            {
                h=0;
            }
        }
    }
    cout<<h<<" "<<m<<" "<<s;
    return 0;
}
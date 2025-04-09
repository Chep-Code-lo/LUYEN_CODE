#include <iostream>
using namespace std;
void menhdeNoiLien();
void menhdeNoiRoi();
void menhdekeotheo();
void menhdekeotheo_2C();
void bamenhde();
void bamenhde_01();
int main(){
    // menhdeNoiLien();
    // menhdeNoiRoi();
    // menhdekeotheo();
    // menhdekeotheo_2C();
    // bamenhde();
    bamenhde_01();
    return 0;
}
void menhdeNoiRoi(){
    cout << "\n" << "bang chan tri cua p v q" << endl;
    cout << "p q   (p v q)"<< endl;
    int e;
    for (int p=0; p<=1; p++)
        for (int q = 0; q<=1;  q++){
            if (p==0 && q==0){
                e = 0;
                cout << p << " " << q << "     " << e << endl;
            }
            if (p==0 && q==1){
                e = 1;
                cout << p << " " << q << "     " << e << endl;
            }
            if (p==1 && q==0){
                e = 1;
                cout << p << " " << q << "     " << e << endl;
            }
            if (p==1 && q==1){
                e = 1;
                cout << p << " " << q << "     " << e << endl;
            }
        }
}
void menhdeNoiLien(){
    cout << "\n" << "bang chan tri cua p^q" << endl;
    cout << "p q   (p^q)"<< endl;
    int e;
    for (int p=0; p<=1; p++)
        for (int q = 0; q<=1;  q++){
            if (p==0 && q==0){
                e = 0;
                cout << p << " " << q << "     " << e << endl;
            }
            if (p==0 && q==1){
                e = 0;
                cout << p << " " << q << "     " << e << endl;
            }
            if (p==1 && q==0){
                e = 0;
                cout << p << " " << q << "     " << e << endl;
            }
            if (p==1 && q==1){
                e = 1;
                cout << p << " " << q << "     " << e << endl;
            }
        }
}
void menhdekeotheo(){
    cout << "bang chan tri cua p --> q" << endl;
    cout << "p q  p --> q"<< endl;
    int p,q,e;
    e = 0;
    for (int p=0; p<=1; p++)
        for (int q = 0; q<=1;  q++){
            if (p==0 && q==0){
                e = 1;
                cout << p << " " << q << "     " << e << endl;
            }
            if (p==0 && q==1){
                e = 1;
                cout << p << " " << q << "     " << e << endl;
            }
            if (p==1 && q==0){
                e = 0;
                cout << p << " " << q << "     " << e << endl;
            }
            if (p==1 && q==1){
                e = 1;
                cout << p << " " << q << "     " << e << endl;
            }
        }
}
void menhdekeotheo_2C(){
    cout << "bang chan tri cua p <--> q" << endl;
    cout << "p q  p <--> q"<< endl;
    int p,q,e;
    e = 0;
    for (int p=0; p<=1; p++)
        for (int q = 0; q<=1;  q++){
            if (p==0 && q==0){
                e = 1;
                cout << p << " " << q << "     " << e << endl;
            }
            if (p==0 && q==1){
                e = 0;
                cout << p << " " << q << "     " << e << endl;
            }
            if (p==1 && q==0){
                e = 0;
                cout << p << " " << q << "     " << e << endl;
            }
            if (p==1 && q==1){
                e = 1;
                cout << p << " " << q << "     " << e << endl;
            }
        }
}
void bamenhde(){
    cout << "\n" << "bang chan tri cua (p --> q)^r" << endl;
    cout << "p q r   (p-->q)   (p --> q)^r"<< endl;
    int p,q,r,e,f;
    for (int p=0; p<=1; p++)
        for (int q = 0; q<=1;  q++)
            for (int r=0; r<=1;r++){
                if ((p==0 && q==0)||(p==0 && q==1) || (p==1 && q==1)){
                    e = 1;
                    if (r == 0) f = 0;
                    else f = 1;
                    cout << p << " " << q << " " << r << "      " << e << "          " << f << endl;
                }
                if (p==1 && q==0){
                    e = 0;
                    f = 0;
                    cout << p << " " << q << " " << r << "      " << e << "          " << f << endl;
                }
            }
}
void bamenhde_01(){
    cout << "\n" << "bang chan tri cua (p <--> q)^r" << endl;
    cout << "p q r   (p<-->q)   (p <--> q)^r"<< endl;
    int p,q,r,e,f;
    for (int p=0; p<=1; p++)
        for (int q = 0; q<=1;  q++)
            for (int r=0; r<=1;r++){
                if ((p==0 && q==0) || (p==1 && q==1)){
                    e = 1;
                    if (r == 0) f = 0;
                    else f = 1;
                    cout << p << " " << q << " " << r << "      " << e << "          " << f << endl;
                }
                else {
                    e = 0;
                    f = 0;
                    cout << p << " " << q << " " << r << "      " << e << "          " << f << endl;
                }
            }
}
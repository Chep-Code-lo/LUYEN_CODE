#include <iostream>
using namespace std;
double a, b, c;
int main(){
    cin >> a >> b >> c;  
    if (a == 0){
        if(b == 0){
            if (c == 0)
                cout << 4;  // Vô số nghiệm
            else
                cout << 0;  // Vô nghiệm
        }else 
            cout << 1;  // Phương trình bậc nhất có nghiệm duy nhất
    }else{
        double delta = b * b - 4 * a * c;  // Tính biệt thức delta
        if (delta > 0) 
            cout << 2;  // 2 nghiệm phân biệt
        else if (delta == 0) 
            cout << 3;  // Nghiệm kép
        else 
            cout << 0;  // Vô nghiệm
    }
}

#include<bits/stdc++.h>
using namespace std;
int x, y;
pair<string, int>play_game(int x, int y){
    int turn = 0;
    while(true){
        //Nam start
        turn++;
        int nam_a = -1, nam_b = -1;
        for(int a=0; a<=min(x, 2); ++a){
            if((220 - 100*a) % 10 == 0){
                int b = (220 - 100*a)/10;
                if(b >= 0 && b <= y)
                    if(nam_a == -1 || a > nam_a){
                        nam_a = a;
                        nam_b = b;
                    }
            }
        }
        if(nam_a == -1)
            return{"Minh", turn};
        x -= nam_a;
        y -= nam_b;
        //Minh start
        turn++;
        int minh_a = -1, minh_b = -1;
        for(int b=0; b<=min(y, 22); ++b){
            if((220 - 10*b) % 100 == 0){
                int a = (220 - 10*b)/100;
                if(a >= 0 && a <= x)
                    if(minh_b == -1 || b > minh_b){
                        minh_a = a;
                        minh_b = b;
                    }
            }
        }
        if(minh_b == -1)
            return{"Nam", turn};
        x -= minh_a;
        y -= minh_b;
    }
}
int main(){
    cin >> x >> y;
    auto res = play_game(x, y);
    cout << res.first << "\n" << res.second;
}
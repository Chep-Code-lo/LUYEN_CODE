//Cre: Chat GPT
#include <iostream>
using namespace std;
string s;
int main(){
    cin >> s;
    for(int i=0; i<s.size(); ++i){
        bool isUnique = true;
        for(int j=0; j<s.size(); ++j){
            if(i != j && s[i] == s[j]){
                isUnique = false;
                break;
            }
        }
        if(isUnique){
            cout << s[i];
            return 0;
        }
    }
    cout << "";
}

#include<bits/stdc++.h>
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
using namespace std;
const string NAME = "TASK";
const int TEST = 10000;// Giới hạn sinh test
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
long long Rand(long long l, long long r){
    return uniform_int_distribution<long long>(l, r)(rng);
}
string random_string(size_t length){
    const string characters = "0123456789QWERTYUIOPASDFGHJKLZXCVBNMqwertyuioasdfghjklzxcvbnm";
    random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<> dist(0, characters.size()-1);
    string random_string;
    for(size_t i=0; i<length; ++i)
        random_string += characters[dist(generator)];
    return random_string;
}
bool check_file(const string& p1, const string& p2){
    ifstream f1(p1, ifstream::binary | ifstream::ate);
    ifstream f2(p2, ifstream::binary | ifstream::ate);
    if(f1.fail() || f2.fail())
        return false;
    if(f1.tellg() != f2.tellg())
        return false;
    f1.seekg(0, ifstream::beg);
    f2.seekg(0, ifstream::beg);
    return equal(istreambuf_iterator<char>(f1.rdbuf()),
                istreambuf_iterator<char>(),
                istreambuf_iterator<char>(f2.rdbuf()));
}
int main(){
    srand(time(NULL));
    for(int test=1; test<=TEST; ++test){
        ofstream inp((NAME + ".inp").c_str());
        // Code sinh
        int n = Rand(1, 1000);
        int m = Rand(1, 1000);
        inp << n << " " << m << "\n";
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j)
                inp << Rand(-1e9, 1e9) << " ";
            inp << "\n";
        }
        inp.close();
        system((NAME +".exe").c_str());
        system((NAME +"_trau.exe").c_str());
        //file out code chuẩn
        //file ans code trâu
        if(!check_file("TASK.ans", "TASK.out")){
            cout << "Test" << test << ":WA\n";
            return 0;
        }
        cout << "Test" << test << ": AC\n";
    }

}
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
using namespace std;

int main(){
    int res=0;
    string line;
    while( getline(cin, line) ){
        unordered_set<string> phrases;
        stringstream ss;
        ss<<line;
        string buff;
        int val = 1;
        while(ss>>buff){
            if(phrases.count(buff)==0 )
                phrases.insert(buff);
            else{
                val = 0;
                break;
            }
        }
        res += val;
    }
    cout<<res<<endl;
    return 0;
}

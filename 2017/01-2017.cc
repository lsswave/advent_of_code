#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int solve(const string & s){
    int sum=0;
    int len = s.size();
    if(len<2)
        return sum;
    for(int i=1; i<len; ++i){
        if(s[i] == s[i-1])
            sum += (s[i]-'0');
    }
    if(len>2 && s[len-1]==s[0])
        sum += (s[0]-'0');
    return sum;
}

int main(){
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
    return 0;
}

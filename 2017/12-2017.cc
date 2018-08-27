#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef unordered_map<string, vector<string> > umsv;

string strtrim(string str){
    stringstream ss(str);
    string res;
    ss>>res;
    return res;
}

void parse(const string & line, umsv & dict){
    string key = line.substr(0, line.find_first_of(' '));
    string sep = "<->";
    int vpos = line.find_first_of(sep)+sep.size();
    stringstream ss(line.substr(vpos));
    vector<string> vals;
    string token;
    while(getline(ss, token, ','))
        vals.push_back(strtrim(token));
    if(dict.count(key)==0)
        dict[key]=vals;
    else{
        for(auto x: vals)
            dict[key].push_back(x);
    }
}

void solve(umsv & dict, unordered_set<string> & visited, string key, int & cnt){
    cnt += 1;
    visited.insert(key);
    for(const auto x: dict[key])
        if(visited.count(x)==0)
            solve(dict, visited, x, cnt);
}

int forest_cnt(umsv & dict){
    int res=0;
    unordered_set<string> visited;
    for(const auto x: dict){
        if(visited.count(x.first)==0){
            res += 1;
            int temp=0;
            solve(dict, visited, x.first, temp);
        }
    }
    return res;
}

int main(){
    string line;
    umsv dict;
    while(getline(cin, line)){
        parse(line, dict);
    }
    unordered_set<string> visited;
    string start_key="0";
    int cnt=0;
    solve(dict, visited, start_key, cnt);
    cout<<cnt<<endl;
    cout<<forest_cnt(dict)<<endl;
    return 0;
}

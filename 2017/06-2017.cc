#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

const int N = 16;

int distribute(vector<int> & banks, int index){
    int pos(-1), maxv(0);
    int increase = banks[index]/N;
    int extra = banks[index]%N;
    banks[index] = 0;
    int i=1;
    while(i<=N){
        int loc = (i+index)%N;
        banks[loc] += increase;
        if(i<=extra)
            banks[loc] += 1;
        if(maxv<=banks[loc]){
           if(maxv < banks[loc] | loc < pos )
               pos = loc;
           maxv = banks[loc];
        }
        ++i;
    }
    /*
    for(auto x: banks)
        cout<<x<<'\t';
    cout<<endl;
    */
    return pos;
}

string serialize(const vector<int> & banks){
    string res = "";
    for(auto x: banks)
        res += to_string(x) + " ";
    return res;
}

int solve(vector<int> & banks){
    int cnt(0), index(0), maxv(0);
    for(int i=0; i<N; ++i){
        if(banks[i] > maxv){
            index = i;
            maxv = banks[i];
        }
    }
    unordered_set<string> history;
    string serialized_banks = serialize(banks);
    while(history.count(serialized_banks)==0){
        ++cnt;
        history.insert(serialized_banks);
        index = distribute(banks, index);
        serialized_banks = serialize(banks);
    }
    return cnt;
}
int main(){
    vector<int> banks(N, 0);
    int val(0), i(0);
    while(i<N && cin>>val){
        banks[i] = val;
        ++i;
    }
    cout<<solve(banks)<<endl;
    return 0;
}

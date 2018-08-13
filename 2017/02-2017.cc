#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int solve(const vector<vector<int> > & sheet){
    int checksum=0;
    for(auto row: sheet){
        if(row.size()==0)
            continue;
        int maxv = row[0];
        int minv = row[0];
        for(auto x: row){
            maxv = maxv > x?maxv:x;
            minv = minv < x?minv:x;
        }
        checksum += (maxv - minv);
    }
    return checksum;
}

int main(){
    vector<vector<int> > sheet;
    string line;
    while( getline(cin, line) ){
        stringstream ss(line);
        /*
        stringstream ss;
        ss<<line;
        */
        vector<int> buff;
        int num;
        while(ss>>num)
            buff.push_back(num);
        sheet.push_back(buff);
    }
    /*
    for(auto x: sheet){
        for(auto y: x)
            cout<<y<<' ';
        cout<<endl;
    }
    */
    cout<<solve(sheet)<<endl;
    return 0;
}

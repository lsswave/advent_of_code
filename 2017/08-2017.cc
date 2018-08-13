#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;
typedef unordered_map<string, int> umap_si;

static umap_si op_map = {
	{"!=", 1},
	{"==", 2},
	{">=", 3},
	{"<=", 4},
	{">",  5},
	{"<",  6},
	{"inc",7},
	{"dec",8}
};

struct phrase{
    string var;
    string op;
    int val;
    phrase(string _var, string _op, int _val){
        var=_var, op=_op, val=_val;
    }
};

pair<phrase, phrase> line_parse(string line){
    stringstream ss(line);
    string var, op;
    int val;
    ss>>var, ss>>op, ss>>val;
    phrase action = phrase(var, op, val);
    ss>>var;
    ss>>var, ss>>op, ss>>val;
    phrase condition = phrase(var, op, val);
    return {action, condition};
}

bool phrase_calc(umap_si & vars, phrase & p){
    switch(op_map[p.op] ){
        case 1: return vars[p.var]!=p.val;
        case 2: return vars[p.var]==p.val;
        case 3: return vars[p.var]>=p.val;
        case 4: return vars[p.var]<=p.val;
        case 5: return vars[p.var]>p.val;
        case 6: return vars[p.var]<p.val;
        case 7:
                vars[p.var] += p.val;
                return 1;
        case 8:
                vars[p.var] -= p.val;
                return 1;
        default:
                cout<<"warning"<<endl;
                return 0;
    }
}

int line_calc(umap_si & vars, const string line){
    pair<phrase, phrase> pp = line_parse(line);
    phrase act(pp.first), cond(pp.second);
    if(vars.count(cond.var)==0 )
        vars[cond.var] = 0;
    if(vars.count(act.var)==0)
        vars[act.var] = 0;
    if(phrase_calc(vars, cond) )
        phrase_calc(vars, act);
    // cout<<act.var<<" "<<vars[act.var]<<endl;
    return vars[act.var];
}

int main(){
    int res=0;
    umap_si vars;
    string line;
    while( getline(cin, line) )
        line_calc(vars, line);
    for(auto x: vars)
        res = res>x.second?res:x.second;
    cout<<res<<endl;
    return 0;
}

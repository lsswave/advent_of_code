#include <iostream>
#include <cmath>
using namespace std;

int solve(int n){
    if(n<=3)
        return (n<0)?-1:n-1;
    int k = sqrt(n);
    if(n==k*k)
        return k-1;
    int sp = k*k+1;
    if((k&1)==0){
        sp = (k-1)*(k-1)+1;
        k=k-1;
    }
    int locx(((k-1)>>1)+1), locy(-((k-1)>>1));
    while(sp < n){
        int cnt_r(k), cnt_t(k+1), cnt_l(k+1), cnt_b(k+1);
        while(sp!=n && cnt_r>0)
            ++sp, --cnt_r, locy+=1;
        while(sp!=n && cnt_t>0)
            ++sp, --cnt_t, locx-=1;
        while(sp!=n && cnt_l>0)
            ++sp, --cnt_l, locy-=1;
        while(sp!=n && cnt_b>0)
            ++sp, --cnt_b, locx+=1;
        ++k;
    }
    return abs(locx) + abs(locy);
}

int main(){
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}

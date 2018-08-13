#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> & nums){
    if(nums.size() == 0)
        return 0;
    int cnt(0), index(0), len(nums.size() );
    while(index>=0 && index<len){
        int next = index + nums[index];
        nums[index] += 1;
        index = next;
        ++cnt;
    }
    return cnt;
}
int main(){
    vector<int> nums;
    int val(0);
    while(cin>>val)
        nums.push_back(val);
    cout<<solve(nums)<<endl;
    return 0;
}

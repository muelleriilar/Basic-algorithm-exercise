#include <algorithm>
#include <bits/stdc++.h>
#include <valarray>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> a;
    vector<int>::iterator it2;
    vector<vector<int>> subsets(vector<int>& nums) {
        this->it2 = nums.end();
        solve(nums.begin());
        return this->result;
    }
    void solve(std::vector<int>::iterator it1){
        result.push_back(a);
        for(;it1<it2;it1++){
            a.push_back(*it1);
            solve(it1+1);
            a.pop_back();
        }
        return ;
    }
};
int main(){
    vector<int> nums = {1,2,3};
    Solution s ;
    s.subsets(nums);
    for (auto i : s.result){
        for (auto j:i)
            std::cout << j << ' ';
        cout << '\n';
    }
    return 0;
}

/*

* dsad
! dsad
? dsad
TODO dsad
// dasd

回溯问题，求组合
1.
每个数，问一下，选不选
选的话，进入下一阶段，不选也要进入下一阶段
直到某一阶段到底了，处理当前的状态

2.
每个数问一下选不选
选的话，进入下一个阶段，不选也要进入下一个阶段，但是用for实现
选的话，直接处理，不选的话不处理（因为是组合问题，不选的话不用处理）
*/
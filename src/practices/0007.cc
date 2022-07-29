#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums = {-1,0,1};

    auto it1 = begin(nums);
    auto it2 = end(nums);
    do {
        cout << nums[0] << ' ';
        cout << nums[1] << ' ';
        cout << nums[2] << '\n';
    } while (next_permutation(it1,it2));

    return 0;
}
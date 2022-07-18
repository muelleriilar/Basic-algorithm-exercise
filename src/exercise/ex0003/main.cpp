#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
using gg = long long;
#define MAX_N 10'0000
struct timespec t1, t2;

gg ni,s;
vector<int> v;
int MIN_COINS[MAX_N] = {0};

int dp(int s){
    if (!MIN_COINS[s]) {
        return 0;
    }
    if (MIN_COINS[s] != -1){
        return MIN_COINS[s];
    }
    return MIN_COINS[s] = accumulate(v.begin(),v.end(),MAX_N,[&s](int left,int e){
        if(s < e){
            return left;
        }
        return min(left,dp(s - e) + 1);
    });
}

int main(){
    memset(MIN_COINS, -1, sizeof(MIN_COINS));
    MIN_COINS[0] = 0;    
    cin >> s >> ni;
    for(;ni > 0;ni--){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    cout << dp(s) << '\n';
    clock_gettime(CLOCK_MONOTONIC, &t2);
    cout << "time spends: " << (double)((t2.tv_sec-t1.tv_sec) + (t2.tv_nsec-t1.tv_nsec)/1000000) << '\n';
    return 0;
}

/**
硬币问题
最优子结构、重叠子问题

边界条件
| 子问题迭代到某个基础子问题 dp(0)
| s - v[0] ＜ 0

边界条件写在递归函数的开头

// 变量
n, v[], s, MIN_COINS[]

// 初始条件
MIN_COINS[0] = 0;
MIN_COINS[1] = 1;
MIN_COINS[2] = 1;

// 状态转移
dp(s){
    if(MIN_COINS[s]){
        return MIN_COINS[s]
    }
    完全背包才能这样写
    return MIN_COINS[s] = min(
        dp(s - v[0]) + 1,
        dp(s - v[1]) + 1,
        dp(s - v[2]) + 1,
        ...
        dp(s - v[n]) + 1
    )
}

// 输入
7
5
1 2 3 4 5

// todo 
如果没法表示的话，会输出什么？

*/
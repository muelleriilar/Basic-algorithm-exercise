#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <climits>
#include <sys/time.h>
using namespace std;
using gg = long long;
#define MAX_N 100
struct timespec t1, t2;

gg ni,s;
vector<int> v;
array<int, MAX_N> MIN_COINS;

int solve(){
    for(auto e:v){
        for(int j=e;j<MAX_N;j++){
            MIN_COINS[j] = min(MIN_COINS[j], MIN_COINS[j - e] + 1);
        }
        for(auto b:MIN_COINS){
            cout << b <<',';
        }
        cout << '\n';
        cout << '\n';
    }
    return 0;
}

int main(){
    MIN_COINS.fill(INT_MAX);
    cout << INT_MAX <<'\n';
    MIN_COINS[0] = 0;

    cin >> s >> ni;
    for(;ni>0;ni--){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    clock_gettime(CLOCK_MONOTONIC, &t1);
    solve();
    cout << MIN_COINS[s] << '\n';
    clock_gettime(CLOCK_MONOTONIC, &t2);
    cout << "time spends: " << (double)((t2.tv_sec-t1.tv_sec) + (t2.tv_nsec-t1.tv_nsec)/1000000) << '\n';
    return 0;
}

/**
硬币问题
最优子结构、重叠子问题

// 变量
n, v[], s, MIN_COINS[]

// 状态转移
dp(s) = min(
    dp(s - 1) + 1,
    dp(s - 2) + 1,
    ...
    dp(s - i) + 1
)

// 打表
for(auto e:v){
    for(int j=e;j<VALUE;j++){
        MIN_COINS[j] = min(MIN_COINS[j], MIN_COINS[i - e] + 1);
    }
}
7个数
[-1,-1,-1,-1,-1,-1,-1]
初始化第一个
[ 0,-1,-1,-1,-1,-1,-1]
遍历第一次
[ 0, 1, 2,-1,-1,-1, 6]
遍历第二次
[ 0, 1, 1, 2, 2, 3, 4]
遍历第三次
[ 0, 1, 1, 1, 2, 2, 2]
遍历第四次
[ 0, 1, 1, 1, 1, 2, 2]
遍历第五次
[ 0, 1, 1, 1, 1, 1, 2]
如果要对i个数求的话，应该数组有0到i共i+1个

// 输入
7
5
1 2 3 4 5

// 有问题的样例
990
3 
7 17 19
-2147483597

*/
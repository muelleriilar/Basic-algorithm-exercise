/*
 * @Author: doufugan 2195134555@qq.com
 * @Date: 2022-07-23 22:11:34
 * @LastEditors: doufugan 2195134555@qq.com
 * @LastEditTime: 2022-07-24 19:02:23
 * @FilePath: /Basic-algorithm-exercise/src/exercise/ex0013/main.cc
 * @Description: 宗教问题 区间dp
 */

#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using gg = long long;
int main() {
  int ni,mi,ki;
  cin >> ni >> mi >> ki;
  vector<int> p(ni);
  for (int i = 0;i < ni;ni++) {
    cin >> p[i];
  }

  return 0;
}

/*
样例输入
10 4 3
1 2 3 4 3 4 3 2 1 2

样例输出
3
6

状态转移方程 
区间dp 1 2 3 // 4 3 4 3 2 // 1 2
分割点数量 
i = 区间长度
j = 区间起点
dp(i,0) = min(
  dp(i - 1, 0) + 1,
  dp(i - 1, 1) + 1,
  ...
  dp(i - 1, j) + 1,
)

边界
dp(1,j) = 0;
dp(2,1) = min(
  dp(1,1) + 1,
  dp(1,2) + 1
)
dp(i,j) 区间中的 m <= k return 0

怎么记录path？path[][] 存放节点，指向前一个节点坐标？不行啊，dp(i,j) 不知道其上一个是谁，节点的前向路径不唯一啊
*/
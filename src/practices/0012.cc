#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using gg = long long;
array<array<int, 1'001>, 1'001> subproblem;
vector<int> a;
vector<int> b;
int lcs(int i, int j) {
  int &c = subproblem[i][j];
  if (c != -1)
    return c;
  assert(i > 1 && j > 1);
  return c = max({
    lcs(i - 1, j),
    lcs(i, j - 1),
    a[i - 1] == b[j - 1] ? lcs(i - 1, j - 1) + 1:0,
  });
}
int main() {
  gg ni;
  cin >> ni;
  assert(ni <= 1001);
  for (auto &e:subproblem) 
    e.fill(-1);
  a.resize(ni);
  b.resize(ni);
  for (auto &e:a)
    cin >> e;
  for (auto &e:b)
    cin >> e;

  int flag1 = 0;
  int flag2 = 0;
  for (int i = 0;i < ni;i++) {
    if (a[i] == b[0]) {
      flag1 = 1;
    }
    subproblem[i + 1][0 + 1] = flag1;
    if (a[0] == b[i]) {
      flag2 = 1;
    }
    subproblem[0 + 1][i + 1] = flag2;
  }
  subproblem[0][0] = 0;
  cout << lcs(ni,ni) << endl;
}
/* cmake ../;make;echo -e "5\n1 2 3 4 5\n2 5 6 7 8\n" | cat | ./Basic-algorithm-exercise; */

/*
暴力解法, 时间复杂度 O(n^2)
  最长公共子序列 线性dp
  a b a a c
  c b a
  子问题长度为 i, j 的两个序列的 lcs 
  无后效性, 已解决的子问题 i, j 不会受到后续决策的影响, 选择其他长度对不影响该长度对
  重叠子问题, 存在重叠子问题 i, j 可以从 i + 1, j 转移过来, 也可以从 i, j + 1 转移而来
  状态用 i, j 表示
  策略就是向最大的那个转移
  dp(i, j) = max(
    dp(i - 1, j - 1) + 1,
    dp(i - 1,j),
    dp(j - 1,i)
  )
离散化解法
  求两个序列的公共子序列, 可以看成是求最长"上升"子序列, 只不过这里的上升不是按照从大到小上升, 
  以第一个数组为参照, 这里的上升看成第二个数组, 按照第一个数组的顺序上升, 这时候需要做一些转化, 也就是离散化 
*/

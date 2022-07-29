#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using gg = long long;

int main() {
  vector<int> li;
  vector<int> m;
  int ni;
  cin >> ni;
  li.resize(ni);
  for (auto &a:li)
    cin >> a; 
  m.resize(ni);
  fill(m.begin(),m.end(),0);
  function<int(int)> lis = [&li, &lis, &m](int i){
    if (m[i] != 0) {
      return m[i];
    }
    vector<int> tem = {};
    for (int j = i;j >= 0;j--) {
      if (li[j] < li[i]) {
        tem.push_back(lis(j) + 1);
      }
    }
    if (tem.empty())
      return 1;
    return m[i] = *max_element(tem.begin(),tem.end());
  };
  vector<int> count(ni);
  iota(count.begin(), count.end(), 0);
  cout << accumulate(count.begin(),count.end(),0,[&lis](int left, int e){
    return max(left, lis(e));
  }) << endl;
}
/*
cmake ../;make;echo -e "5\n1 3 4 5 2\n"|./Basic-algorithm-exercise;
*/
/*
lcs(i) 表示以 index = i 结尾的最长上升子序列
子结构
无后效性 (好像不满足?)
状态 i
策略 max
*/
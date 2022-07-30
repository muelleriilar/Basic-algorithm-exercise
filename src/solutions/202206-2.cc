#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
using namespace std;
using gg = long long;
int main() {
  int ni, li, s, sum = 0;
  cin >> ni >> li >> s;
  vector<pair<int, int>> trees;
  trees.resize(ni);
  for (auto &tree:trees) {
    cin >> tree.first >> tree.second;
  }
  vector <pair<int, int>> g;
  vector <pair<int, int>> cog;
  int k;
  for (int i = s;i >= 0;i--) {
    for (int j = 0;j <= s;j++) {
      cin >> k;
      if (k == 1) {
        g.push_back(make_pair(i, j));
      } else {
        cog.push_back(make_pair(i, j));
      }
    }
  }
  sort(trees.begin(), trees.end());
  // 在藏宝图中随便找一个 tree 去和所有的树进行匹配
  // 复杂度 n*(s*n);
  // 如果排序并使用二分的话复杂度 n*logn + n*(s*logn)
  // 排序之后因为藏宝图大小有限的缘故, 还可以进一步优化成 n*logn + n*(s*O(1))
  auto oneTree = g.front();
  for (auto &tree:trees) {
    // 满足藏宝图不超出地图边缘
    if (tree.first - oneTree.first < 0 
      or tree.second - oneTree.second < 0
      or tree.first + (s - oneTree.first) > li
      or tree.first + (s - oneTree.first) > li
      ) continue;
    // 该有的树必须有
    for (auto tree1:g) {
      auto key = make_pair(tree.first + (tree1.first - oneTree.first), 
        tree.second + (tree1.second - oneTree.second));
      if (key.first == -1) {
      }
      auto it = lower_bound(trees.begin(), trees.end(), key);
      if(it == trees.end() or key != *it) {
        goto noAddSum;
      }
    }
    // 该为0的地方也必须为0
    for (auto tree2:cog) {
      auto key = make_pair(tree.first + (tree2.first - oneTree.first), 
        tree.second + (tree2.second - oneTree.second));
      auto it = lower_bound(trees.begin(), trees.end(), key);
      if(it != trees.end() and key == *it) {
        goto noAddSum;
      }
    }
    sum++;
    noAddSum:;
  }
  cout << sum << endl;
}
/*
1 0 0 1
0 0 1 0
1 1 0 0
0 0 1 0

0 0 1
1 1 0
0 0 1
(1, 1) 和 (2, 1) 匹配, 要求行下界不能超 2 - (1 - 0) = 1 >= 0, 行上界不能超2 + (2 - 1) <= L
左右同理
cmake ../;make;./Basic-algorithm-exercise
5 4 2
0 0
1 1
2 2
3 3
4 4
0 0 0
0 1 0
1 0 0

输出 0
5 100 2
0 0
1 1
2 2
3 3
4 4
0 0 1
0 1 0
1 0 0

输出 3
*/
/*
 * @Author: doufugan 2195134555@qq.com
 * @Date: 2022-07-23 22:11:34
 * @LastEditors: doufugan 2195134555@qq.com
 * @LastEditTime: 2022-07-24 01:01:51
 * @FilePath: /Basic-algorithm-exercise/src/exercise/ex0012/main.cc
 * @Description: 单源最短路径 djikstra
 */

#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using gg = long long;
struct Arc {
  int to;
  int w;
};
struct Vertex{
  gg path_length;
  list<Arc *> arcs;
};
class Graph {
 public:
  void Add(int u, int v, int w) {
    vertexs_[u].arcs.push_back(new Arc{
      v, w
    });
  }
  void dji(){
    // pq 相当于 V-S，初始化 pq
    auto less = [this](int a, int b){
      return this->vertexs_[a].path_length > this->vertexs_[b].path_length;
    };
    vector<int> container;
    priority_queue<int,vector<int>,decltype(less)> pq(less, move(container));
    // 相当于 S
    vector<bool> s(n_);
    fill(s.begin(),s.end(),false);
    auto bfs = [&pq, &s, this]() {  // lambda 不能捕获类成员
      pq.push(s_);
      vertexs_[s_].path_length = 0;
      // 在 V-S 中拿一个点，寻找其最短路径 path_length
      // 这个点就是用 bfs 搜出来的
      while (!pq.empty()) {
        auto e = pq.top();
        pq.pop();
        // add to S
        s[e] = true;
        // 搜索接下来的 V-S 节点
        for (auto arc:vertexs_[e].arcs) {
          // 如果该节点在 V - S
          if ( !s[arc->to] ) {
            pq.push(arc->to);
            vertexs_[arc->to].path_length = min(vertexs_[arc->to].path_length,
              vertexs_[e].path_length + arc->w);
          }
        }
      }
    };
    bfs();
    for (int i  = 1;i <= n_;i++){
      cout << vertexs_[i].path_length << ' ';
    }
    cout << '\n';
  }
  int n_;
  int s_;
  vector<Vertex> vertexs_;
} g;

int main() {
  int mi;
  cin >> g.n_ >> mi >> g.s_;
  g.vertexs_.resize(g.n_ + 1);
  fill(g.vertexs_.begin(),g.vertexs_.end(), Vertex{
    LONG_LONG_MAX,
    list<Arc*>()
  });
  while (mi--) {
    int u, v, w;
    cin >> u >> v >> w;
    assert(w < INT_MAX);
    g.Add(u, v, w);
  }
  g.dji();
  return 0;
}

/*
样例输入
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4

样例输出
0 2 4 3
*/
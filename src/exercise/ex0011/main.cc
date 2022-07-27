/*
 * @Author: doufugan 2195134555@qq.com
 * @Date: 2022-07-22 12:18:02
 * @LastEditors: doufugan 2195134555@qq.com
 * @LastEditTime: 2022-07-23 17:15:20
 * @FilePath: /Basic-algorithm-exercise/src/exercise/ex0011/main.cc
 * @Description: 最大流ff算法实现，第一次尝试 google c++ code style
 */

#include <bits/stdc++.h>
using namespace std;
using gg = long long;
class Arc {
 public:
  gg RemainCapacity() { 
    return capacity_ - flow_; 
  }
  void argument(int bottleNeck) {
    residual_->flow_ -= bottleNeck;
    this->flow_ += bottleNeck;
  }
  int to_;
  gg capacity_;
  gg flow_;
  Arc *residual_;
};
class Graph {
 public:
  void Add(int u, int v, gg capacity) {
    auto arc1 = new Arc{v, capacity, 0, nullptr};
    auto arc2 = new Arc{u, 0, 0, arc1};
    arc1->residual_ = arc2;
    vertexs_[u].push_front(arc1);
    vertexs_[v].push_front(arc2);
  }
  gg MaxFlow() {
    array<bool, 10000> vertexs_visited;
    function<gg(int,gg)> Dfs = [this, &vertexs_visited, &Dfs](int i,gg flow) {
      // 寻找增广路径，寻找增广路径的 bottleneck 增广该路径上的流
      // 对于一个节点来说，Dfs 的参数 flow 是前向路径上的最大能经过的流，对于汇点 t 来说
      // 无论 flow 有多么大，都可以流入，所以整条路的 bottleneck 就是这个 flow
      if (i == this->t_) return flow;

      vertexs_visited[i] = true;

      for (auto arc:vertexs_[i]) {
        if (arc->RemainCapacity() > 0 && !vertexs_visited[arc->to_]){
          auto bottleneck = Dfs(arc->to_, min(flow, arc->RemainCapacity()));
          if (bottleneck > 0){
            arc->argument(bottleneck);
            return bottleneck;
          }
        }
      }
      return (gg)0;
    };
    {
      gg f = 0;
      do {
        vertexs_visited.fill(false);
        f = Dfs(s_,LONG_LONG_MAX);
        max_flow_ += f;
      } while (f != 0);
    }
    return max_flow_;
  }
  
  int n_, s_, t_;
  gg max_flow_;
  vector<list<Arc *>> vertexs_;
} g;

int main() {
  int ni, mi;
  cin >> ni >> mi >> g.s_ >> g.t_;
  g.vertexs_.resize(ni + 1);
  fill(g.vertexs_.begin(),g.vertexs_.end(),list<Arc*>());
  while (mi--) {
    int u, v, capacity;
    cin >> u >> v >> capacity;
    if(capacity > pow(2, 32) - 1){
      exit(0);
    }
    g.Add(u, v, capacity);
  }
  cout << g.MaxFlow();
  return 0;
}

/*
样例输入
4 5 4 3
4 2 30
4 3 20
2 3 20
2 1 30
1 3 40

样例输出
50
*/
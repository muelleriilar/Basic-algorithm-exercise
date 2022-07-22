/*
 * @Author: doufugan 2195134555@qq.com
 * @Date: 2022-07-22 12:18:02
 * @LastEditors: doufugan 2195134555@qq.com
 * @LastEditTime: 2022-07-22 23:25:18
 * @FilePath: /Basic-algorithm-exercise/src/exercise/ex0011/main.cc
 * @Description: 最大流ff算法实现，第一次尝试 google c++ code style
 */

#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

class Arc {
 public:
  int RemainCapacity() { 
    return capacity_ - flow_; 
  }
  void argument(int bottleNeck) {
    residual_->flow_ -= bottleNeck;
    this->flow_ += bottleNeck;
  }
  int to_;
  int capacity_;
  int flow_;
  Arc *residual_;
};
class Graph {
 public:
  void Add(int u, int v, int capacity) {
    auto arc1 = new Arc{v, capacity, 0, nullptr};
    auto arc2 = new Arc{u, 0, 0, arc1};
    arc1->residual_ = arc2;
    vertexs_[u].push_front(arc1);
    vertexs_[v].push_front(arc2);
  }
  int MaxFlow() {
    array<bool, 201> vertexs_visited;
    vertexs_visited.fill(false);
    int debug_a = 10;
    for (auto arc:vertexs_[4])
      cout << arc->to_ <<'a';
    cout << endl;
    function<int(int,int)> Dfs = [this, &vertexs_visited, &Dfs, &debug_a](int i,int flow) {
      if (debug_a > 0){
        debug_a--;
      } else {
        exit(0);
      }
      cout << i << ' ' << flow << "test\n";
      // 寻找增广路径，寻找增广路径的 bottleneck 增广该路径上的流
      // 对于一个节点来说，Dfs 的参数 flow 是前向路径上的最大能经过的流，对于汇点 t 来说
      // 无论 flow 有多么大，都可以流入，所以整条路的 bottleneck 就是这个 flow
      if (i == this->t_) return flow;

      vertexs_visited[i] = true;

      for (auto arc:vertexs_[i]) {
        if (arc->RemainCapacity() > 0 && !vertexs_visited[arc->to_]){
          cout << " capacity is " << arc->RemainCapacity();
          auto bottleneck = Dfs(arc->to_, min(flow, arc->RemainCapacity()));
          if (bottleneck > 0){
            arc->argument(bottleneck);
            return bottleneck;
          }
        }
      }
      return 0;
    };
    for(int f = Dfs(s_,INT_MAX);f != 0;f = Dfs(s_,INT_MAX)) {
      max_flow_ += f;
      vertexs_visited.fill(false);
    }

    return max_flow_;
  }
  
  int n_, s_, t_;
  int max_flow_;
  vector<list<Arc *>> vertexs_;
} g;

int main() {
  int ni, mi;
  cin >> ni >> mi >> g.s_ >> g.t_;
  g.vertexs_.resize(ni + 1);
  while (mi--) {
    int u, v, capacity;
    cin >> u >> v >> capacity;
    g.Add(u, v, capacity);
  }
  cout << g.MaxFlow() << '\n';
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
#include <atomic>
#include<bits/stdc++.h>
#include <list>
#include <queue>
#include <regex>
using namespace std;

struct Arc{
    int to;
    int capacity;
    int flow;
    Arc* residual;
    auto remainCapacity(){
        return capacity - flow;
    }
    void argument(int bottleNeck){
        residual->flow - bottleNeck;
        this->flow + bottleNeck;
    }
};
// 节点没有值，就不写节点了，把节点数组中的节点省略掉，直接写弧链表
// struct Node{
//     int val;
//     list<Arc> arcs;
// };
struct Graph{
    vector<list<Arc*>> heads;
    void add(int u,int v,int capacity){
        auto arc1 = new Arc{v,capacity,0,nullptr};
        auto arc2 = new Arc{u,0,0,arc1};
        arc1->residual = arc2;
        heads[u].push_front(arc1);
        heads[v].push_front(arc2);
    }
}g;


int main(){
    int ni,mi,si,ti;
    cin >> ni >> mi >> si >> ti;
    g.heads.resize(ni + 1);
    while(mi--){
        int u,v,capacity;
        cin >> u >> v >> capacity;
        g.add(u,v,capacity);
    }

    return 0;
}
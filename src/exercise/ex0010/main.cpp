#include<bits/stdc++.h>
using namespace std;
using gg = long long;

struct arc{
    int to,val,next;
};
class Graph{
public:
    array<int,110000> head;
    int cnt;
    array<arc,110000> arcs; 
    void add(int u,int v,int val){
        arcs[cnt] = arc{
            v,val,head[u]
        };
        head[u] = cnt++;
    }
    Graph(){
        head.fill(-1);
    }
}g;
gg ni,mi;

int bfs(int i){
    array<bool,110000> head_visited;
    head_visited.fill(0);
    int max = i;
    queue<int> q;
    if(g.head[i]!=-1){
        q.push(i);
        while(!q.empty()){
            auto o = q.front();
            if(head_visited[o]){
                q.pop();
                continue;
            }
            head_visited[o] = true;
            if(o > max)
                max = o;
            // for(arc* b;b!=nullptr;b = b.next)
            for(int a = g.head[o];a!=-1;a = g.arcs[a].next){
                q.push(g.arcs[a].to);
            }
            q.pop();
        }
    }
    return max;
}
// int dfs(int i){
//     int max = i;
//     array<bool,110000> head_visited;
//     head_visited.fill(0);
//     function<void(int)> _dfs;
//     _dfs = [&max,&_dfs,&head_visited](int i){
//         // 这个更新的位置之前写错了，访问节点后就可以直接更新max
//         // if(g.head[i]!=-1) 判断的是是否有arc，没有arc的节点也可以被访问
//         if(i > max)
//             max = i;
//         if(head_visited[i]){
//             return ;
//         }
//         if(g.head[i]!=-1){
//             head_visited[i] = true;
//             for(int a = g.head[i];a!=-1;a = g.arcs[a].next){
//                 _dfs(g.arcs[a].to);
//             }
//         }
//     };
//     _dfs(i);
//     return max;
// }
int main(){    
    cin >> ni >> mi;
    
    int u,v;
    while(mi--){
        cin >> u >> v;
        g.add(u,v,1);
    }
    for(int i = 1;i<=ni;i++){
        cout << bfs(i) <<' ';
    }
    return 0;
}

/*
4 3
1 2
2 4
4 3

0   -1  [2  1   -1] 
1   0   [4  1   -1]
2   1   [3  1   -1]
3   -1  []
4   2   []

5 4
1 2 
3 4 
1 3 
1 5 

0   -1  [2  1   -1]
1   3   [4  1   -1]
2   -1  [3  1   0]
3   1   [5  1   2]
4   -1  []
5   -1  []

dfs(1) = 
1
5   3   2
""  4   ""
所以max = 5

dfs(2) = 2
dfs(3) = 4
dfs(4) = 4
        
*/

#include <iostream>
#include <ostream>
#include <limits>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include <ctime>
#include "../headers/ex9.h"
using namespace std;
namespace ex9
{

    struct node_info
    {
        public:
            node_info (int i,int w)
                : index (i), weight (w) {}
            node_info ()
                : index(0),weight(0) {}
            node_info (const node_info & ni)
                : index (ni.index), weight (ni.weight) {}

            //仿函数类 
			friend
            bool operator < (const node_info& lth,const node_info& rth)
            {
                return lth.weight > rth.weight ; // 为了实现从小到大的顺序
            }

        public:
            int index; // 结点位置
            int weight; // 权值
    };

    struct path_info
    {
        public:
            path_info ()
                : front_index(0), weight (numeric_limits<int>::max()) {}

        public:
            int front_index;
            int weight;
    };

// single source shortest paths
    class ss_shortest_paths
    {

        public:
            ss_shortest_paths (const vector<vector<int> >& g,int end_location)
                :no_edge (-1), end_node (end_location), node_count (g.size()) , graph (g)
            {}

            // 打印最短路径
            void print_spaths () const
            {
                cout << "min weight : " << shortest_path << endl;
                cout << "path: " ;
                copy (s_path_index.rbegin(),s_path_index.rend(),
                      ostream_iterator<int> (cout, " "));
                cout << endl;
            }

            // 求最短路径
            void shortest_paths ()
            {
                vector<path_info> path(node_count);
                //默认类型比如int是大顶堆，本例仿函数是小顶堆（权值小的先出列） 
                priority_queue<node_info,vector<node_info> > min_heap;
                min_heap.push (node_info(0,0));    // 将起始结点入队

                while (true)
                {
                    node_info top = min_heap.top ();    // 取出最大值
                    min_heap.pop ();

                    // 已到达目的结点
                    if (top.index == end_node)
                    {
                        break ;
                    }
                    // 未到达则遍历
                    for (int i = 0; i < node_count; ++ i)
                    {
                        // 顶点top.index和i间有边，且此路径长小于原先从原点到i的路径长
                        if (graph[top.index][i] != no_edge &&
                                (top.weight + graph[top.index][i]) < path[i].weight)
                        {
                        	//为什么要push？ 
                            min_heap.push (node_info (i,top.weight + graph[top.index][i]));
                            path[i].front_index = top.index;
                            path[i].weight = top.weight + graph[top.index][i];
                        }
                    }
                    //对上一段循环遍历补充：节点能不能往回走，可以，因为如果往回走的话，最终会被剪枝掉 
                    if (min_heap.empty())
                    {
                        break ;
                    }
                }

                shortest_path = path[end_node].weight;
                int index = end_node;
                s_path_index.push_back(index) ;
                while (true)
                {
                    index = path[index].front_index ;
                    s_path_index.push_back(index);
                    if (index == 0)
                    {
                        break;
                    }
                }
            }

        private:
            vector<vector<int> >    graph ;            // 图的数组表示
            int                        node_count;        // 结点个数
            const int                no_edge;        // 无通路
            const int                end_node;        // 目的结点
            vector<int>                s_path_index;    // 最短路径
            int                        shortest_path;    // 最短路径
    };

    int fex9()
    {
        unsigned seed;
        srand(seed);

        int length=1000;
        for(length; true; length+=1000)
        {
            //初始化graph
            vector<vector<int> > graph (length);
            for (int i = 0; i < length; ++ i)
            {
                graph[i].resize (length);
            }
            for (int i = 0; i < length; ++ i)
            {
                for (int j = 0; j < length; ++ j)
                {
                    graph[i][j] = -1;
                }
            }
            for(int i=0; i<length; i++)
            {
                //随机数找三分之一个
                int temp=length/3;
                for(int j=1; j<temp; j++)
                {
					//列值从1开始 ，并赋随机值
                    graph[i][rand() % length  + 1]=rand() % (length-2) + 1;
                }
            }
            clock_t a=clock();
            for(int i=0; i<1; i++)
            {
                ss_shortest_paths ssp (graph, length);
                ssp.shortest_paths ();
//            	ssp.print_spaths ();
			}
            clock_t b=clock();
            cout<<b-a<<endl;
        }
//        graph[0][1] = 2;
//        graph[0][2] = 3;
//        graph[0][3] = 4;
//        graph[1][2] = 3;
//        graph[1][5] = 2;
//        graph[1][4] = 7;
//        graph[2][5] = 9;
//        graph[2][6] = 2;
//        graph[3][6] = 2;
//        graph[4][7] = 3;
//        graph[4][8] = 3;
//        graph[5][6] = 1;
//        graph[5][8] = 3;
//        graph[6][9] = 1;
//        graph[6][8] = 5;
//        graph[7][10] = 3;
//        graph[8][10] = 2;
//        graph[9][8] = 2;
//        graph[9][10] = 2;
        return 0;
    }
}

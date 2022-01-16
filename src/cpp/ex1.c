#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "../headers/ex1.h"
//define没有命名空间，只能用ex1的1来做命名
#define num1 3
using namespace std;
namespace ex1
{
//物品个数
    int n=5;
//背包容量
    int c=30;
//物品重量
    vector<int> w= {16,15,15};
//物品价值
    vector<int> v= {45,25,25};
//最高价值
    int bestP;
//最优路径
    vector<int> bestPath(num1);
//记录阶段重量
    vector<int> varC(num1+1);
//记录阶段价值
    vector<int> value(num1+1);
//记录阶段path
    vector<int> path(num1);
//性价比
    vector<float> costP(num1);

    float bound(int stage)
    {
        return (*max_element(costP.begin()+stage,costP.end()))*(c-varC[stage]);
    }

    void backTrace(int stage)
    {
        if(stage>=n)
        {
            //cout<<"触发约束条件，结束，当前path为："
            //    <<' '<<path[0]<<' '<<path[1]<<' '<<path[2]<<' '<<varC[stage]<<" stage为:"<<stage<<endl;
            if(value[stage]>bestP)
            {
                bestP=value[stage];
                copy(path.begin(),path.end(),bestPath.begin());
            }
            return ;
        }
        int temp1=0;
        for(temp1; temp1<2; temp1++)
        {
            path[stage]=temp1;
            varC[stage+1]=varC[stage]+w[stage]*temp1;
            if(varC[stage+1]<=c&&bound(stage)+value[stage]>bestP)
            {
                value[stage+1]=value[stage]+v[stage]*temp1;
                backTrace(stage+1);
            }
            else
            {
                //cout<<"触发约束条件，结束，当前path为："
                //    <<' '<<path[0]<<' '<<path[1]<<' '<<path[2]<<' '<<varC[stage]<<" stage为:"<<stage<<endl;
                if(value[stage]>bestP)
                {
                    bestP=value[stage];
                    copy(path.begin(),path.end(),bestPath.begin());
                }
                return ;
            }
        }
    }
    void fex1()
    {
        unsigned seed;
        srand(seed);
        for(n=1000; true; n+=100)
        {
            vector<int> w_temp;
            w=w_temp;
            vector<int> v_temp;
            v=v_temp;
            //初始化相关数组
            for(int i=0; i<n; i++)
            {
                w.push_back(rand() % n+1);
                v.push_back(rand() % (2*n)+0);
            }
            c=(int)((n+1)*n*1.0/6);
            bestP=0;
            vector<int> bestPath_temp(n);
            bestPath=bestPath_temp;
            vector<int> varC_temp(n+1);
            varC=varC_temp;
            vector<int> value_temp(n+1);
            value=value_temp;
            vector<int> path_temp(n);
            path=path_temp;
            vector<float> costP_temp(n);
            costP=costP_temp;
            //求解 
            int temp3=0;
            for(temp3; temp3<num1; temp3++)
            {
                costP[temp3]=(float)v[temp3]/w[temp3];
            }
            clock_t a=clock();
            backTrace(0);
            clock_t b=clock();
            cout<<b-a<<endl; 
        }
        return ;
    }
}


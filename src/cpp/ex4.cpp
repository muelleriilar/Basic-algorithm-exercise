#include <iostream>
#include <algorithm>
#include <vector>
#include "../headers/ex4.h"
#include "../headers/ex0.h"
#include "windows.h"
#include "sysinfoapi.h"
#include<stdio.h>
using namespace std;
namespace ex4
{
    //声明两个字符序列
    vector<char> charList1= {'p','h','q','g','h','u','m','e','a','y','l','n','l','f','d','x','f','i','r','c','v','s','c','x','g','g','b','w','k','f',
                             'n','q','d','u','x','w','f','n','f','o','z','v','s','r','t','k','j','p','r','e','p','g','g','x','r','p','n','r','v','y',
                             's','t','m','w','c','y','s','y','y','c','q','p','e','v','i','k','e','f','f','m','z','n','i','m','k','k','a','s','v','w',
                             's','r','e','n','z','k','y','c','x','f'
                            };
    vector<char> charList2= {'m','x','w','t','p','t','t','t','y','k','d','u','y','v','x','j','b','z','h','q','u','p','x','k','x','x','v','e','b','m',
                             'c','s','i','x','h','v','d','h','c','j','x','o','n','z','h','s','s','p','m','k','l','y','h','l','a','b','f','a','r','y',
                             'o','s','s','k','u','g','b','k','i','u','f','f','d','l','y','e','r','x','l','m','h','g','p','a','f','a','w','z','h','n',
                             't','v','e','e','j','z','a','t','j','m'
                            };

    vector<char> temp;

    vector<vector<int>> record;

    int lcs(int i,int j)
    {
        //判断当前参与比较的两个子序列的长度是否都不为0,i和j指向对应序列的最后一个
        if(i<0||j<0)
        {
            return 0;
        }

        //访问数组之前需要先判断是否可能越界
        if(record[i][j]!=-1)
        {
            return record[i][j];
        }

        //判断两个序列最后一位是否相等
        if(charList1[i]==charList2[j])
        {
            //相等的状态转移
            int len=lcs(i-1,j-1);
            record[i][j]=len+1;
            return len+1;
        }
        else
        {
            //不相等的状态转移
            int a=lcs(i,j-1);
            int b=lcs(i-1,j);
            if(a>b)
            {
                record[i][j]=a;
                return a;
            }
            else
            {
                record[i][j]=b;
                return b;
            }
        }
    }
    void fex4()
    {
        for(int len=100; true; len+=100)
        {
            vector<char> a;
            vector<char> b;
            unsigned seed;
            srand(seed);
            for(int i=0; i<100; i++)
            {
                char number = rand() % 26 + 97;
                a.push_back(number);
            }

            for(int i=0; i<100; i++)
            {
                char number = rand() % 26 + 97;
                b.push_back(number);
            }
            charList1=a;
            charList2=b;

            vector<int> clear;

            for(int j=0; j<len; j++)
            {
                clear.push_back(-1);
            }

            vector<vector<int>> c;
            record=c;
            for(int i = 0; i <len; i++)
            {
                //直接赋值是深拷贝
                record.push_back(clear);
            }

//            double dur;
//            clock_t start,end;
//            start = clock();
////            DWORD t1= GetTickCount();
//            lcs(len-1,len-1);
//            end = clock();
//            dur = (double)(end - start);
////            DWORD t2= GetTickCount();
//            cout<<dur/CLOCKS_PER_SEC<<endl;
            
            ex0::Timer timer;
            timer.startTiming();
            lcs(len-1,len-1);
            timer.endTiming();
            cout<<timer.showMS()<<endl;
            
            
        }
    }
}

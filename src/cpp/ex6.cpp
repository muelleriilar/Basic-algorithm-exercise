#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "../headers/ex6.h"
using namespace std;
namespace ex6
{
    bool comp(Activity a,Activity b)
    {
        return a.end<b.end;
    }

    void Select(Activity act[],int n)
    {
        int begin=act[0].start;
        for(int i=0; i<n; i++)
            if(act[i].start>=begin)
            {
                begin=act[i].end;
                act[i].mark=1;
            }
    }
    
    void fex6(int length)
    {
    	unsigned seed;
        srand(seed);
        int j;
        Activity act[length];
        for(int i=0; i<length; i++)
        {
        	//取随机数 
            act[i].start=rand() % length + 0;
            //如果不幸取到最后一个 
			if(act[i].start==length)
            {
            	act[i].start=rand() % length - 1 + 0;
			}
			
            act[i].end=rand() % (length-act[i].start) + act[i].start+3;	
			
            act[i].num=i;
            act[i].mark=0;
//            cout<<i<<endl;
        }
        cout<<length<<' ';
        sort(act,act+length,comp);
        
        clock_t a=clock();
        for(int i=0;i<10000;i++)
        {
        	Select(act,length);	
		}
        clock_t b=clock();
        
        cout<<b-a<<endl;
        
        return ; 
    }
}

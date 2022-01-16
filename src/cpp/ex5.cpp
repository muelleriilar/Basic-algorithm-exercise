#include <iostream>
#include <algorithm>
#include <vector>
#include "../headers/ex4.h"
#include "../headers/ex0.h"
#include "windows.h"
#include "sysinfoapi.h"
#include<time.h>
#include<stdio.h>
using namespace std;
namespace ex5
{
	void line(){
		vector<int> a;
		//10000000  56995894
		//100000000 574941334
		int length=100*1000*1000;
		for(int i=0;i<length;i++)
		{
			a.push_back(i);
		}
		for(int j=0;j<10;j++)
		{
			ex0::Timer timer;
			timer.startTiming();
			for(int i=0;i<length;i++)
			{
				if(i==a[i])
				{
					;
				}
			}
			timer.endTiming();
			cout<<timer.showClockCycles()<<endl;
		}
	}
}

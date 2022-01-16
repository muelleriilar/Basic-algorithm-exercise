#include <iostream>
#include <algorithm>
#include "../headers/ex0.h"
#include <intrin.h>
#include <stdio.h>

using namespace std;
namespace ex0
{
	///////////////////////////////////////
	//class Timer 的实现 
    inline unsigned __int64 Timer::GetCycleCount()
    {
		//windows 不需要内联汇编，有库 
		return __rdtsc();
    }
    unsigned long Timer::startTiming()
    {
    	this->startTime=(unsigned long)GetCycleCount();
    	return this->startTime;
	}
	unsigned long Timer::endTiming()
	{
		this->endTime=(unsigned long)GetCycleCount();
		return this->endTime;
	}
    unsigned long Timer::showClockCycles()
    {
    	return (this->endTime-this->startTime)*1.0;
	}
	unsigned long Timer::showNS()
    {
    	return (this->endTime-this->startTime)*1.0*0.0000000004*1000*1000*1000;
	}
	unsigned long Timer::showUS()
    {
    	return (this->endTime-this->startTime)*1.0*0.0000000004*1000*1000;
	}
	unsigned long Timer::showMS()
    {
    	return (this->endTime-this->startTime)*1.0*0.0000000004*1000;
	}
	
	///////////////////////////////////////
	//class randVec 的实现
	//返回值是值传递还是引用传递？ 
	vector<int> randArray1(int length)
	{
		unsigned seed;
        srand(seed);
		vector<int> randvec;
		int temp;
		for(temp=0;temp<length;temp++)
		{
			randvec.push_back(rand() % length + 0);	
		}
		return randvec;
	}
}

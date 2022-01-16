#include <vector>
#include <iostream>
using namespace std;
#ifndef __EX0_H__
#define __EX0_H__
// function **declarations**
namespace ex0{
	//定时器类
	class Timer
    {
        public:
            unsigned long startTime;
            unsigned long endTime;
            inline unsigned __int64 GetCycleCount();
            unsigned long startTiming();
            unsigned long endTiming();
            //单位K 
            unsigned long showClockCycles();
            unsigned long showNS();
            unsigned long showUS();
            unsigned long showMS();
    };
	//随机数类 
	class randVec
	{
		//随机int序列，有重复 
		vector<int> randArray1(int length); 
	};
};
#endif

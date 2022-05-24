#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
//using namespace std;
#ifndef __EXtemplateTest_H__
#define __EXtemplateTest_H__
#include "../headers/ex11.h"
namespace ex11
{
	template<typename T>
	T Bob1 <T>::changeA(T b)
	{
		this->a=b;
		return this->a;
	}
}
#endif


#include <iostream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include "../headers/ex3.h"
#define num2 5
using namespace std;
using namespace std::chrono;
namespace ex3
{
    //排好序的容器
	vector<int> orderedArray; 
    int BinarySearch(int array[], int n, int value)
    {
        int left = 0;
        int right = n - 1;

        while (left <= right)
            {
                int middle = left + ((right - left) >> 1);

                if (array[middle] >= value)  // 因为是找到最小的等值下标，所以等号放在这里
                    right = middle - 1;
                else
                    left = middle + 1;
            }

        if (left < n && array[left] == value)
            return left;

        return -1;
    }
    void fex2()
    {
        cout<<"woc"<<endl;
	 
    }
}


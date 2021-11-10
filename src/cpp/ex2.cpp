#include <iostream>
#include <algorithm>
#include "../headers/ex2.h"
#define num2 5
using namespace std;
namespace ex2 {
	//物品个数
	int n=num2;
	//背包容量
	int c=10;
	//物品重量
	vector<int> w= {2,2,6,5,4};
	//物品价值
	vector<int> v= {6,3,5,4,6};

	optSub(int i,int j){
		if(i==n-1){
			//判断背包容量能否装下最后一个
			if(j>=w[n-1]){
				//能装下最后一个
				return v[n-1]; 
			} 
			else{
				return 0;
			}
		}
		//非最后一个,看看能不能装下这一个（指第i+1个，optSub(0，c)时检查的是第一个物品，对应的重量是w[i]） 
		if(j>=w[i]){
			int a=optSub(i+1,j);
			int b=optSub(i+1,j-w[i])+v[i];
			if(a>b){
				return a;
			}else {
				return b;
			}
		} else{
			int a=optSub(i+1,j);
			return a;
		}
	}
	void fex2() {
		int d=0;
		d=optSub(0,c);
		cout<<"背包所能装取的最大价值为"<<d<<endl;
	}
}


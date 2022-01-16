#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include<string>
#include "../headers/ex7.h"
using namespace std;
namespace ex7
{
    class D
    {
        public:
            D(double d):d_(d) {}
            operator int() const
            {
                std::cout<<"(int)d called!"<<std::endl;
                return static_cast<int>(d_);
            }
        private:
            double d_;
    };

    int add(int a,int b)
    {
        return a+b;
    }

    void fex7()
    {
        D d1=1.1;
        D d2=2.2;
        std::cout<<add(d1,d2)<<std::endl;
        system("pause");
        return ;
    }
}

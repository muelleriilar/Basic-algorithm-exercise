#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;
class StringAppend {
public:
    // 默认是存在构造函数传参的隐式转换的，隐式转换形式如下
    // CxString string1(int size);
    // CxString string1(24);    无隐式转换
    // CxString string2 = 10;   有隐式转换
    // CxString string2 = 'c';  有隐式转换
    // explicit 相当于禁用了隐式转换
    explicit StringAppend(const string& str) : ss(str){}
    // 函数加上const后缀的作用是表明函数本身不会修改类成员变量
    void operator() (const string& str) const {
         cout << str << ' ' << ss << endl;
    }
private:
    const string ss;
};

class Animal{
    const int age;
    Animal(int a):age(a){
        // 此处还是构造函数的内容
        // const 成员必须用参数列表来初始化
        // 参数列表是从右向左初始化的，要注意初始化的顺序
    }
    void operator+(const Animal &A) const {
        cout << A.age << '\n';
    }
};

int main() {
    vector<int> a={1,2,3};
    
    sort(a.begin(),a.end(),[](int a,int b){
        return a > b;
    });

    for(auto x:a){
        cout << x << ' ';
    }
    cout << '\n';
    
    StringAppend myFunctor2("and world!");
    
    myFunctor2("Hello");
}
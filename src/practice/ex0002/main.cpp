#include <iostream>
using namespace std;
int main(){
    int n=10;
    // 打印出来的是 10,9,8,7,...,2,1所以for循环先执行代码块在，再执行后面的语句
    for (;n>0;n--){
        cout<<n<<',';
        n--;
        cout<<n<<'\n';
    }
    cout<<'\n';
    // 注意分支是否可以化简
}
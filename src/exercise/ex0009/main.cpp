#include<bits/stdc++.h>
#include <regex>
using namespace std;
using gg = long long;
gg ni;
struct timespec t1, t2;
vector<int> pre;
int main(){
    clock_gettime(CLOCK_MONOTONIC, &t1);
    
    
    
    regex reg(R"(<(.*)>\w*\d+</\1>)");
    cout << regex_match(R"(<div>123</div>)",reg) << '\n';
    cout << regex_match(R"(<div>abc123</div>)",reg) << '\n';
    cout << regex_match(R"(<div>a123</div>)",reg) << '\n';
    cout << regex_match(R"(<div>a123</di>)",reg) << '\n';


    clock_gettime(CLOCK_MONOTONIC, &t2);
    cout << "time spends: " << (double)((t2.tv_sec-t1.tv_sec) + (t2.tv_nsec-t1.tv_nsec)/1000000) << '\n';
    return 0;
}

/*
    \w 表示字符
    \d 表示数字
*/
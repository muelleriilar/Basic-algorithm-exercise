#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main(){
    // 输入输出技巧
    ios::sync_with_stdio(false);
    cin.tie(0);
    // 和下面的setw一起用
    cout<<setfill('0');
    gg mi,ni,ai,bi,ri,ki;
    cin>>mi>>ni>>ai>>bi>>ri;
    for(gg i=0;i<mi;i++){
        for(gg j=0;j<ni;j++){
            cin>>ki;
            // 这个三目+赋值好用
            ki=(ki>ai and ki <bi ?ri:ki);
            // 特判最后一列空格 好用！
            cout<<setw(3)<<ki<<(j==ni-1 ? "":" ");
        }
        cout<<'\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni,ki;
    gg no=0;
    cin>>ni>>ki;
    char a[100000]={0};
    for(int i=0;i<ki;i++){
        int left,right;
        cin>>left>>right;
        // constent then change left value flag
        if(right==0){
            a[left]=1;
            continue;
        }
        // uninitialized right value
        if(a[right]==0){
            no++;
            
        }
        a[left]=1;
        continue;
    }
    cout<<no<<'\n';
}
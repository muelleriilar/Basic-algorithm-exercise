#include <bits/stdc++.h>
using namespace std;
using gg =long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Ti,ki,n1i,bi,ti,n2i;
    cin>>Ti>>ki;
    for(;ki>0;ki--){
        cin>>n1i>>bi>>ti>>n2i;
        if(ti>Ti){
            cout<<"not enough tokens. Total = "<<Ti<<".\n";
            continue;
        }
        if(n2i>n1i==bi){
            Ti+=ti;
            cout<<"Win "<<ti<<". Total="<<Ti<<'\n';
        }
        Ti-=ti;
        cout<<"Lose "<<ti<<". Total="<<Ti<<'\n';
        if(Ti==0){
            cout<<"Game Over.\n";
            break;
        }
    }
    return 0;
}

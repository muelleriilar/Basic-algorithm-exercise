#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg N = 1010;
gg n,m;
gg V[N],W[N];
gg f[N][N];
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> V[i] >> W[i];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            f[i][j] = f[i - j][j];
            if(j >= V[i]) f[i][j] = max(f[i][j], f[i - 1][j - V[i]] + W[i]);
        }
    }
    
    cout << f[n][m] << '\n';
    return 0;
}
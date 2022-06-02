#include <iostream>
using namespace std;
int main(){
    int n;
    int x=0;
    std::cin>>n;

    while (n!=1){
        x++;
        if(n%2==0){
            n=n/2;
        }else {
            if(n=(3*n+1)/2);
        }
    }
    std::cout<<x<<'\n';
}
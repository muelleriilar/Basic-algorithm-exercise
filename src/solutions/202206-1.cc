#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
  int ni;
  vector<double> data;
  cin >> ni;
  data.resize(ni);
  for (auto &a:data)
    cin >> a;
  double avg = accumulate(data.begin(),data.end(),0.0)/ni;
  double d = accumulate(data.begin(), data.end(), 0.0, [&avg](double left, double e){
    return left + (e - avg)*(e - avg);
  })/ni;
  for (auto &a:data) 
    printf("%f\n", (a - avg)/sqrt(d));
}
/*
test case:
cmake ../;make;echo -e "7\n-4 293 0 -22 12 654 1000"|./Basic-algorithm-exercise

普通c++14秒了, 我记得考场做这道题的时候直接写会有精度问题, 需要化简表达式, 还是说c++ 14做了优化?
*/
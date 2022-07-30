#include <bits/stdc++.h>
using namespace std;
using gg = long long;
template <int N> struct A {
  constexpr A() : isPrime(), primes() {
    for (int i = 0; i < N; i++) {
      isPrime[i] = true;
    }
    for (int i = 2; i < N; i++) {
      if (isPrime[i] == true) {
        primes[cnt++] = i;
      }
      for (int j = 0; j <= cnt; j++) {
        gg a = i * primes[j];
        if (a > N)
          break;
        isPrime[a] = false;
        // 保证不重复筛, 但是不知道为什么
        int c = i % primes[j];
        if (c == 0)
          break;
      }
    }
  }
  int cnt = 0;
  int primes[N + 10];
  bool isPrime[N + 10];
};

int main() {
  constexpr auto a = A<100>();
  for (auto e : a.primes)
    cout << e << endl;
}
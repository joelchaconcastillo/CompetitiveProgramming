#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    long long n, k;
    cin >> n>> k;
    k--;
    long long f =n/2;
    cout << (k + (n % 2) * k / f) % n + 1 <<endl;
  }
  return 0;
}

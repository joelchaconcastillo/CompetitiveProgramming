#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >>t;
  while(t--)
  {
    long long n;
    cin >> n;
    cout <<fixed<< (long long)floor((-1.0+sqrt(1+8*n))/2.0)<<endl;
  }
  return 0;
}

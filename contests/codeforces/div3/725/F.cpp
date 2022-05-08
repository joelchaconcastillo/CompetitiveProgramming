#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >>t;
  long long l, r;
  while(t--)
  {
    cin >>l>>r; 
    long long s=0;
    while(l!=0 || r!=0)
      s += (r-l), l/=10, r/=10;
    cout << s<<endl;
  }
  return 0;
}

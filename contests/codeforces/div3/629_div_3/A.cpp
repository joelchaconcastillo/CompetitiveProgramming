#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >>t ;
  while(t--)
  {
     long long a, b;
     cin >>a >>b;
     long long d = a/b;
     if( d*b < a) d++;
     cout << d*b - a <<endl;
  }
  return 0;
}

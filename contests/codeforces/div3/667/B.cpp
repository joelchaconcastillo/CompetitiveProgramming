#include <bits/stdc++.h>
using namespace std;
long long greedy(long long x, long long a, long long y, long long b, long long n)
{
   long long d1 = a-x, d2=b-y;
   if( n > d1) a -=d1, n-=d1;
   else a -=n, n=0;
   if( n > d2) b -=d2;
   else b -=n;
   return a*b;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     long long x,y,a,b, n;
     cin>>a>>b>>x>>y>>n;
     cout << min(greedy(x,a,y,b,n),  greedy(y,b,x,a,n)) <<endl;
  }
  return 0;
}

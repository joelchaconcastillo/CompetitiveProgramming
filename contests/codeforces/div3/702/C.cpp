#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  unordered_map<long long, bool> intcubic;
  for(long long i = 1; i <= 10000; i++) intcubic[i*i*i]=true;
  while(t--)
  {
     long long x;
     cin>>x;
     bool f = 0;
     for(long long b =1; b*b*b < x; b++)
     {
        long long a = x-b*b*b;
	if( intcubic[a]){ f=1; break;}
     }
     if(!f) cout << "NO\n";
     else cout << "YES\n";
  }
  return 0;
}

#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
bitset<MAX_N> s;
vector<int> p;
void init_sieve()
{
  s.set();
  s[0]=s[1]=0;
  for(long long i =2; i <= (MAX_N); i++)
  {
     if(!s[i]) continue;
     for(long long j = i*i; j <= (MAX_N); j +=i) s[j]=0;
     p.push_back(i);
  }
}
int count_pf(int n)
{
   int idx = 0, c = 1;
   while(p[idx]*p[idx]<= n)
   {
      int po = 0;
      while((n%p[idx])==0) n/=p[idx], po++;
      if(po)
      c *=(po+1);
      idx++; 
   }
   if( n!=1 )c*=2;
   return c;
}
int main()
{
  init_sieve();
  int L, U, n;
  cin >>n;
  while(n--)
  {
     cin >>L>>U;
     pair<int, int> maxd(-1, 0);
     for(int i = L; i <=U; i++)
     {
	 int v = count_pf(i);
	 if(maxd.first<v) maxd =make_pair(v, i);
     }
     cout << "Between "<<L<<" and "<<U<<", "<<maxd.second<<" has a maximum of "<<maxd.first<<" divisors."<<endl;
  }
  return 0;
}

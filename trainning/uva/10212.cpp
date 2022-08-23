#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long N, M;
  while(cin >> N >> M)
  {
     long long p = 1;
     long long m = 1e9;//--> max LL 1x10^19 so i x N = 1x10^9 * 1x10^9 = 1 x10^18
     for(long long i = N; i >= N-M+1; i--)
	{
	  p *=(i%m);
	  while( p%10 == 0) p/=10;
	  p%=m;
	}
	p%=10;
     cout <<p<<endl;
   }
  return 0;
}

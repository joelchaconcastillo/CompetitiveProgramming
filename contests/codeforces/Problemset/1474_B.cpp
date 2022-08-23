#include <bits/stdc++.h>
using namespace std;
vector<long long> p;
const long long MAX_N = 100001;
bitset<MAX_N+2> b;
void primes()
{
   b.set();
   b[0]=b[1]=0;
   for(long long i = 2; i <= MAX_N; i++)
   {
	if(!b[i]) continue;
	for(long long j = i*i; j <= MAX_N; j += i) b[j]=0;
	if(b[i])p.push_back(i);
   }
}
int main()
{
  int t;
  cin>>t;
  primes();
  while(t--)
  {
     int d;
     cin>>d;
     int l=0, r=p.size()-1;
     while( l < r )
     {
	int m = (r+l)/2;
	if( p[m] >= d+1 ) r=m;
	else l = m+1;
     }
     int n1 = p[r];
     l=r, r=p.size()-1;
     while( l < r )
     {
	int m = (r+l)/2;
	if( p[m] >= n1+d ) r=m;
	else l = m+1;
     }
     cout << min(1ll*n1*n1*n1, 1ll*n1*p[r])<<endl;
  }	
  return 0;
}

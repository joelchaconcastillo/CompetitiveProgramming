#include <bits/stdc++.h>
using namespace std;
long long m=1e9+7;
long long gcd(long long a, long long b){  return (b)?gcd(b,a%b):a;}
long long lcm(long long a, long long b){return a/gcd(a,b)*b;}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >>t;
  while(t--)
  {
	long long n;
	cin >>n;
	long long ans=2LL*n, x=1LL;
	for(long long i=2; x <= n; i++)
        {
	  x = lcm(x, i);
	  ans += n/x;
	  ans %=m;
        }
	cout << ans<<endl;
  }
  return 0;
}

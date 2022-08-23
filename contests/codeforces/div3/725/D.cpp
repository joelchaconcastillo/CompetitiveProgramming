#include <bits/stdc++.h>
#define MAXN 2e5
using namespace std;
int main()
{
  vector<int> g(MAXN, 0), p;
  g[0]=g[1]=1;
  for(int i = 2; i<MAXN; i++)
  {
     if(g[i])continue;
     for(int j = 2*i; j<MAXN; j+=i) g[j]=1;
     p.push_back(i);
  }
  int t;
  cin >>t;
  while(t--)
  {
    int a,b,k, sumexp=0, m=2;
    cin >>a>>b>>k;
    if(a<b)swap(a,b);
    if(a==b)m=0;
    else if(__gcd(a,b)==a || __gcd(a,b)==b)m=1;
    for(int i = 0;p[i]*p[i]<=a || p[i]*p[i]<=b ; i++)
    {
         int ca=0, cb=0; 
	  while(a%p[i]==0)a/=p[i], ca++;
          while(b%p[i]==0)b/=p[i], cb++; 
	sumexp+=ca+cb;
    }
    if(a>1)sumexp++;
    if(b>1)sumexp++;
    if( m <= k && k <= sumexp)
 
       if((m==1 && k==1) || k!=1)cout <<"YES\n";
       else cout <<"NO\n";
//    else if( k!=1 && m <= k && k <= sumexp)cout <<"YES\n";
    else cout <<"NO\n";
  }
  return 0;
}

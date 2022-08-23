#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int mx=5e5;
  vector<int> p, g(mx,0);
  g[0]=g[1]=1;
  for(int i = 2; i < mx; i++)
  {
    if(g[i])continue;
    for(int j = 2*i; j < mx; j+=i) g[i]=1;
    p.push_back(i);  
  }
  long long n,m;
  while(cin>>n>>m)
  {
    long long n2=n, m2=m;
    bool f=1;
    for(int i=0; i < mx && p[i]*p[i]<=m2; i++)
    {
	int cnt1=0, cnt2=0;
	if(m2%p[i]==0)
 	{
	   while(m2%p[i]==0)m2/=p[i], cnt1++;
	   n2=p[i];
	   while(n2<=n) cnt2+=n/n2, n2*=p[i];
	}
	if(cnt1 > cnt2){f=0; break;}
    }
    if(m2!=1 && n < m2) f=0;
    if(f)  cout << m <<" divides "<<n<<"!"<<endl;
    else cout << m<<" does not divide "<<n<<"!"<<endl; 
  }
  return 0;
}

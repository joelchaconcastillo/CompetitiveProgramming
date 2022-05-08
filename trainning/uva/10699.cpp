#include <bits/stdc++.h>
using namespace std;
int main()
{
  int MAXN=1e6;
  vector<int> g(MAXN,0), p;
  g[0]=g[1]=1;
  for(int i=2; i<MAXN; i++)
  {
     if(g[i])continue;
     for(int j = 2*i; j<MAXN; j+=i) g[j]=1;
     p.push_back(i);
  }
  int n;
  while(cin>>n)
  {
     if(n==0)break;
     int c=0, n2=n;
     for(auto i:p)
     {
	if(i>n)break;
	if(n%i==0)
	{
	  while(n%i)n/=i;
	  c++;
	}
	if(n==1)break;
     }
     cout<<n2<<" : "<<c<<endl;
  }
  return 0;
}

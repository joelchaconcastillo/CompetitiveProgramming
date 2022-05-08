#include <bits/stdc++.h>
#define N 5000
using namespace std;
vector<vector<int>>adj;
int p[N], r[N];
int find(int a){ return (a!=p[a])?(p[a]=find(p[a])):a;}
void unionf(int a, int b)
{
   a = find(a), b =find(b);
   if(r[a]>r[b]) p[b]=a;
   else 
   {
	p[a]=b;
	if(r[a]==r[b]) r[a]++;
   }
}
int main()
{
  int ite;
  long long d[5000];
  cin>>ite;
  while(ite--)
  {
    int n;
    cin>>n;
    for(int i=0; i < n; i++)cin>>d[i], p[i]=i,r[i]=0;
    adj.assign(n,vector<int>());
    int c=0;
    for(int i=0;i <n; i++)
    {
      for(int j=i+1; j<n;j++)
      {
	      if(d[i]!=d[j] && find(i) !=find(j) ) adj[i].push_back(j), unionf(i, j), c++;
      }
    }
    if(c<n-1)cout<<"NO\n";
    else
    {
	    cout <<"YES\n";
    for(int i=0; i <n; i++)
    {
	for(auto idx:adj[i])
		cout<<i+1<< " "<<idx+1<<endl;
    }
    }
  }
  return 0;
}

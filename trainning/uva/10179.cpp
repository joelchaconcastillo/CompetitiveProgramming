#include <bits/stdc++.h>
#define N 1<<17
bool g[N];
int p[N], sp=0;
int main()
{
   //memset(g, false, sizeof g);
   g[0]=g[1]=1;
   for(int i = 2; i < N; i++)
   {
    if(g[i])continue;
	for(int j = 2*i; j < N; j+=i) g[j]=1;
    p[sp++]=i;
   }
   int n;
   while(scanf("%d\n", &n))
   {
      if(n==0)break;
      int ans=n;
      for(int i = 0; p[i]*p[i]<=n; i++)
      {
	if(n%p[i]==0) ans -= ans/p[i];
	while(n%p[i]==0) n/=p[i];
      }
      if(n!=1) ans -= ans/n;
	printf("%d\n", ans);
   }
   return 0;
}

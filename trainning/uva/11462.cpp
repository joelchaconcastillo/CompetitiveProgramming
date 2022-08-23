#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  int d[2000001];
  while(scanf("%d\n", &n), n != 0)
  {
   // memset(d, 0, sizeof d); 
   for(int i = 0; i < n; i++) scanf("%d ", &d[i]);
   sort(d, d+n); 
   for(int i = 0; i < n; i++)
	{
	 printf("%d", d[i]);
	if(i<n-1)printf(" ");
	}
   printf("\n");
  }
  return 0;
}

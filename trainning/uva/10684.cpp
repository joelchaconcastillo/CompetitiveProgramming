#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  while(scanf("%d ", &n), n!=0)
  {
    int sum = 0, maxsum=INT_MIN;
    for(int i = 0; i < n; i++)
    {
       int d;
       scanf("%d ", &d);
	sum+=d;
	maxsum = max(maxsum, sum);
       if(sum < 0) sum=0;
    }
    if(maxsum >0) printf("The maximum winning streak is %d.\n", maxsum);
    else printf("Losing streak.\n");
  }
  return 0;
}

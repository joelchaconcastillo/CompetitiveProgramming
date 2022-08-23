#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
  {
     long s, d;
     scanf("%ld %ld\n", &s, &d);
     if( s-d>=0 && ((s+d) % 2 == 0 ))
     {
	printf("%ld %ld\n", (s+d)/2, (s-d)/2);
     }
     else printf("impossible\n");
  }
  return 0;
}

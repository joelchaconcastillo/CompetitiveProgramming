#include <bits/stdc++.h>

using namespace std;
int main()
{
  int n, k;
  while(scanf("%d %d\n", &n, &k)!= EOF)
  {
     int cig = n;
     int cont=0;
     while( n/k > 0)
     {	
	cig += n/k;
	n = n/k + n%k;
     }
     printf("%d\n", cig);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
 int s, a, b, c;
 while(scanf("%d %d %d %d\n", &s, &a, &b, &c))
 {
	 if( !a && !b && !c && !s) break;
  int T = 40;	 
  int total = T*2;
  total += ( (s+T)-a)%T;
  total += T;
  total += ( (b+T)-a)%T;
  total += ( (b+T)-c)%T;
  double d = ((double)total/T);
  d *=360.0;
  printf("%.0lf\n", d);
 }
}

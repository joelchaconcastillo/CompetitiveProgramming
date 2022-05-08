#include <bits/stdc++.h>
using namespace std;
int main()
{
   int h, m;
   while(scanf("%d:%d", &h, &m) != EOF , h != 0)
   {
	double h2 = 30.0*h + 0.5*m;
	double m2 =  6.0*m;
	double v = fabs(h2-m2);
	if(v >= 180) v=360-v;
	printf("%.3lf\n", v);
   } 
   return 0;
}

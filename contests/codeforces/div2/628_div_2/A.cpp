#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){return b == 0? a: gcd(b, a%b); }
int main()
{
  int t;
  scanf("%d\n", &t);
  for(int i = 0;  i < t; i++)
  {
     int x;
     bool found=false;
     scanf("%d", &x);
     for(int a = 1; a < x && !found; a++)
     {
	   int b = x-a;
	   int gcd_n = gcd(a,b);
	   if( gcd_n + (a*b/gcd_n) == x)
	   { 
		printf("%d %d\n", a, b);
		found=true;
	   }
     }
  }
  return 0;
}

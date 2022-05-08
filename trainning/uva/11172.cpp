#include <bits/stdc++.h>
using namespace std;
int main()
{
   int k;
   scanf("%d\n", &k);
   for(int i = 0; i<k; i++)
   {
      long a,b;
	scanf("%ld %ld\n", &a, &b);
//	a = abs(a);
//	b = abs(b);
	if( a > b) printf(">\n");
	else if( a < b) printf("<\n");
	else printf("=\n");
   }
}

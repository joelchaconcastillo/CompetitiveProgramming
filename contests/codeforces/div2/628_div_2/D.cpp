#include <bits/stdc++.h>
using namespace std;
int main()
{
 int u, v;
 scanf("%d %d\n", &u, &v);
 for(int a = 0; a < v; a++)
 {
    int b = v-a;
    if( (a ^ b) == u )
	{ 
	   printf("%d %d\n", a, b);
	   break;
	}
 }
 return 0;
}

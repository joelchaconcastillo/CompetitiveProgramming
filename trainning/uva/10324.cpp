#include <bits/stdc++.h>
using namespace std;
int main()
{
  int counter[1000005];
  char str_bin[1000005];
  int Case=1;
     int q;
  while( scanf("%s", str_bin) != EOF)
  {
     int cont = 0;
     counter[0] = 0;    
     int len = strlen(str_bin);
     for(int i = 1; i < len; i++)
     {
	if( str_bin[i] != str_bin[i-1])
	cont ++;
	counter[i]  = cont;
     }
     printf("Case %d:\n", Case++);
     scanf("%d", &q);
     int a, b;
     for(int i = 0; i < q; i++)
     {
	scanf("%d%d", &a, &b);
	if( a>b) swap(a,b);
	if((counter[b]- counter[a]) == 0)
	  printf("Yes\n");
	else
	  printf("No\n");
     }
  }
 return 0;
}

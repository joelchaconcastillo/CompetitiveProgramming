#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  while(scanf("%d", &n), n)
  {
     int cont = 0, a1=0, b1=0;
     for(int i = 0; i < 31; i++)
     {
       if( n &(1<<i))
        {  
	   cont++;
	   if( (cont%2)==0 )
 	   {
  	     b1 |= (1<<i);
	   }
	   else
	   {
	    a1 |= (1<<i);
	   }
        }
     }
     printf("%d %d\n", a1, b1);
  }
  return 0;
}

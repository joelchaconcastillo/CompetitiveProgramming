#include <bits/stdc++.h>
#define MAXSIZE 1048577
using namespace std;
int main()
{
  int l;
     scanf("%d", &l);
     for(int i = 0; i  < l; i++)
     {
        int D, I;
	scanf("%d %d", &D, &I);
	int cu = 1, cv = I;
	   for(int l = 0; l < D-1; l++)
	   {	
	      if( (cv%2)== 1 )
	      {     
		cu = (cu << 1);
		cv = (cv >> 1) + 1;
	      }
	      else if( (cv%2)== 0 )
	      {
		cu = (cu << 1)+1;
		cv = (cv >> 1);
   	      }
	   }
	printf("%d\n", cu);
     }
  return 0;
}

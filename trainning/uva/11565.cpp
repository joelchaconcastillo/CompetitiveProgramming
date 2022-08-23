#include <bits/stdc++.h>
using namespace std;
int main()
{
   int N;
   scanf("%d", &N);
   for(	int i = 0; i < N; i++)
   {
      int A, B, C;
      scanf("%d %d %d", &A, &B, &C);
      bool sol=false;
      for(int x = -22; x<=22 && !sol; x++)
	   if(x * x <= C)
         for(int y = -100; y<=100 && !sol; y++)
	    if( x != y && (x*x + y*y <= C))
            for(int z = -100; z<=100 && !sol; z++)
	         if( x != y && x != z && y !=z && ( (x*x + y*y + z*z) == C) && (x+y+z == A) && (x*y*z == B))
		 {
			sol=true;
			printf("%d %d %d\n", x, y, z);
		 }
       if(!sol)
	printf("No solution.\n");

   }
}

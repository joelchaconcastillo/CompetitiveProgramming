#include <bits/stdc++.h>
using namespace std;
int const c = 1024;
int grid[c*c];
int main()
{
 int T;
 scanf("%d\n", &T);
 while(T--)
 {
   memset(grid, 0, sizeof grid);
   int d, n;
   scanf("%d\n%d\n", &d, &n);
   for(int a = 0; a < n; a++)
   {
	int x, y, Size;
	scanf("%d %d %d\n", &x, &y, &Size);
	for(int i = max(0, x-d); i < min(c, x+d+1);i++)
	       for(int j = max(0,y-d); j<min(c, y+d+1); j++)
		  grid[i*c+j] += Size;
   }
   int maxv=-1, idx = -1, idy=-1;
   for(int i = 0; i <c; i++)
   {
      for(int j = 0; j <c; j++)
      {
	      if(grid[i*c+j] > maxv)
	      {
		 maxv = grid[i*c+j];
		 idx = i;
		 idy = j;
	      }
      }
   }
   printf("%d %d %d\n", idx, idy, maxv);
	

 }
}

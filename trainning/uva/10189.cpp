#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n, m, cont = 0;
   int grid[101][101];
   int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
   int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
  
   while(scanf("%d %d\n", &n, &m) != EOF && n!= 0 && m!=0)
   {
	if(cont !=0)
    	printf("\n");
	cont++;
   
    memset(grid, 0, sizeof grid);
    for(int i = 0; i < n; i++)
    {
      char cell;
      for(int j  = 0; j < m; j++)
      {
	scanf("%c", &cell);
	if(j==m-1)scanf("\n");
//	cout <<cell;
	if( cell == '*' )
	{
	 for(int k = 0; k < 8; k++)
	 {
	    if( i + dx[k] >= 0 && i+dx[k] < n && j+dy[k] >=0  && j+dy[k]<=m ) grid[i+dx[k]][j+dy[k]]++;
	 }
	 grid[i][j]=-10000;
	}
      } 
//	cout <<endl;
    }
    printf("Field #%d:\n", cont);

    for(int i = 0; i < n; i++)
    {
       for(int j = 0; j < m; j++)
       {
	if(grid[i][j] >=0 )
	printf("%d", grid[i][j]);
	else
	printf("*");
       }
	printf("\n");
    }
   }
   return 0;
}

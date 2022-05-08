#include <bits/stdc++.h>
//#include <stdio.h>
#include <string.h>
#define MAX 200
using namespace std;
int dr[]={1, 1, 0, -1, -1, -1, 0, 1};
int dc[]={0, 1, 1, 1, 0, -1, -1, -1};

int dfs(int c_r, int c_c, char grid[MAX][MAX], bool checked[MAX][MAX], int nr, int nc)
{
//	cout << grid[c_r] <<endl;
  if( c_r >= nr || c_c >= nc || c_r < 0 || c_c < 0)
    return 0;
  if( grid[c_r][c_c] !='W') return 0;
  if(checked[c_r][c_c]==true) return 0;
  checked[c_r][c_c] = true;
  int sum = 1;
  for(int i = 0; i < 8; i++)
  {
    sum += dfs(c_r+dr[i], c_c+dc[i], grid, checked, nr, nc); 
  }
  return sum;
}
int main()
{
   int C;
   char grid[MAX][MAX] = {0};
   bool checked[MAX][MAX] = {false};
   memset(checked, false, sizeof(checked));

   char line[MAX]={0};
//   scanf("%d\n", &C);
   fgets(line, MAX, stdin);
   sscanf(line, "%d", &C);
   fgets(line, MAX, stdin);
   for(int z = 0; z < C; z++)
   {
        int nc=0, nr=0;
	memset(grid, 0, sizeof(grid));
	while(fgets(line, MAX, stdin) && strlen(line) > 1)
	//while(gets(line) && strlen(line) > 1)
	{
	  if(line[0] == 'L' || line[0] == 'W')
	    strcpy(grid[nr++], line);
	  else //if( strlen(line)>1 )
	  {
	    int ir, ic;
	    nc = strlen(grid[0]);
	    //read nr nc
	    memset(checked, false, sizeof(checked));
	    sscanf(line, "%d %d", &ir, &ic);
	    printf("%d\n",dfs(ir-1, ic-1, grid, checked,  nr, nc) );
	  }
	}
	if( z < C-1) printf("\n");
   }
   return 0;
}

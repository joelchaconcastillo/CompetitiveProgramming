#include <bits/stdc++.h>
#define MAXSIZE 1001
#define BOMB -1
#define MAXVAL 1000000
using namespace std;

int grid[MAXSIZE][MAXSIZE];
int walk_r[] = {-1, 0, 1, 0};
int walk_c[] = {0, 1, 0, -1};

int main()
{
  int R, C;
  while( true )
  {
    scanf("%d %d\n", &R, &C);
     if(R == 0 && C == 0) break;
//     memset(grid, INT_MAX, sizeof grid); ///..¿?...
     fill_n(*grid, sizeof grid / sizeof **grid, MAXVAL);
     int bomb_rows;
     scanf("%d\n", &bomb_rows);
     for(int i = 0; i < bomb_rows; i++)
     {
       int r, nc;
       scanf("%d %d\n", &r, &nc); 
       for(int j = 0; j < nc; j++)
       {
           int c;
	   scanf("%d ", &c);
	   grid[r][c] = BOMB;
       }
     }
     int sr, sc, er, ec;
     scanf("%d %d\n", &sr, &sc);
     scanf("%d %d\n", &er, &ec);
     queue<pair<int, int> > q;
     grid[sr][sc]=0;
     q.push(make_pair(sr, sc));
     while(!q.empty())
     {
	pair<int, int> cell = q.front();
	q.pop();
	if( cell.first == er && cell.second == ec) break;
        for(int i = 0; i < 4; i++)
        {
	   int next_r = cell.first+walk_r[i];
	   int next_c = cell.second+walk_c[i];
	   if(next_r < 0 || next_r >= R ) continue;
	   if(next_c < 0 || next_c >= C ) continue;
	   if( grid[next_r][next_c] == BOMB) continue; 
	   if( grid[next_r][next_c] > grid[cell.first][cell.second]+1)
	   {
	      grid[next_r][next_c] = grid[cell.first][cell.second]+1;
	      q.push(make_pair(next_r, next_c));
  	   }
        }
     }
    printf("%d\n", grid[er][ec]);
  }
  return 0;
}

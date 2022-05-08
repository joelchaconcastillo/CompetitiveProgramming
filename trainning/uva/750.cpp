#include <bits/stdc++.h>
using namespace std;

int ca, rb, counter;
//vector<int> row;
int row[8];
bool check(int r, int c)
{
   for(int ci = 0; ci < c; ci++)
	if( row[ci] == r  ||  (abs(ci-c) == abs(row[ci] - r) ) ) return false;
   return true;
}
void bk(int c)
{
   if(c == 8 && row[rb] == ca) //found!...
   {
     printf("%2d      %d", ++counter, row[0]+1);
     for(int i = 1; i < 8; i++)
     {
	  printf(" %d", row[i]+1);
     }
     printf("\n");
     return;
   }
   for(int i = 0; i < 8 ; i++)
   {
	if( check(i, c))
	{
	   row[c] = i;
	   bk(c+1);
	}
   }
}

int main()
{
      int N;
      scanf("%d\n", &N);
      for(int k = 0; k < N; k++)
      {
	      if( k >0) printf("\n");
	      counter = 0;
//	     row.resize(8, 0);
        memset(row, 0, sizeof row);
	scanf("%d %d\n", &ca, &rb);
	rb--; ca--;
	printf("SOLN       COLUMN\n");
	printf(" #      1 2 3 4 5 6 7 8\n\n");
	bk(0);

      }
}

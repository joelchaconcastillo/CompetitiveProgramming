#include <bits/stdc++.h>
#define MAX_N 2000
#define MAX_H 2000

using namespace std;
 int main()
{
  int n, h, l,r;
  cin>>n>>h>>l>>r;
  int d[MAX_N], tab[2*MAX_H];
  memset(tab, -1, sizeof tab);
  for(int i = 0; i <n; i++)
    cin>>d[i];
   tab[d[0]]   = ( d[0] >=l && d[0] <=r)?1:0;
   tab[d[0]-1] = ( d[0]-1 >=l && d[0]-1 <=r)?1:0;
  int maxv = -1;
  for(int i = 1; i < n; i++)
  {
    int row = (i%2)*h, prow = ((i+1)%2)*h;
    for(int j = 0; j < h; j++)
    {
	int prev = tab[prow + j ];
	if( prev !=-1)
	{
	  int c1 = (j+d[i])%h, c2 = (j+d[i]-1)%h;
	  if(c1 >=l && c1 <=r)
          tab[row+c1] = max(tab[row+c1], prev+1);
          else 
          tab[row+c1] = max(tab[row + c1], prev);
	  if(c2 >=l && c2 <=r)
          tab[row + c2] = max(tab[row + c2], prev+1);
	  else
          tab[row + c2] = max(tab[row + c2], prev);
	}
    }
    for(int j = 0; j < h; j++) tab[prow + j] = -1;
  }
  for(int  i =0; i < h; i++) maxv = max(maxv, tab[((n-1)%2)*h+i]);
	cout << maxv<<endl;
  return 0;
}

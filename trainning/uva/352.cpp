#include <bits/stdc++.h>
#define MAX_D 26
using namespace std;
int adj[MAX_D*MAX_D];
int D;
int dr[]={1, 1, 1, 0, 0, -1, -1, -1};
int dc[]={-1, 0, 1, -1, 1, -1, 0, 1};
int dfs(int c, int r)
{
 if(c<0 || r<0 || c>=D || r>=D) return 0;
 if(adj[r*D +c] == 0) return 0;
 adj[r*D+c]=0;
 int cont = 1;
 for(int i = 0; i < 8; i++)
  cont +=  dfs(c+dc[i], r+dr[i]);
 return cont;
}
int main()
{
  int ite=1;
  while(cin >> D)
  {
	
     for(int i = 0; i < D; i++)
     {
        for(int j = 0; j < D; j++)
	{
	  char d;
           cin >>d;
	   adj[i*D+j] = d-'0';
	}
     }
     int nc=0;
     for(int i = 0; i < D; i++)
     {
        for(int j = 0; j < D; j++)
	   if( dfs(i, j) > 0) nc++;
     }
    cout << "Image number "<<ite++<< " contains "<<nc<<" war eagles."<<endl; 
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int M,N;
int r[]={-1, 0, 1, 0}, c[]={0, -1, 0, 1};
vector<string> maps;
int size=0;
char land;
void bk(int i, int j)
{
  size++;
  maps[i][j]='.';
  for(int idx=0; idx<4; idx++)
  {
     int nexti=r[idx]+i, nextj=c[idx]+j;
     nextj = (nextj+N)%N; 
     if(nexti<0 || nexti>=M)continue;
//     nextj = (nextj+N)%N; 
     if(maps[nexti][nextj]!=land)continue;
     bk(nexti, nextj);
  }
}
int main()
{
  while(cin >>M>>N)
  {
     maps.resize(M, string(N,' '));
     for(auto &i:maps)cin>>i;
     int si,sj, ms=0;
     cin>>si>>sj;
     land = maps[si][sj];
     bk(si, sj);
     for(int i = 0; i < M; i++)
     {
        for(int j = 0; j < N; j++)
	{
	  if(maps[i][j] == land)
	  {
	      size=0;
	      bk(i, j);
	      ms = max(ms, size);
	  }
	}
     }
     cout << ms<<endl;
  }
  return 0;
}

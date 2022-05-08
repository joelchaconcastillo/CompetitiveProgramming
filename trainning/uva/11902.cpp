#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
int mat[MAX_N*MAX_N], visited[MAX_N], dominated[MAX_N*MAX_N], visited2[MAX_N];
int N;
void dfs(int c, int target)
{
   visited[c]=1;
   if(c == target) return;
   for(int i = 0; i < N; i++)
   {
      if(visited[i]==1)continue;
      if(mat[c*N+i]==0) continue;
      dfs(i, target);  
   }
}
int main()
{
  int T, it=1;
  cin >> T;
  while(T--)
  {
     memset(dominated, 0, sizeof dominated);
     cin >> N;
     for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++) 
	   cin >> mat[i*N+j];
    memset(visited, 0, sizeof visited);
    dfs(0,-1);
   
    for(int k = 0; k < N; k++) visited2[k]=visited[k];
    for(int k = 0; k < N; k++)
    {
       memset(visited, 0, sizeof visited);
       dfs(0, k);
    for(int i = 0; i < N; i++)
	{
	 if(k == i && visited[k]==1) dominated[k*N+k]=1;
	 if(visited[i]==0 && visited2[i]==1 ) dominated[k*N+i]=1;
	}
    } 
    cout << "Case "<<it++<<":\n";
    for(int i = 0 ; i < N; i++)
    {
	cout<<"+";
        for(int j = 0; j < 2*N-1; j++)
	cout<<"-";
	cout<<"+";
	cout<<"\n|";
        for(int j = 0; j < N; j++)
	{
	   if(dominated[i*N+j]==1) cout << "Y|";
	   else cout << "N|";
	}
	cout << endl;
    }	cout<<"+";
        for(int j = 0; j < 2*N-1; j++)
	cout<<"-";
	cout<<"+";
	cout<<"\n";

  }
  return 0;
}

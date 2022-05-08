#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >>t;
  while(t--)
  {
     int n, m, x, y;
     cin >>n >>m>>x>>y;
     vector<string> g(n, "");
     int totalsum= 0;
     for(int i = 0; i < n; i++)
     {
	cin >> g[i];
        for(int j = 0; j < m; j++)
	{
	   if(g[i][j]=='*')continue;
           if( j < m-1 && 2*x>y && g[i][j]=='.' && g[i][j+1]=='.')
		totalsum += y, g[i][j] = g[i][j+1]='*';
	   else if(g[i][j]=='.') totalsum +=x, g[i][j]='*';
	}
     }
     cout << totalsum<<endl;
  }
  return 0;
}

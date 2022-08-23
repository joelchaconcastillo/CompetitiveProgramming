#include <bits/stdc++.h>
using namespace std;
int n,m;
int f(int i, int j){ return (i%2+j%2)%2;}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    cin >> n >> m;
    pair<int,int> s(-1,-1);
    vector<vector<char> > g(n, vector<char>(m));
    for(int i = 0; i < n; i++)
    {
	for(int j = 0; j < m; j++)
	{
	    cin >> g[i][j];
            if( g[i][j] != '.' && s.first ==-1 && s.second==-1) s=make_pair(i, j);
	}
    }
//    if(s.first==-1 && s.second==-1){cout << "NO\n"; continue;}
    if(s.first==-1 && s.second==-1) s = make_pair(0,0);
    char opt[]={'R','W'};
    if(opt[f(s.first, s.second)] != g[s.first][s.second]) swap(*opt, *(opt+1));
    bool check=true;
    for(int i = 0; i < n; i++)
    {
	for(int j = 0; j < m; j++)
	{
	   if(g[i][j]=='.' )g[i][j]=opt[f(i,j)];
	   else
	      if( g[i][j] != opt[f(i,j)]) check=0;
	   if(!check)break;
	}
	   if(!check)break;
    }
    if(!check){cout<< "NO\n"; continue;}
    cout << "YES\n";
    for(int i = 0; i < n; i++)
    {
	for(int j = 0; j < m; j++)
	{
	   cout <<opt[f(i,j)];
	}
	cout << endl;
    }

  }
}

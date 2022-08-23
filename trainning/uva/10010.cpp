#include <bits/stdc++.h>
using namespace std;
string s;
int l;
vector<string> g;
int i, j, n, m;
bool check(int dr, int dc)
{
   int c = j, r = i, idx = 0;
   while( c < n && r < m && c>=0 && r>=0 && idx < l && g[r][c] == s[idx] ) r +=dr, c+=dc, idx++;
   return (idx == l);
}
void dfs()
{
    l = s.size();
    for(i = 0; i < m; i++)
    {
 
      for(j = 0; j < n; j++)
      {
	if(check(0, 1)) return;
	if(check(0, -1)) return;
	if(check(1, 0)) return;
	if(check(-1, 0)) return;
	if(check(1, 1)) return;
	if(check(-1, -1)) return;
	if(check(1, -1)) return;
	if(check(-1, 1)) return;
      }
    }
}
int main()
{
  int T, C;
  cin>>T;
  while(T--)
  {
     cin >> m >>n;
     g = vector<string>(m);
     for(int i =0 ; i < m; i++)
     {
	cin >> g[i];
	transform(g[i].begin(), g[i].end(), g[i].begin(), ::tolower);
     }
     cin >>C;
     while(C--)
     {
       cin >>s; 
       transform(s.begin(), s.end(), s.begin(), ::tolower);
       dfs();
       cout << i+1 << " "<<j+1<<endl;
     }
     if(T)cout << endl;
  }
  return 0;
}

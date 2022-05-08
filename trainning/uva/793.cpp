#include <bits/stdc++.h>
using namespace std;
vector<int> p, r;
int nc;
void init()
{
   p.assign(nc,0);
   r.assign(nc,0);
   for(int i = 0; i < nc; i++)p[i] = i;
}
int find(int i)
{
   if( p[i] == i) return i;
   return (p[i] = find(p[i]));
}
bool Issame(int i, int j)
{
   return find(i) == find(j);
}
void connect(int i, int j)
{
 if(!Issame(i,j))
 {
    int x = find(i), y = find(j);
    if( r[x] > r[y] )
    {
       p[y] = x;
    }
    else
    { 
       p[x] = y;
       if( r[x] == r[y]) r[y]++;
    } 
 }
}
int main()
{
  int n;
  string st;
  cin >> n;
  getline(cin, st);
  getline(cin, st);
  
  while(n--)
  {
     int cont_s = 0, cont_u = 0;
     cin >>nc;
     init();
     getline(cin, st);
    while(getline(cin, st))
    {
      if(st.empty())break;
      istringstream tmp(st);
      char op;
      int i, j;
      tmp >> op >>i >>j;
      i--; j--;
      if( op == 'q')
      {
	if(Issame(i,j))
	  cont_s++;
	else cont_u++;
      }
      else if( op == 'c' )
      {
        connect(i, j);
      }
    }
    cout << cont_s << "," <<cont_u<<"\n"; 
    if(n>0) cout <<"\n";
  }
  return 0;
}

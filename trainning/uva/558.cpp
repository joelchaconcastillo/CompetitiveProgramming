#include <bits/stdc++.h>
#define MAX_N 1000

using namespace std;
int d[MAX_N];
int main()
{
  int c;
  cin>>c;
  while(c--)
  {
    int n, m, a, b, t;
    cin>>n>>m;
    fill_n(d, n, 100000);
    vector<tuple<int, int, int> > la;
    for(int i = 0; i <m; i++)
    {
	cin >> a >> b>>t;
	la.push_back(make_tuple(a,b,t));
    }
    bool cy=false;
    //bellman ford
    for(int k= 0; k < n; k++)
    {
       for(auto item:la)
       {
	     int i, j, t;
             tie(i, j, t) = item;
	     if(k==n-1 && d[j] > (d[i]+t)) cy=true;
	     d[j] = min(d[j], d[i]+t);
       }
    }
    if(!cy || m==0) cout << "not possible\n";
    else cout << "possible\n";
  }
  return 0;
}

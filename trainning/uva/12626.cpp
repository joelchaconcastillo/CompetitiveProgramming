#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  int n;
  cin>>n;
  cin.ignore();
  map<char, int> l;
  l['M']=1;
  l['A']=3;
  l['R']=2;
  l['G']=1;
  l['I']=1;
  l['T']=1;

  for(int i = 0; i < n; i++)
  {
     map<char, int> f;
     getline(cin, s);
     for(auto a:s)  f[a]++;
     int minv = INT_MAX;
     for(auto c:l)
     {
        minv =min(minv, f[c.first]/c.second);
     }
     cout << minv<<endl;
  }
  return 0;
}

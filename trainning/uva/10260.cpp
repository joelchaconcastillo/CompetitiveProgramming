#include <bits/stdc++.h>
using namespace std;
int main()
{
  string in;
  int v[200];
  memset(v, 0, sizeof(v));
  v['B'] = v['F'] = v['P']=v['V']=1;
  v['C'] = v['G'] = v['J']=v['K']=v['Q']=v['S']=v['X']=v['Z']=2;
  v['D'] = v['T'] = 3;
  v['L'] = 4;
  v['M'] = v['N'] = 5;
  v['R'] = 6;
  while(cin >> in)
  {
    int prev = -1;
    string out ="";
    for(auto i :in)
    {
       if(v[i]==prev) continue;
       prev = v[i];
       if(v[i]==0) continue;
       out.push_back(v[i]+'0');
    }
    cout << out <<endl;
  }
  return 0;
}

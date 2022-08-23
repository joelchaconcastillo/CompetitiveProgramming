#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  string s;
  while(cin >>n >>s)
  {
     map<string, int> f;
     pair<int, string> maxv(-1, "");
     for(int i =0 ; i < s.size()-n+1; i++)
	 f[s.substr(i, n)]++, maxv=max(maxv, make_pair(f[s.substr(i, n)]++, s.substr(i, n)));
     cout << maxv.second<<endl;

  }
  return 0;
}

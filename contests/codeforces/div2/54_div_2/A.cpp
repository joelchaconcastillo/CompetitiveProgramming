#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s,h="hello";
  cin >> s;
  int j = 0;
  for(int i = 0; i < s.size() && j <h.size(); i++) if(j < h.size() && s[i] == h[j]) j++;
  if(j == h.size()) cout <<"YES\n"; else cout << "NO\n";
  return 0;
}

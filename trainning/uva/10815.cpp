#include <bits/stdc++.h>
using namespace std;
inline bool IsLowerCharacter(char c)
{
    return c >= 'a' && c <= 'z';
}
 int main()
{
  string st;
  set<string> s;
  string tmp;
  while(getline(cin, st))
  {
    for(auto i:st)
    {
	if(!isalpha(i) && !tmp.empty()) s.insert(tmp), tmp.clear();
	else if(isalpha(i)) tmp.push_back(tolower(i));
    }
    if( !tmp.empty()) s.insert(tmp);
    tmp.clear();
  }
  for(auto i:s) cout <<i<<endl;
}

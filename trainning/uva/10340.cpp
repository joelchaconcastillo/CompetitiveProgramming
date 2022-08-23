#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s, t;
  while(cin >> s >>t)
  {
   int i=0, j=0;  
   for(; j < t.size(); j++)
	if( s[i] == t[j]) i++;
   
   if(i == s.size()) cout << "Yes"<<endl;
   else cout << "No"<<endl;
  }
  return 0;
}

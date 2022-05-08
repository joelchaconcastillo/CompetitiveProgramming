#include <bits/stdc++.h>
using namespace std;
bool mod(string a, int b)
{
 int idx = 0, tmp = a[idx]-'0', r;
 string c ="";
 while( tmp < b ) tmp = tmp*10 + a[++idx]-'0';
 while( idx < a.size())
 {
   c += (tmp/b) + '0'; 
   r = tmp%b;
   tmp = (tmp%b)*10 + a[++idx]-'0';
 }
  return r;
}
int main()
{
  string s;
  while(getline(cin, s))
  {
     if(s.size() ==1 && s[0]=='0') break;
     if(mod(s, 11)==0) cout << s<< " is a multiple of 11.\n";
     else cout << s << " is not a multiple of 11.\n";
  }
  return 0;
}

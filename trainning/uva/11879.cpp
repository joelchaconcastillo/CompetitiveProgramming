#include <bits/stdc++.h>
using namespace std;
string subs(string up, string low)
{
  string rem="";
  if(up.size()<low.size()) up.swap(low);
  int maxs=max(up.size(), low.size());
  while(up.size()>low.size())low = "0"+low;
  int c = 0;
  for(int i = maxs-1 ; i>=0; i--)
  {
      int u = up[i]-'0',l=low[i]-'0'+c;
      if(u<l) u+=10, c=1;
      else c=0;
      rem = char(u-l+'0')+rem;
  }
  while( rem.empty() && rem.front()=='0')rem=rem.substr(1);
  return rem;
}
int main()
{
  string s;
  while(cin>>s)
  {
     if(s[0]=='0' && s.size()==1) break;
     while(s.size()>2)
     {
       int n = (s.back()-'0')*5;
       s.pop_back(); 
       s=subs(s, to_string(n)); 
     }
     int ss = stoi(s);
     if(ss%17==0)cout << 1<<endl;
     else cout << 0<<endl;
  }
  return 0;
}

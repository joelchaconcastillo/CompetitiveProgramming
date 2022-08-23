#include <bits/stdc++.h>
using namespace std;
string mod(string &a, string &b)
{
 return "";
}
string div(string &a,string &b)
{
  return "";
}
string gcd(string a, string b){return (b.size()==1 && b[0] == '0')?a:gcd(b, mod(a, b));}
int main()
{
  int T;
  string st;
  cin >> T;
  getline(cin, st);
  while(T--)
  {
     string a="", b="";
     getline(cin, st);
     for(auto c:st){ if(c==' ') break; a +=c; }
     for(int i = a.size()+3; i < st.size(); i++)b +=st[i];
     string g = gcd(a, b);
     a = div(a, g), b = div(b, g);
     cout << a << " / "<<b<<endl;
  }
  return 0;
}

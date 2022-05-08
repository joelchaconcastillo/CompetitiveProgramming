#include <bits/stdc++.h>
using namespace std;
vector<string>words;
void bk(string st1, string st2, int n)
{
  if(st2.size()>5) return;
  if(n==st1.size())
  {
	words.push_back(st2);
	return;
  }
  bk(st1, st2+st1[n], n+1);
  bk(st1, st2, n+1);
}
bool cmp(string a, string b)
{
   if( a.size()<b.size())return true;
   else if(a.size()>b.size()) return false;
   else return (a<b);
}
int main()
{
  string all="";
  for(int i = 0; i < 26; i++) all +='a'+i;
  bk(all, "", 0);
  sort(words.begin(), words.end(), cmp);
  map<string, int> d;
  for(int i = 0; i < words.size(); i++) d[words[i]]=i;
  string in;
  while(getline(cin, in))
  {
      if(d.find(in) != d.end())
      cout << d[in]<<endl;
	else cout << 0<<endl;
  }
  return 0;
}
//vwxyz
//22, 23, 24, 25, 26
//83681

#include <bits/stdc++.h>
using namespace std;
int main()
{
  int it;
  cin>>it;
  while(it--)
  {
     string s;
     cin>>s;
     int zeros = s.rfind("00");
     int ones= s.find("11");
     if(zeros!=-1 && ones != -1 && zeros>ones)cout <<"NO\n";else cout <<"YES\n";
  }
  return 0;
}

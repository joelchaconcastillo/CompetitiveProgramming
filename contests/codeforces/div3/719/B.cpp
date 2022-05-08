#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     string s;
     cin>>s;
     int n = s.size();
     int f = s[0]-'0'-1;
     if( stoi(s) >= stoi(string(n, s[0])))f++;
     cout << 9*(n-1)+f<<endl;
  }
  return 0;
}

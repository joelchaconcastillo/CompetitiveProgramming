#include <bits/stdc++.h>
using namespace std;
int main()
{
  int ite;
  cin>>ite;
  while(ite--)
  {
     string st;
     cin>>st;
     int n = st.size();
      n = n*(n+1)/2;
     cout <<n+(st[0]-'0'-1)*10<<endl;
  }
  return 0;
}

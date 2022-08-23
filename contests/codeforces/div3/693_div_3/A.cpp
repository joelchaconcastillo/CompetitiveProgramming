#include <bits/stdc++.h>
using namespace std;
int main()
{
  int w, h, n, t;
  cin >> t;
  while(t--)
  {
     cin >> w >> h>> n;
     int c = 1;
     while( w%2==0)w/=2, c *=2;
     while( h%2==0)h/=2, c *=2;
     if(c>=n) cout << "YES"<<endl;else cout <<"NO"<<endl;
  }
  return 0;
}

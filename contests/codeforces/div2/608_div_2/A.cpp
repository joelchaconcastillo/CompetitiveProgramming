#include <bits/stdc++.h>

using namespace std;
int main()
{
  int a, b, c, d, e, f, maxv = 0;
  cin >> a >> b >>c >>d >>e >>f;
  if( e >= f)
  {
     int p1 = min(d, a);
     d -=p1;   
     int p2 = min( d, min(b,c));
     cout << p1*e + p2*f<<endl;
  }
  else
  {

     int p1 = min( d, min(b,c));
     d -=p1;   
     int p2 = min(d, a);
     cout << p1*f + p2*e<<endl;

  }
  
  return 0;
}

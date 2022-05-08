#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
   int x, y, n, k;
   cin >> x >> y >> n;
   int z = n%x;
   if( z>=y)
   {
      k = n - z + y;
   }
   else
     k = n - x + y - z;
   cout << k <<endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
//  if( fabs(((int) sqrt(n)) - sqrt(n)) == 0)
//	cout << (int)4*sqrt(n) <<endl;
//  else
  {
     int minp = 1e6;
     for(int a = 1; a <= 1e6; a++)
     {
        int b = n/a;
  	if( a*b != n ) continue;
        minp = min(minp, 2*a + 2*b);
     }
     cout << minp<<endl;
  }
  return 0;
}

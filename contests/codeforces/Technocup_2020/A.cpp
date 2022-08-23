#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >>n;
  while(n--)
  {
   int q;
   cin >> q; 
   if( q <=4) cout << 4-q<<endl;
   else cout << q%2<<endl;
  }
  return 0;
}

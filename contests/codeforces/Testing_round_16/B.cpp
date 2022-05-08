#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t, a1, b1, a2, b2;
  cin >> t;
  while(t--)
  {
   cin >> a1 >> b1;
   cin >> a2 >>b2;
   if( ((a1 + a2) ==  2*(b1+b2) && a1==a2 )
    || ((a1 + b2) ==  2*(b1+a2) && a1==b2 )
    || ((b1 + a2) ==  2*(a1+b2) && b1==a2)
    || ((b1 + b2) ==  2*(a1+a2) && b1==b2)
     )
    cout << "Yes\n";
   else cout << "No\n";
  }
   return 0;
}

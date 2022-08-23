#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int a,b,c, n=0;
    cin >> a >> b >> c;
    int a1 = min(a, b/2), a2 = min(b, c/2);
    int b1 = min(b-2*a1,c/2), b2 = min(a, (b-a2)/2);
    cout << max(a1+2*a1+b1+2*b1, a2+2*a2+b2+2*b2)<<endl;
  }
  return 0;
}

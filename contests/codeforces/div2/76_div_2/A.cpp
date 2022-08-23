#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n, x, a, b;
    cin >> n >> x >> a >> b;
    if( a > b) swap(a,b);
    int span = a-1 + n-b;
    cout << b-a + min(span, x)<<endl; 
  }
  return 0;
}

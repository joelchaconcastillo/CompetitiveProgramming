#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int x, y, n;
    cin>>x>>y>>n;
    int mod = x%n, r=1;
    for(int i = 0; i < y; i++) r*=mod, r%=n, cout << i<<endl;
    cout << (r%n)<<endl;
  }
  int zero;
  cin >> zero;
  return 0;
}

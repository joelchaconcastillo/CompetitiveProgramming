#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long k,n;
  cin >> n >>k;
  long long neven  = n/2, nodd=n-neven;
  if( k <= nodd) cout << 2*k-1<<endl;
  else cout <<2*(k-nodd) <<endl;
  return 0;
}

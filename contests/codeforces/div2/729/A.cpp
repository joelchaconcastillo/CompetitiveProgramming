#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >>t;
  while(t--)
  {
    int n, even=0, odds=0;
    cin >> n;
    for(int i = 0; i <2*n ; i++)
    {
	int d;
	cin >>d;
        if(d%2)odds++;
	else even++;
    }
    if(odds == even) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}

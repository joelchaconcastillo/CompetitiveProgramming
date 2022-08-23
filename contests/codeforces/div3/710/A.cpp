#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
     long long n, m,x;
     cin>>n>>m>>x;
     x--;
     long long r=x%n, c=x/n;
     cout << r*m+c+1<<endl;
  }
  return 0;
}

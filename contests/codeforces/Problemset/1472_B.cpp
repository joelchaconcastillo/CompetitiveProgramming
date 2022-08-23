#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     long long n, k, acum=0, newp=0, pi;
     cin>>n>>k;
     cin>>pi;
     acum =pi;
     for(int i = 1; i < n; i++)
     {
	cin>>pi;
	newp += max(0LL, (pi*100L-k*(acum+newp)+k-1)/k  );
	acum +=pi;
     }
     cout << newp <<endl;
  }
  return 0;
}

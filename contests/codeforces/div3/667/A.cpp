#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long a,b, t;
  cin>>t;
  while(t--)
  {
     cin>>a>>b;
     long long diff = labs(a-b);
     cout << diff/10 + (diff%10>0)<<endl;
  }
  return 0;
}

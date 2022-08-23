#include <bits/stdc++.h>
using namespace std;
long long fac(long long f)
{
  long long ff=1;
  for(long long i = 1 ; i <=f; i++) ff*=i;
  return ff;
}
int main()
{
 int n;
 cin>>n;
 cout << fac(n-1)*2/n<<endl; 
 return 0;
}

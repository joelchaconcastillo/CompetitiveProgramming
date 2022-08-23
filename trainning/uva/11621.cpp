#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long m;
  while(cin >>m, m!=0)
  {
     long t2=m, t3=m;
     while(t2%2==0) t2/=2;
     while(t3%3==0) t3/=3;
     if(t2==1){cout <<m<<endl;continue;}
     if(t3==1){cout <<m<<endl;continue;}
     long minv=2LL*INT_MAX;
     for(long pow2 = 1; pow2<=2LL*m; pow2*=2)
     {
	if(pow2>=m) minv=min(minv, pow2);
	for(long pow3 = 3*pow2; pow3<=2LL*m; pow3*=3)
	if(pow3>=m)minv=min(minv, pow3);
     }
     cout <<minv<<endl;
  }
  return 0;
}

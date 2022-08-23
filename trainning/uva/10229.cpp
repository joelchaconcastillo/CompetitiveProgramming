#include <bits/stdc++.h>
using namespace std;
//int mx=214748364;
int mx=4e8;
void fib(vector<long long> &sizef)
{
    sizef[0]=1;
    for(long long i =1; i<=20; i++)
        sizef[i] = (1<<(i-1))*3;
}
int main()
{
   vector<long long>sizef(21);
   fib(sizef);
  long long n, m;
  while(cin>>n>>m)
  {
      if( n >= sizef[m]) n = n%sizef[m];
	m = (1<<m);
      long long f1=0, f2=1, t;
	for(int i = 0; i < n; i++)
	   t = f2, f2=((f1%m)+(f2%m))%m, f1=t;
	cout << f1<<endl;
  }
  return 0;
}

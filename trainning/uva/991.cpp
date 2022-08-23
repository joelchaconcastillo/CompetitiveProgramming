#include <bits/stdc++.h>
#define N 23
using namespace std;
long long fac[N];
int cat(int n)
{
  fac[0]=1;
  for(long i = 1; i <= N; i++) fac[i] =i*fac[i-1];
  return (fac[2*n])/(fac[n]*fac[n]*(n+1));
}
int main()
{
  int n, i=0;
  int cata[] = {1,1,2,5,14,42,132,429,1430,4862,16796};
  
  while(cin >> n)
  {
     if(i>0) cout <<endl;
     cout << cata[n]<<endl;
	i++;
  }
  return 0;
}

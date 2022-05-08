#include <bits/stdc++.h>
using namespace std;
long long fac(long long int N, long long int M)
{
  long long int a=M, b = N-M;
  if( a<b) swap(a,b);
  long long f1=1, f2=1;
  for(long long i = 1; i <=b; i++)
    f2 *=i;
  long a1 = 0; 
  for(long long i = a+1; i <=N; i++)
  {
    f1 *=i;
    a1 *=i;
    if( f1/f2 > 0){ a1 += f1/f2; f1 %=f2;}
  }
  return a1+f1;
}
int main()
{
  long long int N, M;
  while(cin >> N >> M)
  {
    if( N==0 && M==0) break;
    	cout << N<<" things taken " << M <<" at a time is "<< fac(N, M)<<" exactly."<<endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
long long inv_fac(long long f, int m)
{
  int pow =1;
  while(m)
  {
    if( m%2==0) f = (f*f)%mod, m/=2;
    else pow = (pow*f)%mod, m--;
  } 
  return pow;
}
long long comb(int n, int k)
{
  if(n==k)return 1;
  long long fN = 1, fNK, fK; 
  for(long long i = 1; i <=n; i++)
  {
      fN =(fN*i)%mod;
      if(i==k) fK = fN;
      if( i== (n-k)) fNK=fN;
  }
  return fN*inv_fac(fK, mod-2)%mod*inv_fac(fNK, mod-2)%mod;
}
int main()
{
  int t, d[1000], freq[1001];
  cin>>t;
  while(t--)
  {
    int n, k;
   cin>>n >>k;
   memset(freq, 0, sizeof(freq));
   for(int i = 0; i < n; i++) cin >> d[i], freq[d[i]]++; 
    sort(d, d+n);
    int minv = d[n-k];
    int repin = 0, i = n-k;
    while(minv == d[i])i++, repin++;
    cout << comb(freq[minv], repin)<<endl;
  }
  return 0;
}

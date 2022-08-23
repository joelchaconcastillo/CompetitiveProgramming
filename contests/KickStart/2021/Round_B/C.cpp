#include <bits/stdc++.h>
#define N 10000
using namespace std;
vector<long long>primes, pr_primes;
bitset<10000000010> bs;
void fill_primes()
{
   bs.set();	
   bs[0]=bs[1]=0;
   for(int i = 2; i < N; i++)
   {
      if(!bs[i]) continue;
      for(int j = i*i; j < N; j+=i) bs[j] = 0;
      primes.push_back(i);
   }
   for(int i = 0; i < primes.size()-1; i++)
	   pr_primes.push_back(primes[i]*primes[i+1]);
}
int main()
{
  int T;
  cin>>T;
  fill_primes();
  for(int t = 1; t <=T; t++)
  {
     long long Z;
     cin >>Z;
     int i = pr_primes.size()-1;
     for(; i>=0; i--)
	if( pr_primes[i] <= Z )break;
     cout << "Case #"<<t<<": "<<pr_primes[i]<<endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
bitset<1000001> sieve;
void init_sieve(long long MAXL)
{
//  sieve.set();
  sieve[0]=sieve[1]=1;
  for(long long i = 2;i <= MAXL;i++)
  {
     if(sieve[i]) continue;
     for(long long  j = i*i; j <= MAXL; j +=i)
	sieve[j] = 1;
     primes.push_back(i);
  }
}
int main()
{
  init_sieve(1000000L);
  int n;
  while(cin>>n)
  {
	if(n==0) break;
     int a=-1, b=-1;
     for(int i = 0; primes[i]<n; i++)
	if(sieve[n-primes[i]]){ a= primes[i], b=n-primes[i]; break;}
     if(a==-1) cout << "Goldbach's conjecture is wrong."<<endl;
     else cout << n << " = "<<a<< " + "<<b<<endl;
  
  }
  return 0;
}

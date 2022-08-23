#include <bits/stdc++.h>
using namespace std;
bitset<10000000> b;
vector<long long> pri;
long long z, maxN=1e6;
void sieve()
{
  b.set();
  b[0]=b[1]=0;
  for(long long i = 2; i <= maxN; i++)
  {
     if(!b[i])continue;
     for(long long j = i*i; j <= maxN ; j+=i) b[j]=0;
     pri.push_back(i);
  }
}
bool isprime(long long test)
{
  if( test <= maxN) return (b[test]);
  for(auto idx:pri)
  {
	  if( idx*idx > test)return true;
	  if( test%idx == 0) return false;
  }
  return true;
}
int main()
{
  int ite;
  sieve();
  cin>> ite; 
  for(int t = 1; t <=ite;t++)
  {
     cin>>z;
     long long p1 = sqrt(z), p2=sqrt(z)+1;
     while( !isprime(p1))p1--;
     while( !isprime(p2))p2++;

     if( p1*p2 <=z)
     cout <<"Case #"<<t<<": "<<p1*p2<<endl;
     else{
	long long p0 = p1-1;
       while( !isprime(p0))p0--;
     cout <<"Case #"<<t<<": "<<p1*p0<<endl;
     }
  }
  return 0;
}

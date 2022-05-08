#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
vector<long long> p, f;

bitset<MAX_N+1> b;
void init_sieve()
{
  b.set();
  b[0] = b[1] = 0;
  for(long long i = 2; i <= MAX_N; i++)
  {
     if(!b[i])continue;
     for(long long j = i*i; j <= MAX_N; j+=i) b[j]=0;
     p.push_back(i);
  }
  p.push_back((1<<31)-1);
}
void pf(long long int n)
{
  f.clear();
  if(n<0) f.push_back(-1), n = -n;
  int idx = 0, d = p[idx];
  while(p[idx] < n)
  {
     while((n % p[idx]) == 0){  n /=p[idx]; f.push_back(p[idx]);}
     idx++;
  }
  if(n!=1) f.push_back(n); 
}
int main()
{
  init_sieve();
  long long int n;
  while(cin >> n)
  {
     if(n==0) break;
     pf(n);
     cout << n<<" = ";
     for(int i = 0; i  < f.size()-1; i++)
	cout << f[i]<< " x ";
     cout << f[f.size()-1]<<endl;
  }
  return 0;
}

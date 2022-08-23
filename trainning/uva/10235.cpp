#include <bits/stdc++.h>
using namespace std;
bool isprime(int N)
{
  for(int i=2; i<=  sqrt(N);i++)
	if( N%i==0) return false;
  return true;
}
int main()
{
  string N, revN;
  while(cin >> N)
  {
     int N1=0, N2=0;
     for(int i = 0; i < N.size(); i++)
     {
	N1 = (N1*10)+N[i]-'0';
	N2 = (N2*10)+N[N.size()-1-i]-'0';
     }
     bool flag1=isprime(N1), flag2=isprime(N2);
     if(flag1 && flag2 && N1!=N2) cout <<N1<<" is emirp."<<endl;
     else if(flag1) cout << N1 << " is prime."<<endl;
     else if(!flag1) cout << N1<< " is not prime."<<endl;
  }
  return 0;
}

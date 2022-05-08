#include <bits/stdc++.h>
using namespace std;
long long fm(long long a, long long b, long long k){ 
        long long cont = 0;
	while( a > 0)a /=(b+k), cont++;
	return cont+k;
}
int main()
{
  int t;
long long a,b, c;
  cin>>t;
  while(t--)
  {
    cin >> a>> b;
    int k = 0; 
    if(b==1) k++;
    long long current= fm(a,b,k), next=fm(a,b,k+1);
    while( current >= next ) current= fm(a,b,k), next=fm(a,b,k+1), k++;
    cout <<current <<endl;
  }
  return 0;
}

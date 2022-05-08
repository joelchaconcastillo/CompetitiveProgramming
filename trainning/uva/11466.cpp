#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  while(cin>>n)
  {
     if(n==0) break;
	if(n<0)n*=-1;
     long long lastp=-1, cont=0, n2=n;

     for(long long i=2; i*i<=n; i++)
     {
	if(n==1)break;
 	if(n%i==0)
	{
	while(n%i==0) n/=i;
	lastp=i;
	cont++;
	}
     } 
     if(n!=1)cont++, lastp=n;
     if(cont>1) cout <<lastp<<endl;
     else cout <<-1<<endl;
  }
  return 0;
}

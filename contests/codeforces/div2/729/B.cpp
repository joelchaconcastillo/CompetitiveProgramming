#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  long long n, a, b;
  cin >>t;
  while(t--)
  {
     cin >>n >>a >>b;
//     if(n%b==1){cout << "Yes\n"; continue;}
     if(a==1)
     {
	if(n%b==1 || b==1)cout << "Yes\n";
	else cout <<"No\n";
	continue;
     }
// && n%b==1){cout<<"Yes\n";continue;}
//     if(a==1 && n%b!=0){cout<<"No\n";continue;}
//     bool f= dp(n);
     bool f = 0;
     for(long long i = 1; i <= n; i*=a)
     {
	long long num = n-i;
	if(num %b ==0){ f=1;break;}
     }
     if(f)cout << "Yes\n";
     else cout << "No\n";
  }
  return 0;
}

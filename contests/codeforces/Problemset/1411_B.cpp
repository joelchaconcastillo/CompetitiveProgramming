#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    long long n;
    cin>>n;
		
    while(true)
    { 
       bool f=1;
       long long cn=n;
       while(cn && f) if(cn%10!=0 && n%(cn%10) !=0) f=0; else cn/=10LL;
       if(f) break;
       n++;
    }
    cout << n<<endl;
    
  }
  return 0;
}

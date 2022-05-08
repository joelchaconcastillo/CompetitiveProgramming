#include <bits/stdc++.h>
using namespace std;
int n,m, d[10000];
bool cmp(int a, int b)
{
   if(a%m < b%m)return true;
   else if(a%m>b%m)return false;
   if(a%2!=0 && b%2==0) return true;
   else if(b%2!=0 && a%2==0) return false;
   else if(a%2!=0 && b%2!=0)return (a>b);
   else if(a%2==0 && b%2==0)return (a<b);
  return false;
}
int main()
{
  while(cin >> n >> m)
  {
//      if(n==0 && m == 0) break;
      for(int i = 0; i < n; i++) cin>>d[i];
     sort(d, d+n, cmp);
     cout << n<< " " <<m<<endl;
     for(int i = 0; i < n; i++)cout << d[i]<<endl;
  }
  return 0;
}

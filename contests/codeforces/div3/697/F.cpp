#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
int n;
bool m1[MAX_N*MAX_N], m2[MAX_N*MAX_N];
bool check()
{
   for(int i = 0; i < n; i++) //first check first rows and apply all operations by cols
     if(m1[i] != m2[i])
	for(int j = 0; j < n; j++)
	   m1[j*n+i] ^= 1;
   for(int i = 0; i <n; i++) //checking by first col
   {
      for(int j = 0; j< n; j++)
      {
        if(m1[i*n] !=m2[i*n] &&  (m1[i*n+j]^1) != m2[i*n+j] ) return false;  
      }
   }
   return true;
}
int main()
{
  int t;
  cin >>t;
  while(t--)
  {
     cin>>n;
     char c;
     for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >>c,  m1[i*n+j]=c-'0';
     for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >>c, m2[i*n+j]=c-'0';
    int a=2;
    bool f=false;
    while(a--)
    {
      f=check();
      if(!f)break;
      //force to check inside entries
      for(int i = 0; i < n; i++) m1[i] ^=1;
    }
      if(f) cout << "YES\n";
      else cout << "NO\n";
  } 
  return 0;
}

#include <bits/stdc++.h>
#define N_MAX 1010
using namespace std;
string s;
int mem[N_MAX*N_MAX];
int len(int l, int r)
{
   if( l==r) return 1;
   else if( l+1 == r)
      if(s[l] == s[r]) return 2;
      else return 1;
   if(mem[l*N_MAX + r] != -1)  return mem[l*N_MAX + r];
   if( s[l] == s[r] ) return mem[l*N_MAX + r] = 2 + len(l+1, r-1);
   return mem[l*N_MAX + r] = max(len(l+1, r), len(l, r-1));
}
using namespace std;
int main()
{
  int T;
  cin >> T;
  cin.ignore();
  while(T--)
  {
     getline(cin, s);
    //cin>>s;
     memset(mem, -1, sizeof mem);
     int l = s.size();
     if( l == 0)cout<<l<<endl;
     else
      cout <<len(0, l-1)<<endl; 
  }
  return 0;
}

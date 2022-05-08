#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
int idx[MAX_N];
char P[MAX_N];
//void kmp_init()
//{
//  int m = strlen(P), i = 0, j= -1;
//  idx[0] = -1;
//  while(i<m)
//  {
//     while(j >= 0  && P[i] != P[j]) j = idx[j];
//     i++;
//     j++;
//     idx[i] = j;
//  }
//}
//bool kmp()
//{
//
//}
int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    memset(idx, 0, sizeof idx);
    cin >>P; 
    //kmp_init();
    int m = strlen(P), i = 1;
   
    for(; i <= m ; i++) //length
    {
      if( m%i != 0) continue;
      bool f = true;
      for(int j = 0; j < m; j++)
	   if( P[j%i] != P[j] ) {f=false; break;}
      if(f) break;
    }
    cout << i <<endl;
    if( n >0) cout <<endl;
  }
  return 0;
}

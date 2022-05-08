#include <bits/stdc++.h>
using namespace std;
bool isq(long double d)
{
   long double d1=sqrt(d);
   return ( (d1-floor(d1))==0.0);
}
int main()
{
  int t;
  int d[51];
  cin>>t;
 while(t--)
 {
    memset(d, 0, sizeof d);
    int n;
    cin>>n;
    bool f =1;
    int id = 0;
    while(f)
    {
     f=0;
     for(int i = 0; i <n; i++)
     {
	if(d[i] == 0 || isq(d[i]+id+1) ){d[i]=id+1; f=1;id++; break;}
     } 
    }
    if(id == 0) cout << "-1"<<endl;
    else cout << id<<endl;
 }
  return 0;
}

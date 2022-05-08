#include <bits/stdc++.h>
using namespace std;
int main()
{
  int ite;
  int n, da[300000];
  cin >>ite;
  while(ite--)
  {
    cin>>n;
    int maxv=0;
    for(int i = 0; i < n; i++)
	cin>>da[i], maxv=max(maxv, da[i]);
    int i=0;
    for(; i < n; i++)
    {
	if(i>0 && da[i-1]!=maxv &&  da[i]==maxv)break;
	if(i < n-1 && da[i+1]!=maxv && da[i]==maxv)break;
    }
    if(i==n)cout << "-1\n";
    else cout << i+1<<endl;
  }
  return 0;
}

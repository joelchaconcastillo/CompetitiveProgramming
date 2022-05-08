#include <bits/stdc++.h>
using namespace std;
int main()
{
  int ite, d[200];
  cin>>ite;
  while(ite--)
  {
    int n,idx=0;
    cin >> n;
    for(int i = 0; i < n; i++) cin>>d[i];
    for(int i =1; i <n-1 && idx==0;i++)
    {
      if( d[i-1] != d[i] && d[i-1] != d[i+1])
	      idx =i-1;
      else if( d[i-1] != d[i] && d[i] != d[i+1])
	      idx =i;
      else if( d[i-1] != d[i+1] && d[i] != d[i+1])
	      idx =i+1;
    }
    cout << idx+1<<endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, a[1001];
  while(cin >> n, n!=0)
  {
     for(int i =0 ; i < n; i++)cin>>a[i];
     int start=0, end=n-1;
     while(start < n-1 && a[start]==0)start++;
     while(end >= 0 && a[end]==0)end--;
     if(end<start)cout <<0<<endl;
     else
     {
	if(end-start>=1)
	{
	  cout << a[start];
          for(int i =start+1; i <=end; i++)if(a[i]!=0)cout <<" "<<a[i];
	}
	else
	cout << a[start];
     cout <<endl;
     }

  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{

ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);

  int t;
  cin>>t;
  while(t--)
  {
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> a(n), ls(n,0);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    long long l1 = 0, r1=n-1,r2=n-1, s=0;
    while(l1<r1 || l1 < r2)
    {
	while(l1<r1+1 && a[l1]+a[r1]>r)r1--;
	while(l1<r2+1 && a[l1]+a[r2]>l-1)r2--;
	if(l1<r1)
	s+=(r1-l1);
	if(l1<r2)
	s-=(r2-l1);
	l1++;
    }
    cout <<s<<endl;
  }	  
  return 0;
}

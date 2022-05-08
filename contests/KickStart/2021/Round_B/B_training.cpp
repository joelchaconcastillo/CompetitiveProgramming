#include <bits/stdc++.h>
using namespace std;
int n;
int kmp(vector<int> &d)
{
//kind of Knuth Morris algorithm..
      int maxv = -1;
      for(int i = 0, j=0; i < n-1; i=j)
      {
  	while(j < n-1 && d[i]==d[j]) j++;
 	maxv = max(maxv, j-i+1);	
	if( j < n-1) maxv = max(maxv, j-i+2);
	if(j < n-2 && d[j]+d[j+1] == 2*d[i])
	{
	  int end = j+2;
	  while( end < n-1 && d[end] == d[i]) end++;
	  maxv = max(maxv, end-i+1);
	}
      }
    return maxv;
}
int main()
{
  int ite;
   cin >>ite;
   for(int t = 1; t<=ite; t++)
   {
      cin>>n;
      vector<int>A(n), d(n-1);
      for(int i = 0; i < n; i++) cin>>A[i];
      for(int i = 0; i < n-1; i++) d[i] = A[i+1]-A[i];
      int maxv = kmp(d); 
      reverse(d.begin(), d.end());
      maxv = max(maxv, kmp(d)); 
      cout << "Case #"<<t<<": "<<maxv<<endl;
   }

  return 0;
}

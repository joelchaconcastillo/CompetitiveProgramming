#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin>>T;
  for(int t = 1; t <= T; t++)
  {
     int n;
     cin>>n;
     
     vector<long long>d(n), D(n-1);
     for(int i = 0; i < n; i++)
	cin>>d[i];
     for(int i = 0; i < n-1; i++) D[i]=(fabs(d[i+1]-d[i]));
     for(int i = 0; i <D.size(); i++) cout << D[i]<< " ";
cout <<endl;
//     cout << "Case #"<<t<<": "<<maxv<<endl;
  }
  return 0;
}

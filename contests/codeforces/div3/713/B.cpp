#include <bits/stdc++.h>
using namespace std;

int main()
{
  int ite, n;
  cin>>ite;
  while(ite--)
  {
	  cin>>n;
    vector<pair<int, int>>point;
    for(int i = 0; i  < n; i++)
    {
      for(int j = 0; j <n; j++)
      {
	char c;
	cin>> c;
	if(c=='*') point.push_back(make_pair(i,j));
      }
    }	  
    int xl = min(point[0].first, point[1].first);
    int xu = max(point[0].first, point[1].first);
    int yl = min(point[0].second, point[1].second);
    int yu = max(point[0].second, point[1].second);

    if(xl==xu && xu < n-1) xu++;
    else if(xl==xu && xu == n-1) xu--;

    if(yl==yu && yu < n-1) yu++;
    else if(yl==yu && yu == n-1) yu--;

    for(int i = 0; i  < n; i++)
    {
      for(int j = 0; j <n; j++)
      {
	 if( i ==  xl && j == yl)cout << '*';
	 else if( i ==  xl && j == yu)cout << '*';
	 else if( i ==  xu && j == yl)cout << '*';
	 else if( i ==  xu && j == yu)cout << '*';
	 else cout <<'.';
      }
      cout << endl;
    }
  }
  return 0;
}

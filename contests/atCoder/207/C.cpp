#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin>>N;
  vector<pair<double, double>> pp;
  for(int i =0 ; i < N ; i++)
  {
     int t; double l, r;
     cin >>t>>l>>r;
     if(t == 2)r-=0.01;
     else if (t==3)l+=0.01;
     else if (t==4) l+=0.01, r-=0.01;
     pp.push_back({l, r});
  }
  sort(pp.begin(), pp.end());
  int cont = 0;
  for(int i = 0; i < N ; i++)
  {
     for(int j = i+1; j < N; j++)
     {
	     if( pp[i].first <= pp[j].first && pp[i].second >= pp[j].first) cont++;
	     else break;
     }
  }
  cout << cont<<endl;
  return 0;
}

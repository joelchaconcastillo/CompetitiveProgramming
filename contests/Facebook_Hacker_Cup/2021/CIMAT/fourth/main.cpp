#include <bits/stdc++.h>
using namespace std;
bool turnleft(pair<int, int> &a, pair<int,int>&b, pair<int,int> &p){
   pair<int,int>s1(b.first-a.first, b.second-a.second);
   pair<int,int>s2(p.first-b.first, p.second-b.second);
   int det= (s1.first*s2.second)-(s2.first*s1.second);
   return (det<0);
}
int main(){
  int T;
  cin >>T;
  vector<pair<int, int> > d(3);
  pair<int,int> point;
  for(int t = 1; t<=T; t++){
	  cin>>point.first>>point.second;
	  for(int i = 0; i < 3; i++)
	    cin>>d[i].first>>d[i].second;
	  sort(d.begin(), d.end());
	  int c=0;
	  c += turnleft(d[0], d[1], point);
	  c += turnleft(d[1], d[2], point);
	  c += turnleft(d[2], d[0], point);

    if(c==0 || c==3)cout<<"Case #"<<t<<": IN\n";
    else cout <<"Case #"<<t<<": OUT\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool cont(pair<double, double> &p, pair<double, double>&t1, pair<double, double> &b2)
{
  if(p.first <= t1.first || p.first >= b2.first) return false;
  if(p.second >= t1.second || p.second <= b2.second) return false;
  return true;
}
int main()
{
  char c;
  pair<double, double> RT[20], RB[20];
  int n=0;
  while( cin>> c && c=='r')
  {
     cin >> RT[n].first >> RT[n].second>>RB[n].first>>RB[n].second; 
     n++;
  }
  pair<double, double> p;
  int k=0;
  while(cin >> p.first >>p.second && (p.first!= 9999.9 && p.second != 9999.9))
  {
    bool f = false;
    for(int i = 0; i  <n;i++)
//    if( p.first > RT[i].first && p.second < RT[i].second && p.first < RB[i].first && p.first > RB[i].second){ 
      if(cont(p, RT[i], RB[i])){
	cout << "Point "<<k+1<<" is contained in figure "<<i+1<<"\n";
 f=true;}
    if(!f) cout << "Point "<< k+1<<" is not contained in any figure\n";
    k++;
  }
  return 0;
}

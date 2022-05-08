#include <bits/stdc++.h>
#define MAX_N 101
using namespace std;
pair<double, double> point[MAX_N];
bool checked[MAX_N];
int T, N;
double prim()
{
   double totalcost = 0.0;
   int cont =1;
   memset(checked, false, sizeof checked);
   priority_queue<pair<double, int>> pq;
   int current = 0;
   checked[current]=true;
   for(int i = 0; i < N; i++)
   {
	if(i == current) continue;
      pq.push(make_pair(-hypot( point[current].first-point[i].first, point[current].second-point[i].second), -i));
   }
  while(!pq.empty() && cont < N)
  {
      pair<double, int> a = pq.top(); pq.pop();
      if(checked[-a.second]) continue;
      checked[-a.second]=true;
      totalcost += (-a.first);
      current = -a.second;
      cont++;
      for(int i = 0; i < N; i++)
      {
	if(i == current && checked[i]) continue;
        pq.push(make_pair(-hypot( point[current].first-point[i].first, point[current].second-point[i].second), -i));
      }    
  }
  return totalcost;
}
int main()
{
  cin >> T; 
  while(T--)
  {
    cin >> N;
    for(int i = 0;i< N; i++)
	cin >> point[i].first >> point[i].second;
    printf("%.2lf\n", prim());
    if( T > 0) printf("\n");
     
  }
  return 0;
}

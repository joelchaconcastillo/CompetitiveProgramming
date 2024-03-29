#include <bits/stdc++.h>
#define MAX_N 100;
using namespace std;
vector<vector<double>> d, memo2d;
int n;
double dist(pair<double, double> &p1, pair<double, double> &p2){
   return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}
double dp2(int p1, int p2){
    int v = 1+max(p1,p2);
    if(v==n-1)return d[p1][v]+d[v][p2];
    auto &memo=memo2d[p1][p2];
    if(memo > -0.5)return memo;
   double LR=dp2(v,p2)+d[p1][v];
   double RL=dp2(p1,v)+d[v][p2];
   return memo = min(LR,RL);
}

int main(){
  
   while(cin>>n){
     vector<pair<double, double> > points(n);
     d.assign(n, vector<double> (n,0));     
     for(int i = 0; i < n; i++) cin>>points[i].first >> points[i].second;
     memo2d.assign(n, vector<double> (n, -DBL_MAX));
     for(int i = 0; i <n; i++)
	for(int j = 0; j < n; j++)
	      d[i][j] = d[j][i] = dist(points[i], points[j]);
     cout<<fixed;
     cout << setprecision(2)<<dp2(0, 0)<<endl;
   }
   return 0;
}

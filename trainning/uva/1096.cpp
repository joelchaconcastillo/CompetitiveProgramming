#include <bits/stdc++.h>
using namespace std;
vector<vector<double>> d;
vector<vector<vector<double>>>memo;

int n, b1, b2;
double dist(pair<double, double> &p1, pair<double, double> &p2){
   return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}
pair<double dp2(int p1, int p2, int I, vector<int> h){
    int v=max(p1, p2)+1;
    auto &m= memo[p1][p2][I];
    if(m>-0.5)return m;
    if(v+1==n){
	return m=(d[p1][n-1]+d[p2][n-1]);
    }
    if(v==b1 || v==b2){
	if(I==2){
	   auto v1=dp2(v, p2, 1)+d[p1][v];
	   auto v2=dp2(p1, v, 0)+d[p2][v];
	   if(v1<=v2) return m=v1;
	   else return m=v2;
	}
	else if(I==0) return m=(dp2(v, p2, 3) + d[p1][v]);
	else return m=( dp2(p1, v, 3)+d[v][p2]);
    }else{
	auto lr=dp2(v, p2, I)+d[p1][v];
	auto rl=dp2(p1, v, I)+d[p2][v];
	if(lr<=rl)return (m=lr);
	else return (m=rl);
    }
}
int main(){
   int T=1;     
   while(cin>>n>>b1>>b2){
	   if(n==0)break;
     vector<pair<double, double> > points(n);
     memo.assign(n, vector<vector<double> >(n, vector<double> (4,-DBL_MAX)));
     d.assign(n, vector<double> (n,0));     
     for(int i = 0; i < n; i++) cin>>points[i].first >> points[i].second;
     if(points[b1]>points[b2])swap(b1, b2);
     for(int i = 0; i <n; i++)
	for(int j = 0; j < n; j++)
	      d[i][j] = d[j][i] = dist(points[i], points[j]);
     cout <<"Case "<<T<<": ";
     auto opt=dp2(0,0, 2);
     cout<<opt<<endl;
//     sort(opt.second.begin(), opt.second.end());
//
//     vector<bool> marked(n, false);
//     for(auto i:opt.second) marked[i]=true;
////     for(int i=n-1; i >=0; i--)if(!marked[i])opt.second.push_back(i);
//     opt.second.push_back(0);
//     cout<<fixed;
//     cout << setprecision(2)<<opt.first<<endl;
//     for(int i=0; i < opt.second.size(); i++){
//	     cout<<opt.second[i];
//	     if(i+1<opt.second.size())cout<<" ";
//     }
//     cout<<endl;
     T++;
   }
   return 0;
}

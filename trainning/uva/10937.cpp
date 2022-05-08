#include <bits/stdc++.h>
using namespace std;
int row1[]={0,1,1,1,0,-1,-1,-1}, col1[]={-1,-1,0,1,1,1,0,-1};
int row2[]={0, -1, 0, 1}, col2[]={-1, 0, 1, 0};
int n, m, np;
vector<vector<int> > matrix_dist;
vector<int> bfs(pair<int, int> &pp, vector<pair<int ,int> >&points, vector<string> &g){
	queue<pair<int ,int> >q;
	vector<vector<int> > dists(n, vector<int> (m, INT_MAX));
	dists[pp.first][pp.second]=0;
	q.push(pp);
	while(!q.empty()){
            auto ii=q.front(); q.pop();
	    for(int k=0; k < 4; k++){
		int ni=ii.first+row2[k], nj=ii.second+col2[k];
		if(ni < 0 || ni >=n || nj < 0 || nj >=m)continue;
		if( dists[ni][nj]!=INT_MAX || g[ni][nj]=='#' || g[ni][nj]=='~'|| g[ni][nj]=='X' || g[ni][nj]=='*')continue;
		q.push({ni,nj});
		dists[ni][nj]=dists[ii.first][ii.second]+1;
	    }
	}
	vector<int> dists_p(points.size(),0);
	for(int i = 0; i < points.size(); i++){
		dists_p[i]=dists[points[i].first][points[i].second];
		if(dists_p[i]==INT_MAX)return{};
	}
	return dists_p;
}
unordered_map<int, unordered_map<int,int> >memo;
int tspdp(int city, int mask){
    if(mask==(1<<(np))-1){
	    return matrix_dist[city][0];
    }
    if(memo[city].find(mask)!=memo[city].end())return memo[city][mask];
    int minv=100000000;
    for(int i = 0; i < np; i++){
       if( !(mask&(1<<i)) &&  i!= city){
	minv = min(minv, matrix_dist[city][i]+tspdp(i, mask|(1<<i)));
       }
    }
    return memo[city][mask]=minv;
}
int tsp(){
   memo.clear();
   np=matrix_dist.size();
   return tspdp(0,1);
}
int main(){
   while(cin>>n>>m){
      if(n==0 && m==0)break;
      vector<string> g(n);
      for(int i = 0; i < n; i++)
      cin>>g[i];
      /////////////
      int cont=1;
      bool issol=true;
      vector<pair<int, int> > points;
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
	  if(g[i][j]=='!') g[i][j]= cont+'0', cont++, points.push_back({i, j});
	  else if(g[i][j]=='@') g[i][j]='0', points.push_back({i, j}), iter_swap(points.begin(), points.end()-1);
	  else if(g[i][j]=='*'){
             for(int ii=0; ii<8; ii++){
		int ni=i+row1[ii], nj=j+col1[ii];
		if(ni < 0 || ni >=n)continue;
		if(nj < 0 || nj >=m)continue;
		if(g[ni][nj]=='@' || g[ni][nj]=='!' || (g[ni][nj]>='0' && g[ni][nj]<='9'))issol=false;
		if(!issol)break;
		if(g[ni][nj]=='.') g[ni][nj]='~';
             } 
	    if(!issol)break;
	     g[i][j]=='*';
	   }
		if(!issol)break;
	}
		if(!issol)break;
      }
//      for(int i = 0; i < n; i++)cout<<g[i]<<endl;
	matrix_dist.assign(points.size(), vector<int>());
      for(int i = 0; i < points.size(); i++){
	      matrix_dist[i] = bfs(points[i], points, g);
	      if(matrix_dist[i].empty()){
		issol=false;
		break;
	      }
      }
      if(!issol){
	cout <<-1<<endl;
	continue;
      }
      int hrs = tsp();
      cout << hrs<<endl;
   }
   return 0;
}

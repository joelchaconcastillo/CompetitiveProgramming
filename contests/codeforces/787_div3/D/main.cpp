#include <bits/stdc++.h>
using namespace std;
vector<int>p;
vector<vector<int> > edges, paths;
void dfs(int node){
   for(int i = 0 ; i < edges[node].size(); i++){
       int next=edges[node][i];
       if(i>0)
          paths.push_back({next});
       else paths.back().push_back(next);
       dfs(next);
   }
}
int main(){
   int T;
   cin>>T;
   while(T--){
     int n;
     cin>>n;
     p.assign(n, -1);
     paths.clear();
     edges.assign(n, vector<int>());
     int root=0;
     for(int i = 0 ; i < n; i++){
	cin>>p[i];
	p[i]--;
	if(i==p[i])root=i;
	else
	edges[p[i]].push_back(i);
     }
     paths.push_back({root});
     dfs(root);
     cout<<paths.size()<<endl;
     for(int i = 0 ; i < paths.size(); i++){
	cout << paths[i].size() <<endl;
	for(int j=0; j < paths[i].size(); j++)
	   cout << paths[i][j]+1<<" ";
	cout<<endl;
     }
     cout<<endl;
   }
   return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int> > adjlist;
unordered_map<string, int> creatures;
int LARGEST=0, s=0;
void dfs(int node){
   visited[node]=true;
   s++;
   for(auto next:adjlist[node]){
     if(visited[next])continue;
     dfs(next);
   }
}
int main(){
   int C,R;
   while(cin>>C>>R){
	   if(C==0 && R==0)break;
       adjlist.assign(C, vector<int>()); 
       for(int i = 0; i < C; i++){
         string st;
         cin>>st;
	 creatures[st]=i;
       }
       for(int i = 0; i < R; i++){
    	string a,b;
    	cin>>a>>b;
    	adjlist[creatures[b]].push_back(creatures[a]);
    	adjlist[creatures[a]].push_back(creatures[b]);
       }
       LARGEST=0;
       for(int i = 0; i < C; i++){
            s=0;
	    visited.assign(C,0);
	    dfs(i);
	    LARGEST= max(LARGEST, s);
       }
       cout <<LARGEST<<endl;
   }
   return 0;
}

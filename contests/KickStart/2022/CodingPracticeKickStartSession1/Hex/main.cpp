#include <bits/stdc++.h>
using namespace std;
int rr[]={0, 1, 1, 0, -1, -1}, cc[]={-1, -1, 0, 1, 1, 0};
int N;
unordered_map<int, unordered_map<int, int> > adjList1, adjList2;
void augmented(int n, unordered_map<int, int> &p, unordered_map<int, unordered_map<int, int> > &adjList, int s){
   if(n==s)return;
   else if(p[n]!=-1){
     augmented(p[n], p, adjList, s);
     adjList[p[n]][n]=0;
     adjList[n][p[n]]=0;
   }
}
int bfs(unordered_map<int, unordered_map<int, int> > &adjList, int s, int t){
   int maxflow=0;
//   for(auto i:adjList){
//	   cout<< i.first<<": ";
//     for(auto j:i.second){
//	     cout<<j.first<<" ";
//     }
//     cout<<endl;
//   }
//   cout<<endl;
//   cout<<s<<","<<t<<endl;
   while(true){
     int flow=0;
     queue<int> q;    
     unordered_map<int, int> dist, p;
     p[t]=p[s]=-1;
     for(auto i:adjList)dist[i.first]=INT_MAX, p[i.first]=-1;
     dist[t]=INT_MAX; 
     q.push(s);
     dist[s]=0;
     //cout<<endl;
     while(!q.empty()){
       auto node=q.front();q.pop();
       //cout<<node<<":n  ";
	if(node==t){
	   flow=1;
	   break;
	}
	       //cout<<"nxt";
       for(auto nxt:adjList[node]){
	       //cout<<nxt.first<<" ";
	   if(dist[nxt.first]!=INT_MAX)continue;
	   if(nxt.second<=0)continue;
	   p[nxt.first]=node;
	   dist[nxt.first] = dist[node]+1;
	   q.push(nxt.first);
       }
     }
     //cout<<flow<<"<---"<<endl;
     maxflow+=flow;
     augmented(t, p, adjList, s);
     if(flow==0)break;
   }
   return maxflow;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t=1; t<=T; t++){
     cin>>N; 
     vector<vector<int> > gR(N, vector<int>(N,0));
     vector<vector<int> > gB(N, vector<int>(N,0));

     cout<<"Case #"<<t<<": ";
     int cB=0, cR=0;
     for(int i = 0; i < N; i++){
	     for(int j = 0; j < N; j++){
		char c;
		cin>>c;
		if(c=='B') gB[i][j]=1, cB++;
		else if(c=='R') gR[j][i]=1, cR++;
	     }
     }
     if(abs(cB-cR)>1){
	cout<<"Impossible"<<endl;
	continue;
     }
     adjList1.clear();
     adjList2.clear();

     int idxR=0, idxB=0; 
     for(int i = 0; i < N; i++){
	for(int j =0 ; j <N; j++){
	   for(int k = 0; k < 6; k++){
	      int nr=i+rr[k], nc=j+cc[k];
	      if(nr<0 || nc<0 || nr>=N || nc>=N)continue;
	      if(gR[i][j] && gR[nr][nc])
		      adjList1[i*N+j][nr*N+nc]=adjList1[nr*N+nc][i*N+j]=1;
	      if(gB[i][j] && gB[nr][nc]) 
		      adjList2[i*N+j][nr*N+nc]=adjList2[nr*N+nc][i*N+j]=1;
	   }
	}
	if(gR[i][0]) adjList1[N*N][i*N]=adjList1[i*N][N*N]=1;
	if(gR[i][N-1])adjList1[N*N+1][i*N+N-1]=adjList1[i*N+N-1][N*N+1]=1;
	if(gB[i][0])adjList2[N*N][i*N]=adjList2[i*N][N*N]=1;
	if(gB[i][N-1])adjList2[N*N+1][i*N+N-1]=adjList2[i*N+N-1][N*N+1]=1;
     }
     int np1=bfs(adjList1, N*N, N*N+1), np2=bfs(adjList2, N*N, N*N+1);
     //cout<<np1<<" "<<np2<<endl;

     if(np1+np2==0)cout<< "Nobody wins"<<endl;
     else if(np1==1 && np2==0)cout<< "Red wins"<<endl;
     else if(np2==1 && np1==0)cout<< "Blue wins"<<endl;
     else{
	cout << "Impossible"<<endl;
     }
   }
   return 0;
}

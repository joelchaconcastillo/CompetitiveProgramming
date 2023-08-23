#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> edgeList;
vector<int> walk, lleft, rright;
int maxw;
void dfs(int node, int depth){
   if(edgeList[node].first != -2)
	 dfs(edgeList[node].first, depth+1);  
   walk.push_back(node);
   lleft[depth] = min(lleft[depth], (int)walk.size());
   rright[depth] = max(rright[depth], (int)walk.size());
   maxw =max(maxw, rright[depth]-lleft[depth]+1);
   if(edgeList[node].second != -2)
	 dfs(edgeList[node].second, depth+1);  

}
int main(){
   int n;
   cin>>n;
   maxw=0;
   edgeList.assign(n, make_pair(-1, -1));
   lleft.assign(n, INT_MAX);
   rright.assign(n, -INT_MAX);
   for(int i=0; i<n; i++){
	int id,l,r;
	cin>>id>>l>>r;
	id--, l--, r--;
	edgeList[id].first=l;
	edgeList[id].second=r;
   }
   dfs(0,0);
   for(int i =0;i < n;i++) 
	   if(rright[i]-lleft[i]+1==maxw){
		   cout << i+1<<" "<<maxw<<endl;
		   return 0;
	   }
   return 0;
}

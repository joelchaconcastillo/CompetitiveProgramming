#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > blocks;
vector<int> data;
int sizeb;
void update(int idx, int v){
   int idxb=idx/sizeb;
   for(int i=0; i < blocks[idxb].size(); i++){ 
       if(blocks[idxb][i]==data[idx]){
   	       blocks[idxb].erase(blocks[idxb].begin()+i);
	       break;
       }
   }
   auto it= upper_bound(blocks[idxb].begin(), blocks[idxb].end(), v);
   blocks[idxb].insert(it, v);
   data[idx]=v;
}
int query(int l, int r, int b){
   int lb=l/sizeb, rb=r/sizeb;   
   int cont=0;
   if(lb==rb){ //both belong to the same block..
	for(int i = l; i <= r; i++){
	  if( data[i]<=b)cont++;
	}
	return cont;
   }
   //left incomplete block...
   lb++;//first complete left block
   for(int i = l; i < lb*sizeb; i++){
	 if(data[i]<=b)cont++;
   }
   for(int i = rb*sizeb; i<=r; i++){
	if(data[i]<=b)cont++;
   }
   for(int i = lb; i < rb; i++){
	int val = upper_bound(blocks[i].begin(), blocks[i].end(), b)-blocks[i].begin();
	cont += val;
   }
   return cont;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int N,M;
   while(cin>>N>>M){
      sizeb=max( 128, (int)sqrt(N));
      data.assign(N, INT_MAX);
      blocks.assign(N/sizeb+1, vector<int>());
      while(M--){
         int Q;
         cin>>Q;
         if(Q==0){
   	   int id, v;
   	   cin>>id>>v;
   	   update(id, v);
         }else{
   	   int i, j, b;
   	   cin>>i>>j>>b;
   	   cout << query(i,j,b)<<endl;
         }
      }
      
   }
   return 0;
}

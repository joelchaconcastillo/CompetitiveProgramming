#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set_pair;
vector<ordered_set_pair> blocks;
vector<int> data;
int sizeb;
void update(int idx, int v){
   int idxb=idx/sizeb;
   blocks[idxb].erase({data[idx], idx});
   blocks[idxb].insert({v, idx});
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
	 cont += blocks[i].order_of_key({b+1, -INT_MAX});
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
      blocks.assign(N/sizeb+1, ordered_set_pair());
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

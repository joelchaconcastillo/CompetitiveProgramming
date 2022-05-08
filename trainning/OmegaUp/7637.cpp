#include <bits/stdc++.h>
#define NA -1
using namespace std;
class SegmentTree{
  int n;
  int left(int p){return p<<1;}
  int right(int p){return (p<<1)+1;}
  public:
  vector<int> data;
  vector<pair<int, int> > lazy;
  vector<int> tree;
  SegmentTree(int n){
      this->n = n;
      data.assign(n,0);
      lazy.assign(4*n, make_pair(NA, NA));
      tree.assign(4*n, 0); 
  }
  int conquer2(int a, int b){
    if(a==NA)return b;
    if(b==NA)return a;
    return max(a, b);
  }
  void propagate(int node, int L, int R){
     if(lazy[node].first!=NA){
       if(tree[node]==lazy[node].second) tree[node] +=lazy[node].first;
       if(L!=R){
	 if(lazy[left(node)].first==NA){
	   lazy[left(node)] = lazy[node];	
	 }
	 else{
	   lazy[left(node)].first +=lazy[node].first;
	 }

	 if(lazy[right(node)].first==NA){
	   lazy[right(node)] = lazy[node];	
	 }
	 else{
	   lazy[right(node)].first +=lazy[node].first;
	 }
	/// lazy[left(node)].first +=lazy[node].first;
	/// //if(lazy[left(node)].second == NA) lazy[left(node)].second=lazy[node].second;
	/// if(lazy[left(node)].second == NA) lazy[left(node)].second=tree[node]-lazy[node].first;
	/// lazy[right(node)].first +=lazy[node].first;
	/// //if(lazy[right(node)].second == NA) lazy[right(node)].second=lazy[node].second;
	/// if(lazy[right(node)].second == NA) lazy[right(node)].second=tree[node]-lazy[node].first;
       }else{
	   data[L] = tree[node];
       }
       lazy[node]=make_pair(NA, NA);
     }
  }
 void updateRange(int node, int L, int R, int i, int j, int currentMax){
      propagate(node, L, R);
      if(j<i || R<i || L>j)return;
      if(i<=L && j>=R){
	   lazy[node].second=currentMax;
	   lazy[node].first=1;
	   propagate(node, L, R);
	return;
      }else{
      int M = (L+R)/2;
       updateRange(left(node), L, M, i, j, currentMax);
       updateRange(right(node), M+1, R, i, j, currentMax);
       tree[node] = conquer2(tree[left(node)], tree[right(node)]);
      }
   }
  void build(int node, int L, int R){
      if(L==R){ tree[node]=data[L]; return;} // by index..
      int M=(L+R)/2;
      build(left(node), L, M);
      build(right(node), M+1, R);
      tree[node] = conquer2(tree[left(node)], tree[right(node)]);
   }
  int query(int node, int L, int R, int i, int j){
      propagate(node, L, R);
      if(j<i || j < L || i >R ) return NA; 
      if(L>=i && j>=R) return tree[node];
      int M = (R+L)/2;
      return conquer2(query(left(node), L,M, i, j), query(right(node), M+1,R, i, j));
   }
   int query(int i, int j){ //This is just to update the lazies!
      return query(1, 0, n-1, i, j);
   }
   void build(){
     build(1, 0, n-1);
   }
   void updateRange(int i, int j, int currentMax){
	updateRange(1, 0, n-1, i, j, currentMax);
   }
};
int main(){
   int N;
   cin>>N;
   SegmentTree st(N);
   for(int i = 0; i < N; i++)cin >> st.data[i];
   st.build();
   int M;
   cin>>M;
   while(M--){
     int i, j;
     cin>>i>>j;
     int currentMax = st.query(i,j-1);
     st.updateRange(i,j-1,currentMax);
   }  
   for(int i = 0;i<N;i++)cout <<st.query(i,i)<<" ";
   cout<<endl;

   return 0;
}

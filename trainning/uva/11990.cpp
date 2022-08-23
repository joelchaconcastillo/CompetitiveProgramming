#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> st;
vector<vector<int> > BIT; //biinary indexed tree to count the already removed items..
vector<long long>a; 
unordered_map<int,int> val2Idx;
long long inv;
int n;
int getSum(vector<int> &FT, int idx){
    int res=0;
    while(idx>0) res+=FT[idx], idx-= idx&(-idx);
    return res;
}
void updateSum(vector<int> &FT, int idx, int delta){
    while(idx<FT.size()) FT[idx]+=delta, idx += idx&(-idx);
}
void build(int node, int L, int R){
   if(L==R){ 
     BIT[node].assign(2,0); //plus one, one-index FenwickTree
     st[node].push_back(a[L]);
     return;
   }
   int m=(L+R)/2;
   build(node*2, L, m);
   build(node*2+1, m+1, R);
   for(int i = L; i <=R; i++) st[node].push_back(a[i]);
   sort(st[node].begin(), st[node].end());
//   st[node].assign(st[node*2].size()+st[node*2+1].size(), 0);
 //  merge(st[node*2].begin(), st[node*2].end(), st[node*2+1].begin(), st[node*2+1].end(), st[node].begin());
   BIT[node].assign(st[node].size()+1, 0);
}
long long queryPrefix(int node, int L, int R, int i, int j, long long val){
   if(j < L || i>R) return 0;
   if(i>j)return 0;
   if(i<= L && j>=R){
	int idx=upper_bound(st[node].begin(), st[node].end(), val)-st[node].begin();
	int nbigger = st[node].size()-idx;
	int removed = getSum(BIT[node], BIT[node].size()-1)-getSum(BIT[node], idx);
	return nbigger-removed;
   }
   int m=(L+R)/2;
   int l = queryPrefix(node*2, L, m, i,j, val);
   int r = queryPrefix(node*2+1, m+1, R, i,j, val);
   return l+r;
}
long long querySuffix(int node, int L, int R, int i, int j, long long val){
   if(j < L || i>R) return 0;
   if(i>j)return 0;
   if(i<=L && j>=R){
	int idx=upper_bound(st[node].begin(), st[node].end(), val)-st[node].begin();
	return idx-getSum(BIT[node], idx);
   }
   int m=(L+R)/2;
   int l = querySuffix(node*2, L, m, i,j, val);
   int r = querySuffix(node*2+1, m+1, R, i,j, val);
   return l+r;

}
void update(int node, int L, int R, int idx, int val){
   if(L==R){
      updateSum(BIT[node], 1, 1);
     return;
   }
   int m = (L+R)/2; 
   if(idx<=m){
      update(node*2, L, m, idx, val); 
   }else{
      update(node*2+1, m+1, R, idx, val); 
   }
   int pos = lower_bound(st[node].begin(), st[node].end(), val)-st[node].begin();
   updateSum(BIT[node], pos+1, 1);
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int m;
   while(cin>>n>>m){
       inv=0;
       a.assign(n, 0);
       st.assign(4*n, vector<long long>());
       BIT.assign(4*n, vector<int>());
       BIT[0].assign(n+1, 0);
       val2Idx.clear();
       for(int i = 0; i < n ; i++){
           cin>>a[i];
	   val2Idx[a[i]]=i;
           inv += i-getSum(BIT[0], a[i]);
	   updateSum(BIT[0], a[i], 1);
       }
       build(1, 0, n-1);
       for(int i = 0; i< m; i++){
	  cout<<inv<<endl;
          long long d;
	  cin>>d;
	  int left  = queryPrefix(1, 0, n-1, 0, val2Idx[d]-1, d);
	  int right = querySuffix(1, 0, n-1, val2Idx[d]+1, n-1, d);
	  inv -=left+right;
	  update(1, 0, n-1, val2Idx[d], d);
       }
   } 
   return 0;
}

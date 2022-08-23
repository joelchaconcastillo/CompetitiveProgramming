#include <bits/stdc++.h>
using namespace std;
int n, m, u, len;
vector<long long> A;
vector<vector<long long>>B;
int query(int l, int r, long long v){
    int c_l=l/len, c_r=r/len, cont=0;
    if(c_l==c_r){
      cont = lower_bound(B[c_l].begin(), B[c_l].end(), v)-B[c_l].begin();
    }else{
      for(int i=l; i < (c_l+1)*len; i++) if(A[i]<v)cont++;
      for(int i=c_l+1; i< c_r; i++){
         int pos = lower_bound(B[i].begin(), B[i].end(), v)-B[i].begin();
	 cont+=pos;
      }
      for(int i=c_r*len;i<=r;i++) if(A[i]<v)cont++;
    }
    return cont;
}
void update(int idx, long long new_v){
   int lb=idx/len;
   B[lb].erase(lower_bound(B[lb].begin(), B[lb].end(), A[idx]));
   A[idx]=new_v;
   auto it=upper_bound(B[lb].begin(), B[lb].end(), new_v);
   B[lb].insert(it, new_v);
}
int main(){
   cin>>n>>m>>u;
   len = sqrt(n)+1;
   A.assign(n,0);
   B.assign(len, vector<long long>());
   for(int i = 0 ; i < n ; i++){
     cin>>A[i];
     B[i/len].push_back(A[i]);
   }
   for(auto &i:B)sort(i.begin(), i.end());
   for(int i = 0; i < m; i++){
      long long L, R, v, p;
      cin>> L>>R>>v>>p;
      L--, R--, p--;
      long long k = query(L, R, v);
      update(p, u*k/(R-L+1LL));
   }
   for(int i = 0; i < n; i++)cout<<A[i]<<endl;

   return 0;
}

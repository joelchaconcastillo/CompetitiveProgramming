#include <bits/stdc++.h>
using namespace std;
int len, n;
long long inv;
vector<long long> A;
vector<vector<long long>> B;
unordered_map<int,int>id2B, val2id;
void remove(int val){
   int idB=id2B[val];
   for(int i=B.size()-1; i > idB; i--){
      int idx=upper_bound(B[i].begin(), B[i].end(), val)-B[i].begin();
      inv -= idx;
   }

   for(int i=B[idB].size()-1; i>=0; i--){
      int blockval=B[idB][i];
      if(val > blockval && val2id[val] < val2id[blockval])
	      inv--;
      if(blockval > val && val2id[blockval]<val2id[val]) inv--;
   }
   for(int i=idB-1;i>=0; i--){
      if(B[i].empty())continue;
      int idx=upper_bound(B[i].begin(), B[i].end(), val)-B[i].begin();
      if(idx==B[i].size())continue;
      inv -= (B[i].size()-idx);
   }
   auto it = lower_bound(B[idB].begin(), B[idB].end(), val);
   B[idB].erase(it);
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int m;
   while(cin>>n>>m){
   len=sqrt(n)+1;
   id2B.clear();
   val2id.clear();
   A.assign(n, 0);
   inv=0;
   B.assign(len, vector<long long>());
//   vector<long long>countInv;
   for(int i=0; i< n; i++){
     cin>>A[i];
     val2id[A[i]]=i;
     B[i/len].push_back(A[i]);
     id2B[A[i]]=i/len;
//     auto it=upper_bound(countInv.begin(), countInv.end(), A[i]);
//     long long idx=it-countInv.begin();
//     inv += countInv.size()-idx;
//     countInv.insert(it, A[i]);
   }
   for(auto &i:B) sort(i.begin(), i.end());
   for(int i=0; i < m; i++){
      int d;
      cin>>d;
      cout<<inv<<endl;
      remove(d);
   }   
 } 
   return 0;
}

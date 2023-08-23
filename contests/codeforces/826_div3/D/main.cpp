#include <bits/stdc++.h>
using namespace std;
int sortT(vector<int> &A, int l, int r){
    if(l+1>=r)return 0;
    int cont=0;   
    int m=(l+r)/2; 
    if(A[l] > A[m]){
      int i = l, j = m;
      while(i<m) swap(A[i++], A[j++]);
      cont++;
    }
    cont+=sortT(A, l,m);
    cont+=sortT(A, m, r);
    return cont;
}
int main(){
   int T;
   cin>>T;
   while(T--){
     int m;
     cin>>m;
     vector<int> A(m);
     for(auto &i:A) cin>>i;
     auto cnt =sortT(A, 0, m);
     bool flag=true;
     for(int i =0 ; i < m; i++)if(A[i]!=i+1){flag=false; break;}
     if(!flag)cout<<-1<<endl;
     else cout<<cnt<<endl;
   }
   return 0;
} 

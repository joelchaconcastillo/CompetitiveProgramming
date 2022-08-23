#include <bits/stdc++.h>
using namespace std;
struct Fenwick{
   vector<int> bits;
   int n;
   Fenwick(int _n){
      this->n=_n;
   }
   Fenwick(vector<int> a):n(a.size()){
     bits.assign(n+1, 0);
    for(int i = 0; i < n; i++) update(i+1, a[i]); 
   }
   int sum(int idx){
       int res=0;
       for(; idx >0; idx -= idx&(-idx)) res+=bits[idx];
       return res;
   }
   int sum(int l, int r){
       return sum(r)-sum(l-1);
   }
   void update(int idx, int val){
     int preVal = sum(idx, idx);
     for(; idx<=n; idx += idx&(-idx)) bits[idx]+= -preVal+val;
   }
};
int main(){
   int n, t=1;
   while(cin>>n){
    if(n==0) break;
    if(t>1)
     cout<<endl;
    vector<int> pot(n);
    for(auto &i:pot)cin>>i;
    Fenwick FT(pot);
    cout<<"Case "<<t<<":"<<endl;
     while(true){
     string act;
     cin>>act;
     if(act=="END")break;
     else if(act=="S"){
        int x, r;
	cin>>x>>r;
	FT.update(x,r);
     }
     else if(act=="M"){
       int x,y;
       cin>>x>>y;
       cout<<FT.sum(x,y)<<endl; 
     }
     }
     t++;
   }
   return 0;
}

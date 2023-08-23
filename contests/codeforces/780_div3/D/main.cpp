#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
      int n;
      cin>>n;
      vector<int> data(n), zero(n+1, 0), sign(n+1, 0), two(n+1, 0);
      for(int i = 0; i < n ; i++){
	 cin>>data[i];
	 zero[i+1]=zero[i];	
	 sign[i+1]=sign[i];
	 two[i+1]=two[i];
	 if(data[i]==0) zero[i+1]++;
	 if(abs(data[i])==2) two[i+1]++;
	 if(data[i]<0) sign[i+1] ^=1;
      }
      int ans=0, L=0, R=0, l=0;
      for(int i = 0; i < n ; i++){
	if(data[i]==0 || i ==n-1){
	  int h=i;
	  if(zero[i+1]==zero[i]) h=i+1;
	  vector<int> le(2, INT_MAX), ri(2, -1);
	  for(int j=l; j<=h; j++){
	     if(le[sign[j]]==INT_MAX)le[sign[j]]=j;
	     else ri[sign[j]]=j; 
	  }
	  for(int k=0; k <2; k++){
	     if(ri[k]==-1)continue;
	     if(ans < two[ri[k]]-two[le[k]]){
	       ans=two[ri[k]]-two[le[k]];
	       L=le[k], R=ri[k];
	     }
	  }
	  l=i+1;
	}
      }
      cout<<L<<" " <<n-R<<endl;
   }
   return 0;
}

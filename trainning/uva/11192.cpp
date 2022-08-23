#include <bits/stdc++.h>
using namespace std;
int main(){
   int k;
   string st;
   while(cin>>k){
      if(k==0)break;
      cin>>st;
      int n = st.size();
      k=n/k;
      for(int i = 0; i < n; i+=k){
	 int ii=i, jj=i+k-1;
         while(ii<jj)swap(st[ii], st[jj]), ii++, jj--;
      }
      cout <<st<<endl;
   }

   return 0;
}

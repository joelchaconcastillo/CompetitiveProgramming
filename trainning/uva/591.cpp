#include <bits/stdc++.h>
using namespace std;
int main(){
   int n, ite=1;
   while(cin>>n){
     if(n==0)break;
      vector<int> a(n);
      int ave = 0;
      for(int i = 0; i < n; i++){
         cin>>a[i];
         ave +=a[i];
      }
      ave/=n;
      int minv=0;
      for(int i = 0; i < n; i++) minv += abs(ave-a[i]);
      cout<<"Set #"<<ite<<"\n"<<"The minimum number of moves is "<<minv/2<<"."<<endl;
      cout<<endl;
      ite++;
   }
   return 0;
}

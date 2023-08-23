#include <bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   while(t--){
     int n;
     cin>>n;
     vector<int> A(n);
     for(auto &i:A)
	 cin>>i;
     for(int i = n%2; i < n; i+=2)
	     if(A[i]>A[i+1])swap(A[i], A[i+1]);
     bool isSorted=true;
     for(int i =  0 ; i+1 < n; i++)
	 if(A[i] > A[i+1]){
		 isSorted=false;
		 break;
	 }

     if(isSorted)cout<<"YES"<<endl;
     else cout <<"NO"<<endl;
   }
   return 0;
}

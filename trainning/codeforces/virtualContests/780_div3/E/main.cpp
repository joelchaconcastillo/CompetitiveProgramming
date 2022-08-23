#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
    int n;
    string trash;
    //cin>>trash;
    cin>>n;
    vector<string> M(n);
    int totalOnes=0;
    for(int i = 0; i < n; i++){
	cin>>M[i];
	for(int j = 0; j < n; j++)
	if(M[i][j]=='1')totalOnes++;
    }
    int maxDiag=0;
    for(int i = 0; i < n; i++){
       int count=0;
       for(int j=0, k1=0, k2=i; j< n; j++, k1++, k2++){
	 if(M[k1%n][k2%n]=='1')count++; 
       }
       maxDiag=max(maxDiag, count);
    }
      cout<<totalOnes-maxDiag + (n-maxDiag)<<endl; 
   }
   return 0;
}

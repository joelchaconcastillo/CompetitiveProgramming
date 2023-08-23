#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
     int n;
     cin>>n;
     vector<long> A(n), pre(n+1, 0);
     for(auto &i:A)cin>>i;
     for(int i = 1; i <=n; i++)pre[i] = pre[i-1]+A[i-1];
     long long sum = 0;
     int minl=INT_MAX;
     for(int l = 0; l < n; l++){
        sum+=A[l];
	int i=l+1, j=i, maxl=l+1;
	long long innerSum=0;
        while(j < n){
	    if(innerSum + A[j] < sum){
	      innerSum +=A[j];
	    }else if(innerSum+A[j]==sum){
		maxl = max(maxl, j-i+1);
	        innerSum=0;
		i=j+1;
	    }
	    else{
		break;
	    }
	  j++;
        }
	if(i==n) minl = min(maxl, minl);
     }
     cout << minl<<endl;
   }
   return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t;
   cin>>t;
   while(t--){
	   int n;
	   cin>>n;
	   int N=n*(n-1)/2;
	   vector<int> b(N);
	   for(int i=0; i<N; i++)cin>>b[i];
	   sort(b.begin(), b.end());
	   for(int i = 0; i < N; i += (--n)){
		   cout << b[i]<<" ";
	   }
cout<<"1000000000\n";
   }
   return 0;
}
/*
 *
 *  2- 1
 *  4 3 2 1 0
 *  2,2,2,2 ?
 *  -----------
 *  -2 -- 0
 *   0 -- 2
 *   3 -- 1
 *   4 3 2 1 0
 *  -2 0 0 3 
 * */

#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   while(T--){
	   int n;
	   cin>>n;
	   vector<vector<long long>>a(n);
	   long long score = 0, minsecond=INT_MAX, minfirst=INT_MAX;
	   for(int i = 0 ; i < n; i++){
	      int m ;
	      cin>>m;
	      for(int j = 0 ; j <m; j++){
		      int d;
		      cin>>d;
		      a[i].push_back(d);
	      }
	      sort(a[i].begin(), a[i].end());
	      minfirst=min(minfirst, a[i][0]);
	      minsecond=min(minsecond, a[i][1]);
	      score +=a[i][1];
	   }
	   score = score-minsecond+minfirst;

	   cout <<score<<endl;
   }
   return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin>>T;
   for(int t = 1; t<=T;t++){
      string landscape;
      cin>>landscape;
      landscape = "_"+landscape+"_";
      int n = landscape.size();
      vector<double> h;
      double ch =0.0, minv = INT_MAX;
      for(int i = 0 ;i < n; i++){
	 if(landscape[i]=='/'){
		ch  +=0.5;
	 }
	 else if(landscape[i]== '\\'){
		ch -=0.5;
	 }
	 minv = min(minv, ch);
	 h.push_back(ch);
      }
      for(auto &i:h)i-=minv;
//      for(auto i:h)cout <<i <<" ";
//      cout<<endl;

      int n1 = h.size();
      double ground=0.0, ml=0, mr=0, sl=0.0, sr=0.0;
      for(int i = 0 ; i < n1; i++){
	  ml = max(ml, h[i]);
	  mr = max(mr, h[n-i-1]);
	  sl +=ml;
	  sr +=mr;
	  ground +=h[i];
      }
      long long res = 2.0*(sl+sr-(n1*ml)-ground);
      cout <<res <<endl;
   }
   return 0;
}

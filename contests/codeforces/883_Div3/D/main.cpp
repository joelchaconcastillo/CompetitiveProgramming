#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   for(int t = 1; t <=T ;t++){
      int n;
      double d, h;
      cin>>n>>d>>h;
      vector<int> y(n);
      for(int i = 0; i < n; i++) cin>>y[i];
      sort(y.begin(), y.end());
      double sumAreas = 0.0;
      //look for overlaps...
      for(int i = 0; i < n; i++){
	 double area = d*h/2.0;
	 if(i+1<n && y[i]+h > y[i+1]){
	   double hl = (y[i]+h-y[i+1]);
	   area -= (hl*hl)*d/(2.0*h);
	 }
	 sumAreas +=area;
      }
      cout <<fixed<<setprecision(8)<<sumAreas<<endl;
   }
   return 0;
}

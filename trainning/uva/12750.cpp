#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
      int n;
      cin>>n;
      int count=0, notWin=0;
      for(int i = 0 ; i < n ; i++){
	     char c;
	     cin>>c;
	     if(c=='L' || c=='D')
		     notWin++;
	     else notWin=0;
	     if(notWin==3 && count == 0) count=i+1;
      }
      cout <<"Case "<<t<<": ";
      if(count==0)cout<<"Yay! Mighty Rafa persists!"<<endl;
      else cout<< count <<endl;
   }
   return 0;
}

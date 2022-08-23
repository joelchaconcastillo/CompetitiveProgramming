#include <bits/stdc++.h>
using namespace std;
int main(){
   int t, counter=0;;
   cin>>t;
   while(t--){
    double l,w,d,weigth;
    cin>>l>>w>>d>>weigth;
    if(( ( l<=56 && w<=45 && d<=25) || (l+w+d) <=125.0) && weigth <= 7.0){
	cout<<"1"<<endl;
	counter++;
    }else{
	cout<<"0"<<endl;
    }
   }
   cout<<counter<<endl;
   return 0;
}

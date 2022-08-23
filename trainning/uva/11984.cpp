#include <bits/stdc++.h>
using namespace std;
double toFaren(double c){
     return 9.0*c/5.0+32;
}
double toCelcius(double f){
   return (f-32.0)*5.0/9.0;
}
int main(){
   int T;
   cin>>T;
   for(int t=1;t<=T; t++){
      double C, d;
      cin>>C>>d;
      cout<<"Case "<<t<<": "<<fixed<<setprecision(2)<<toCelcius(toFaren(C)+d)<<endl;
   }
   return 0;
}

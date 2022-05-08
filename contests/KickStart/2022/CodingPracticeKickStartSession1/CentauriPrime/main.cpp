#include <bits/stdc++.h>
using namespace std;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
     string kindom;
     cin>>kindom;
     char last =  tolower(kindom.back());
     if(last=='y')
	    cout<<"Case #"<<t<<": "<< kindom << " is ruled by nobody."<<endl;
     else if( last=='a' || last=='e' || last=='i' || last=='o' || last=='u')
	    cout<<"Case #"<<t<<": "<< kindom << " is ruled by Alice."<<endl;
     else
	    cout<<"Case #"<<t<<": "<< kindom << " is ruled by Bob."<<endl;
   }
   return 0;
}


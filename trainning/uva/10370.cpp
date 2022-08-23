#include <bits/stdc++.h>
using namespace std;
int main(){
   int C;
   cin>>C;
   while(C--){
     int n;
     cin>>n;
     int sum=0;
     vector<int> a(n);
     for(int i = 0 ; i< n ; i++)cin>>a[i], sum+=a[i];
     double ave = double(sum)/double(n);
     int cont = 0;
     for(auto i:a){
	if(i>ave)cont++;
     }
     cout << fixed<<setprecision(3)<<cont/double(n)*100.0<<"%"<<endl;
   }
   return 0;
}

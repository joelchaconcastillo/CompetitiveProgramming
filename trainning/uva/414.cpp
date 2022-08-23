#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   while(cin>>n){
    if(n==0)break;
    int sumSpaces=0, minSp=INT_MAX;
    string line;
       getline(cin, line);
    for(int i = 0 ; i < n ; i++){
       getline(cin, line);
       int sp=0;
       for(auto ii:line)
	   sp+=(ii==' ');
       minSp=min(minSp, sp);
       sumSpaces+=sp;
    }
    cout << sumSpaces-n*minSp<<endl;
   }
   return 0;
}

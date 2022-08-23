#include <bits/stdc++.h>
using namespace std;
int bk(string ns, int removed){
    if(ns.empty()) return 1000000;
    long long nl=stoll(ns);
    if(nl%25==0) return removed;
    while(!ns.empty() && ns.front()=='0') ns.erase(0,1), removed++;
    if(ns.empty()) return removed;

    int minv = 10000;
    for(int i = 0; i < ns.size(); i++){
	    string n2 = ns;
	    n2.erase(n2.begin()+i);
	    bool potential=0;
	    for(auto ii:n2) if(ii=='5' || ii=='0') potential=1;
	    if(potential)
       minv = min(minv, bk(n2, removed+1));
    }
    return minv;
}
int main(){
   int T;
   cin>>T;
   while(T--){
     string n;
     cin>>n;
     int s=n.size();
     string last[]={"00", "25", "50", "75"};
     int minr=s;
     for(int i = 0; i < 4; i++){
	     int cv=1;
       for(int j = s-1; j>=0; j--){
	   if(last[i][cv]==n[j])cv--;
	   if(cv==-1){
	     minr=min(minr, s-j-2);
	     break; 
	   }
       }
     }
     cout << minr<<endl;
   }
   return 0;
}

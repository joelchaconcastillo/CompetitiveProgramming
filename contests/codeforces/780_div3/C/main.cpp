#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
    string st;
    cin>>st; 
    int n=st.size(), total=0;
    vector<bool>marked(n, false);
    for(auto i:st){
	if(marked[i-'a']) total+=2, marked.assign(n, false);
	else marked[i-'a']=true;
    }
    cout<<n-total<<endl;
   }
   return 0;
}

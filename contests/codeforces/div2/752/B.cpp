#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin>>T;
   while(T--){
    int n, d;
    cin>>n;
    vector<int>data(n);
    for(int i = 0; i<n; i++){
	cin>>data[i];
    }
    if(n%2==0){
	cout << "YES"<<endl;
	continue;
    } 
    bool f=0;
    for(int i = 0; i < n-1; i++){
	if(data[i]>=data[i+1]){
	 f=1;
	break; 
	}
    }
    if(f)cout<<"YES\n";
    else cout << "NO\n";
   }
   return 0;
}

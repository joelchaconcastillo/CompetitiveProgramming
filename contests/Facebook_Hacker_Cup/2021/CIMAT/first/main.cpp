#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  string target="facebook";
  cin >>T;
  for(int t = 1; t<=T; t++){
   string st;
    cin>>st; 
    bool found = false;
    for(int i = 0, j=0 ; i< st.size(); i++){
	if(target[j]==st[i])j++;
	if(j==target.size()){
		found=true;
		break;
	}
    }
    if(found)cout<<"Case #"<<t<<": YES\n";
    else cout <<"Case #"<<t<<": NO\n";
  }
  return 0;
}

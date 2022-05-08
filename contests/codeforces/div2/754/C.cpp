#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin >>T;
   while(T--){
    int n;
    string st;
    cin >>n>>st;
    set<string>s;
    s.insert("aba");
    s.insert("aca");
    s.insert("abca");
    s.insert("acba");
    s.insert("abbacca");
    s.insert("accabba");
    s.insert("aa");
    bool found=0;
    for(auto i:s){
	if(st.find(i)!=std::string::npos){
		cout << i.size()<<endl;
		found=1;
		break;
	}
    }
    if(!found)cout<<-1<<endl;
//    if(s.size()<=1){
//      cout <<-1<<endl;
//      continue;
//    }
//    int counterB=0, counterC=0;
//    int i = 0, mins=INT_MAX;
//    while(i<s.size() && s[i]!='a')i++;
//    for(int j=i+1; j< s.size(); j++){
//      if(s[j]=='b')counterB++;   
//      else if(s[j]=='c')counterC++; 
//      else if(s[j]=='a'){
//        if(counterB < 2 && counterC < 2) mins=min(mins, j-i+1);
//	i=j;
//	counterB=0;
//	counterC=0;
//      }
//    }
//    if(mins!=INT_MAX)
//    cout << mins<<endl;
//    else cout <<-1<<endl;
   }
   return 0;
}

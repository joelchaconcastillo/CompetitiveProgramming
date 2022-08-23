#include <bits/stdc++.h>
using namespace std;

int main(){
   string s;
   while(cin>>s){
	int l=0, r=s.size()-1;
	while(l<r){
           if(s[l]!=s[r])l++;
	   else{ //check if it is palindrome..
	      int l2=l,r2=r;
	      while(l2<r2 && s[l2] ==s[r2]) l2++,r2--;
	      if(l2>=r2 && s[l2]==s[r2]) break;
	      l++;
	   }   
	}
	for(int i = l-1; i>=0; i--) s+=s[i];
	cout << s<<endl;
   }
   return 0;
}

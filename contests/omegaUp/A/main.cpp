#include <bits/stdc++.h>
using namespace std;
string binpow(int n){
     if(n==0)return "1";
     string res="2";
     --n;
     while(n--){
	int rem=0;
        for(int i = res.size()-1; i>=0; i--){
	   int d1=(int)(res[i]-'0'); 
	   d1=2*d1+rem;
	   rem=d1/10;
	   d1%=10;
	   res[i] =(char)(d1+'0');
	}
	if(rem!=0) res= (char)(rem+'0')+res;
     }
     return res;
}
string mult(string st1, string st2){
     int n1=st1.size(), n2=st2.size();
     //it is easier to manipulate add and mult at the same time
     reverse(st1.begin(), st1.end()); 
     reverse(st2.begin(), st2.end());
     string res="";
     for(int i = 0; i < n1; i++){
        int rem = 0;
        for(int j = 0; j < n2; j++){
	  int d1=(int)(st1[i]-'0'), d2=(int)(st2[j]-'0'); 
	  int prod = d1*d2+rem;
	  if(j+i<res.size()) //adding or not..
	      prod += (int)res[j+i]-'0';
	  rem = prod/10;
	  prod%=10;
	  if(j+i<res.size())
	    res[j+i] = (char)prod+'0';
	  else 
	   res += (char)(prod+'0');
	}
	if(rem!=0) res+=(char)( rem+'0');
     }
     reverse(res.begin(), res.end());
     return res;
}
int main(){
   int n;
   cin>>n;
   cout << binpow(n)<<endl;
   return 0;
}

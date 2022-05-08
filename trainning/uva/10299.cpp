#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n, result;
  while(cin>>n, n!=0){
	  result=n;
    if(n==1){cout << 0<<endl;continue;}
    for(int i = 2; i*i<=n; i++){
     if(n%i==0){
      while( n%i==0) n/=i;
	result -= result/i;
     }
    }
    if(n>1) result -=result/n;
    cout << result<<endl;
  }
  return 0;
}

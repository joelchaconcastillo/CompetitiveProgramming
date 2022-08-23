#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    long long m=1,cont=1;
    while(m%n!=0) m*=10,m+=1, cont++, m%=n;
    cout<<cont<<endl;
  }
  return 0;
}

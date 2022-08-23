#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin>>T;
  while(T--){
     int N, P;
     cin>>N>>P;
     vector<int> d(N+1,0);
     int cont=0;
     for(int i=0; i < P; i++){
        int hi;	
	cin>>hi;
	int k=hi;
	while(k<=N) d[k]=1, k+=hi;
     }
     for(int i=1; i<=N;i++){
	     if((i%7)!=0 && (i%7)!=6 && d[i]==1)cont++;
     }
     cout<<cont<<endl;
  }
  return 0;
}

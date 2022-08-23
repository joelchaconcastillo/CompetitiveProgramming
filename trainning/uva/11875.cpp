#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin>>T;
  for(int t=1; t<=T; t++){
     int N;
     cin>>N;
     vector<int> a(N,0);
     for(int i = 0 ; i <N; i++)cin>>a[i];
     cout<<"Case "<<t<<": "<<a[N/2]<<endl;
  }
  return 0;
}

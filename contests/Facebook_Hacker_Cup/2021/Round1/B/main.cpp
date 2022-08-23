#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin>>T;
  for(int t = 1; t <=T; t++){
    int N,M,A,B;
    cin >>N>>M>>A>>B;
    int minl=N+M-1;
    if( A < minl || B < minl ){
      cout << "Case #"<<t<<": Impossible"<<endl;
      continue;
    }
    vector<vector<int> > g(N, vector<int> (M,1));
    g[0][0]=A-(N+M-2);
    g[0][M-1]=B-(N+M-2);
    cout << "Case #"<<t<<": Possible"<<endl;
    for(int i = 0; i < N; i++){
       for(int j = 0; j <M; j++){
	       cout << g[i][j];
	       if(j<M-1)cout <<" ";
       }
       cout <<endl;
    }
  }
  return 0;
}

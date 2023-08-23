/*
  dp(i,j, k, l) = dp(i-1, x, j, k)+gap(i)
 * */
#include <bits/stdc++.h>
using namespace std;
const int MXN = (int)4e5;
int dp[MXN][3][3][3];
int gap(int a, int b){
  if(b<a)b+=3;
  return (b-a)%3;
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int T;
   cin>>T;
   for(int t = 1; t <=T; t++){
      int n;
      cin>>n;
      vector<int>data(n);
      for(int i = 0 ; i < n; i++) cin>>data[i], data[i]%=3;
      for(int i = 0 ; i < n; i++){
	 for(int j = 0; j < 3; j++){
	    for(int k = 0; k <3; k++){
	       for(int l = 0 ; l < 3; l++){
		  dp[i][j][k][l]=MXN;
	       }
	    }
	 }
      }
      for(int j = 0; j <3; j++){
	 for(int k = 0 ; k <3; k++){
	    for(int l = 0; l < 3; l++){
		if((j+k+l)%3 !=0)continue;
		dp[2][j][k][l] = gap(data[0], j)+gap(data[1], k)+gap(data[2], l);
	    }
	 }
      }
      for(int i = 3; i < n; i++){
	 for(int j = 0 ; j < 3; j++){
	    for(int k = 0 ; k <3; k++){
	       for(int l = 0; l < 3; l++){
		  if((j+k+l)%3!=0)continue;
		  dp[i][j][k][l] = min(dp[i][j][k][l], dp[i-1][ (3-(j+k)%3)%3 ][j][k] + gap(data[i], l));
	       }
	    }
	 }
      }
      long long ans = INT_MAX;
      for(int j = 0; j < 3; j++){
	 for(int k = 0; k < 3; k++){
	     for(int l = 0; l < 3; l++){
		if((j+k+l)%3==0)ans = min(ans, (long long)dp[n-1][j][k][l]);
	     }
	 }
      }
      cout << ans<<endl;
   }
   return 0;
}

#include <bits/stdc++.h>
#define MAXS 352
using namespace std;
int L, S, t=1;
int dp[27][27][MAXS];//all the substrings that ends at letter 'l', length, sum
/*    j 
 *    ----
 *    0:
 *    1:
 *    ---
 *    0:
 *    1:
 *    2:
 * */
int main(){
   while(cin>>L>>S){
     if(L==0 && S==0)break;
     memset(dp, 0, sizeof dp);
     if(L>26 || S>MAXS){
	cout <<"Case "<<t<<": 0"<<endl;
       t++;
       continue;
     }
     dp[0][0][0]=1;
     for(int i = 1; i<=26; i++){
       for(int j = 0; j<= i; j++){ //length
	 for(int s=0; s<MAXS; s++){
            dp[i][j][s] = dp[i-1][j][s]; 
	    if(j>0 && s>=i) dp[i][j][s] += dp[i-1][j-1][s-i]; //taking it..
	 }
       }
     }
     cout <<"Case "<<t<<": "<< dp[26][L][S]<<endl;
     t++;
   }
   
   return 0;
}

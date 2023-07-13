#include <bits/stdc++.h>
using namespace std;
bool check(int i, int j, int trialPow, int items){
   int jump = 1<<trialPow;
   for(int l = 1; l <= items; l+=jump){
      if( l<=i && j<(l+jump))return true;
   }
   return false;
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int N, i ,j;
   while(cin>>N>>i>>j){
     int level = 1<<N;
     if(i>j)swap(i,j);
     int l = i, u=j;
     if(i%2==0)l--;
     if(j%2==1)u++;
     int trialPow = ceil(log2(u-l+1));
     while(!check(i, j, trialPow, 1<<N)){
	     trialPow++;
     }
     cout << trialPow<<endl;

   }
   return 0;
}

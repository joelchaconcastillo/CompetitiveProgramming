#include <bits/stdc++.h>
using namespace std;
int main(){
   int N, M;
   while(cin>>N>>M){
     int count = 0;
     for(int i = 0; i < N; i++){
	int matchesWinned=0;
        for(int j = 0 ; j < M; j++){
	   int tmp;
	   cin>>tmp;
	   if(tmp>0)matchesWinned++;
	}
	if(matchesWinned==M)count++;
     }
     cout << count<<endl;
   }
   return 0;
}

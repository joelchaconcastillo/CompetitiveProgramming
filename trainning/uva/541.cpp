#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
   while(cin>>n){
     if(n==0)break;
     vector<vector<int>> mat(n, vector<int>(n, 0));
     vector<int> rowOdd, colOdd;
     for(int i = 0 ; i < n ; i++){
       int sum=0;
       for(int j = 0 ; j < n; j++)
	cin>>mat[i][j], sum+=mat[i][j];
       if(sum%2==1)rowOdd.push_back(i);
     }
     for(int i = 0 ; i < n; i++){
	int sum=0;
	for(int j = 0 ; j < n; j++)
	sum+=mat[j][i];
	if(sum%2==1) colOdd.push_back(i);
     }
     if(rowOdd.size()>1 || colOdd.size()>1)cout<<"Corrupt"<<endl;
     else if(rowOdd.empty() && colOdd.empty())cout<<"OK"<<endl;
     else{
	cout<<"Change bit ("<<rowOdd.front()+1<<","<<colOdd.front()+1<<")"<<endl;
     }
   } 
   return 0;
}

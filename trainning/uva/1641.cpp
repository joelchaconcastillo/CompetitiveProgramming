#include<bits/stdc++.h>
using namespace std;
int main(){
   int h, w;
   while(cin>>h>>w){
      vector<string> g(h);
      for(int i=0; i<h; i++)cin>>g[i];
      double area=0;
      for(int i=0; i <h; i++){
	 bool flag=false;
         for(int j=0; j < w; j++){
	    if(g[i][j]=='\\' || g[i][j]=='/')
	     flag = 1-flag;
	    if(g[i][j]!='.')area+=0.5;
	    if(flag && g[i][j]=='.')area++;
	 }
      }
      cout << area<<endl;
   }
   return 0;
}

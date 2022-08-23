#include <bits/stdc++.h>
using namespace std;
void printMaze(string &st){
   int num=0;
   for(auto i:st){
      if(i>='0' && i<='9')num +=(i-'0'); 
      else if(i=='!'){
	   num=0;
	   cout<<endl;
      }
      else{
	for(int ii = 0; ii<num; ii++){
		if(i=='b')cout<<' ';
		else
	       	cout<<i;
	}
 	num=0;	
      }
   }
   cout<<endl;
}
int main(){
   string st;
   int t=0;
   while(getline(cin, st)){
	if(t>0)
	cout<<endl;

	  printMaze(st);
	while(getline(cin, st)){
	  if(st.empty())break;
	  printMaze(st);
	}
	t++;
   }
   return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   set<string>oudlers;
   oudlers.insert("fool");
   oudlers.insert("one of trumps");
   oudlers.insert("twenty-one of trumps");
   map<string, double>points;
   points["king"]=points["oudler"]=4.5;
   points["queen"]=3.5;
   points["knight"]=2.5;
   points["jack"]=1.5;

   for(int t=1;t<=T;t++){
	   if(t>1)cout<<endl;
	  int n;
	  cin>>n;
	  int countoudlers=0;
	  double required=0.0, achieved=0.0;
	  string card;
	  cin.ignore();
	  for(int i = 0 ;i < n; i++){
		 getline(cin, card);
		 bool isoudler=false;
		 if(oudlers.count(card)>0){
			 countoudlers++;
			 isoudler=true;
		 }
		 stringstream ss(card);
		 string value;
		 getline(ss, value, ' ');
		 if(isoudler)achieved+=4.5;
		 else if(points.find(value)!=points.end())
		 achieved+=points[value];
		 else achieved +=0.5;
	  }
	  if(countoudlers==3) required=36;
	  else if(countoudlers==2)required=41;
	  else if(countoudlers==1)required=51;
	  else required=56;
	  cout<<"Hand #"<<t<<endl;
	  if(achieved<required) cout<<"Game lost by "<<required-achieved<<" point(s)."<<endl;
	  else cout <<"Game won by "<<achieved-required<<" point(s)."<<endl;
   }
   return 0;
}

/*
 *  
 *   AB CDA
     CB ADC
     Jane...ABC BCDADA
     John...C
     Jane..
     John..CA BC
 *
 * */
#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t = 1 ; t <=T ; t++){
      string Jane, John;
      if(t>1)cout<<endl;
      cin>>Jane>>John;
      deque<char> q1,q2, q11, q22;
      for(auto i:Jane) q1.push_back(i);
      for(auto i:John) q2.push_back(i);

      for(int ii = 0 ; ii < 1000; ii++){
	      if(q1.empty()){
		      while(!q11.empty()){
			   q1.push_front(q11.front());
			   q11.pop_front();
		      }
		      q11.clear();
	      }
	      if(q2.empty()){
		      while(!q22.empty()){
			   q2.push_front(q22.front());
			   q22.pop_front();
		      }
		      q22.clear();
	      }
	      if(q1.empty() || q2.empty()) break;
	      auto J1 = q1.front(); q1.pop_front();
	      auto J2 = q2.front(); q2.pop_front();
	      q11.push_front(J1);
	      q22.push_front(J2);
	      if(J1 == J2){
		 if((random()/141)%2 == 0){ //Jane
		   while(!q22.empty()){
		      q11.push_front(q22.back());
		      q22.pop_back();
		   }
		   auto cp = q11;
		   cout <<"Snap! for Jane: ";
		   while(!cp.empty()){
			  cout <<cp.front();
			 cp.pop_front();
		   }
		   cout<<endl;
		 }else{
		   while(!q11.empty()){
		      q22.push_front(q11.back());
		      q11.pop_back();
		   }
		   auto cp = q22;
		   cout <<"Snap! for John: ";
		   while(!cp.empty()){
			  cout <<cp.front();
			 cp.pop_front();
		   }
		   cout<<endl;
		 }
	      }
//	      cout << q1.size()<<" "<<q11.size()<<" "<<q2.size()<<" "<<q22.size()<<endl;
      }
      if(!q1.empty()){
	  cout <<"Jane wins."<<endl;
      }else if(!q2.empty()){
	  cout << "John wins."<<endl;
      }
      else{
	  cout << "Keeps going and going ..."<<endl;
      }
   }
   return 0;
}

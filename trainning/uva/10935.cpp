#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   while(cin>>n){
     if(n==0)break;
     deque<int> dq;
     for(int i = 1 ;i <= n ; i++){
	dq.push_back(i);
     }
     vector<int> a;
     while(dq.size()>1){
	a.push_back(dq.front());
	dq.pop_front();
	dq.push_back(dq.front());
	dq.pop_front();
     }
     cout<<"Discarded cards:";
     if(!a.empty())cout<<" ";
     for(int i = 0 ; i< a.size() ; i++){
	if(i>0)
	 cout<<", ";
	cout<<a[i];
     }
     cout<<endl;
     cout<<"Remaining card:";
     if(!dq.empty())cout<<" "<<dq.back()<<endl;


   }
   return 0;
}

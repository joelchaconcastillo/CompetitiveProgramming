#include <bits/stdc++.h>
using namespace std;
int main(){
   string st;
   while(cin>>st){
     stack<string> stk;

     unordered_map<string, bool> open, closed;
     unordered_map<string, string> paired;
     open["("]=open["["]=open["{"]=open["<"]=open["(*"]=true;
     closed[")"]=closed["]"]=closed["}"]=closed[">"]=closed["*)"]=true;
     paired["("]=")";
     paired["["]="]";
     paired["{"]="}";
     paired["<"]=">";
     paired["(*"]="*)";
     int n=st.size(), pos=-1;
     for(int i = 0 ; i <n; i++){
	if(i+1<n && open[st.substr(i, 2)]) stk.push(st.substr(i, 2)), i++;
	else if(open[st.substr(i, 1)]) stk.push(st.substr(i,1));
	else if(i+1<n && closed[st.substr(i, 2)]){
 	  if(!stk.empty() && paired[stk.top()] == st.substr(i,2))stk.pop(), i++;
	   else{
		  pos=i;
		  break;
	   }
	}
	else if(closed[st.substr(i, 1)]){
	   if(!stk.empty() && paired[stk.top()] == st.substr(i,1))stk.pop();
	   else{
		  pos=i;
		  break;
	   }
	}
     }
     if(pos!=-1){
	     cout<<"NO "<< pos<<endl;
     }else cout<<"YES"<<endl;
   }
   return 0;
}

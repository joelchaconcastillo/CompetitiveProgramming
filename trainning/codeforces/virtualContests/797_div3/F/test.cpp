#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b){
    return (b==0)?a:(gcd(b, a%b));
}
long long mcm(long long a, long long b){
    return (a/gcd(a,b))*b;
}
void mvRight(string &st){
     st = st.back()+st.substr(0, st.size()-1);
}
int main(){
   int t;
   cin>>t;
   while(t--){
     int n;
     cin>>n;
     string st;
     cin>>st;
     vector<long long>data(n);
     vector<vector<long long> > edges(n, vector<long long>());
     for(int i = 0 ; i < n ; i++){
	     cin>>data[i];
	     data[i]--;
	     edges[i].push_back(data[i]);
     }
     vector<bool>marked(n, false);
     long long MCM=1;
     for(int i = 0; i < n; i++){
	if(marked[i])continue;
        queue<long long> q;
	q.push(i);
	string _substr="";
	while(!q.empty()){
	   auto node=q.front(); q.pop();
	   if(marked[node])break;
	   _substr.push_back(st[node]);
	   marked[node]=true;
	   for(auto next:edges[node])q.push(next);
	}
	//compute shifts...
	long long steps=0;
	auto cpy=_substr;
	mvRight(cpy);
	steps++;
	while( cpy != _substr) mvRight(cpy), steps++;
	MCM = mcm(MCM, steps);
     }
     cout<<MCM<<endl;
   }
   return 0;
}

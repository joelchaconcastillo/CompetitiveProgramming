#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 3e5+5;
int p[MAXN], r[MAXN], t_p[MAXN], t_r[MAXN];
int setfind(int x){
   if(p[x] == x) return x;
   return p[x]=setfind(p[x]);
}

void setunion(int a , int b) {
  a = setfind(a);
  b = setfind(b);
  if (a == b)
    return;
  else {
    if (r[a] < r[b])
      swap(a, b);
    p[b] = a;
    r[a] += r[b];
  }
}

void initialize(int n) {
  for (int i = 0; i < n ; i++) {
    r[i] = 1;
    p[i] = i;
  }
}
int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int T;
   cin>>T;
   while(T--){
     int N;
     cin>>N;
     vector<long long>d(N,0);

     for(int i =0 ; i < N; i++) cin>>d[i];
     sort(d.begin(), d.end());
     if(d.front()==d.back()){
       cout << 0<<endl;
       continue;
     }else if(N==2){
       cout << (d.front()^d.back())<<endl;
       continue;
     }
     int h=0;
     for(int i = 30; i >=0; i--){
	int cnt=0;
        for(int j = 0 ; j < N; j++){
	   if((1ll<<i)&d[j]) cnt++;
	}
	if(cnt>0 && cnt<N){h=i; break;}
     }     
     vector<int> which(N,0);
     initialize(N);
     for(int i = 0 ; i < N; i++){
	if((1ll<<h)&d[i]) which[i]=1;
	else which[i]=0;
     }
     for(int i = h-1; i >=0; i--){
	bool j1=false, j2=false;// partition j1 and partition j2
	for(int j = 0 ; j < N; j++){
	   if( (1ll<<i)&d[j]){
	     if(which[j]==0) j1=true;
	     else j2=true;
	   }
	 }
	   //case 1 or Case 2
	   if((!j1 && !j2) || (!j1 && j2) ) continue;
	   //case 3
	   else if(j1 && !j2){
	     vector<int> partition1;
	     for(int j=0; j <N; j++) if((1ll<<i) & d[j]) partition1.push_back(j);
	     for(int j=1; j < partition1.size(); j++) setunion(partition1[j], partition1[j-1]);
	   }
	   else{
             vector<int> partition1;
	     for(int j=0; j <N; j++){
		if(((1ll<<i) & d[j]) && which[j]==0) 
		  partition1.push_back(j);
	     }
	     for(int j=0; j<N; j++){
		 int a = setfind(j);
		 t_p[j]=a;
		 t_r[j]=r[a];
	     }
	     for(int j=1; j < partition1.size(); j++) setunion(partition1[j], partition1[j-1]);
	     int cont = 0;
	     for(int j = 0 ; j < N; j++) cont += (which[j]==0);
	     if(cont == r[setfind(partition1.front())]){ //we cann't merge them...
		   for(int j=0; j <N; j++)p[j]=t_p[j], r[j]=t_r[j];
	     } else{
	        for(int j = 0 ; j < N; j++){
	           if(setfind(j) == setfind(partition1.front()))
	             which[j]=1;
	        }
	     }
	  }
     }
     int or1=0, or2=0;
     for(int i = 0 ; i < N; i++){
	if(which[i]==0) or1 |= d[i];
	else or2 |=d[i];
     }
     cout <<(or1^or2)<<endl;
   }
   return 0;
}

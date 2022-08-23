#include <bits/stdc++.h>
using namespace std;
int main(){
   int N;
   while(cin>>N){
     vector<int> a(N,0);
     for(int i = 0 ; i < N; i++){
	     cin>>a[i];
     }
     auto b=a;
     sort(b.begin(), b.end());
     int count=0;
     for(int i = 0; i < N; i++){
       int j=i;
       while(a[j]!=b[i])j++;
       while(j>i)swap(a[j], a[j-1]), j--, count++;
     }
     cout<<"Minimum exchange operations : "<<count<<endl;
   }
   return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
  int N =1000, M=20000;
  cout <<N<<" " <<M<<endl;
  for(int i = 0; i < M; i++){
     int a=rand()%N, b=rand()%N;	
     if(a>b)swap(a,b);
     if(a==b)b++;
     cout<<a+1<<" "<<b+1<<endl;
  }
  return 0;
}

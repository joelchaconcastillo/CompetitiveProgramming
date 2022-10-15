#include <bits/stdc++.h>
using namespace std;
void hanoi(int count, char source, char dest, char inter){
   if(count==1){
      return;
   }
   hanoi(count-1, source, inter, dest);
   hanoi(1, source, dest, inter);
   hanoi(count-1, inter, inter , source);
}
int main(){
   int n, m;
   while(cin>>n>>m){
     if(n==0 && m==0)break;
     hanoi(n, 'A', 'C', 'B');
   }
   return 0;
}

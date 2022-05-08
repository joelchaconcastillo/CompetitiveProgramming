#include <bits/stdc++.h>
using namespace std;
int main()
{
   string line;
   int t;
   cin >>t;
   cin.ignore();
   for(int c=1; c<=t;c++)
   {
      cout << "Case #"<<c<<":\n";
      getline(cin,line); 
      string mtx1="";
      for(auto i:line) if(islower(i) || isupper(i)) mtx1.push_back(i);
      int n = mtx1.size(), nsq = sqrt(n); 
      string mtx2=mtx1;
      for(int i = 0; i < mtx1.size(); i++){ int r=i/nsq, c=i%nsq; mtx2[c*nsq+r]=mtx1[i];}
      if(nsq*nsq != n){cout << "No magic :(\n";continue;} 
      bool f=1;
      for(int i=0; i < n/2+n%2; i++) 
           if(mtx1[i]!=mtx1[n-i-1] || mtx2[i]!=mtx2[n-i-1]){f=0; break;}
      if(!f){cout << "No magic :(\n";continue;} 
      cout << nsq<<endl; 
   }
   return 0;
}

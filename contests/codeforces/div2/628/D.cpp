#include <bits/stdc++.h>
using namespace std;
int main()
{
 long long u, v;
 cin >> u >>v;
 if(u>v)cout <<-1<<endl;
 else if(u==v)
 {
   if(u) cout<<"1\n" << u<<endl;
   else cout <<0<<endl;
 }
 else
 {
   if( u%2!=v%2){cout << -1<<endl;return 0;};
   long long x = (v-u)/2; 
   if( (x & u) != 0) cout << 3 << "\n"<< u<<" "<<x<<" "<<x<<endl;
   else
   {
     cout <<2<<"\n"<< u+x<<" " << x<<endl;  
   }
 }
 return 0;
}

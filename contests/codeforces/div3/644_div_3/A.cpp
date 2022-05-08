#include <bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin >>t;
 while(t--)
 {
   int a1, b1, a2, b2, i;
   cin >>a1 >>b1;
   a2 = min(a1,b1);
   b2 = max(a1,b1);
   int v = 4*a2*a2;
   if( 2*a2 <= b2) v = b2*b2;
   cout << v<<endl;

 } 
 return 0;
}


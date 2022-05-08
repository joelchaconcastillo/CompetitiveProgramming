#include <bits/stdc++.h>
#define sign(n)((n>=0)?1:-1)
using namespace std;
int main()
{
   int n;
   cin >> n;
   long long int total=0, current, mindiff=INT_MAX, fsign=1;

   for(int i = 0; i < n; i++)
   {
      cin >> current;
      fsign *= sign(current);
      long long int diff = abs(abs(current)-1);
      mindiff = min(mindiff, abs(current));//min(abs(current), abs(current));
      total += diff;
   }
   if( fsign == -1 ) if( mindiff != 0 )total+=2;
   cout << total <<endl;
   return 0;
}

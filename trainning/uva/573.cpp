#include <bits/stdc++.h>
using namespace std;
int main()
{
   int H, U, D, F;
   while((cin >> H >>U >>D >>F), H > 0)
   {
      int day = 0;
      double InitialH=0.0, DistanceC=0.0, HeightAC=0.0, HAS=0.0;
      while( HeightAC <= H )
      {
	DistanceC = U-((int)100*(U*day*F))/10000.0; // ((int)U*F)/100.0;
	DistanceC = max(0.0, DistanceC);
	HeightAC = InitialH + DistanceC;
	HAS = HeightAC-D;
	InitialH = HeightAC - D;
	day++;
	if( HAS < 0) break;
      }
      if( HAS <0) cout << "failure on day ";
      else cout << "success on day ";
      cout << day <<endl;
   }
}

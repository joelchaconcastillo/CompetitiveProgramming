#include <bits/stdc++.h>
using namespace std;

int main()
{
  double Vt, V0;
//  int Vt, V0;
  while( scanf("%lf %lf", &Vt, &V0), Vt && V0)
  //while( scanf("%d %d", &Vt, &V0), Vt && V0)
 {
  ///two ways....
   //way 1
   double maxv = 0.0;
   int numberd = 0;
   for(int i = 1; ; i++)
   {
     double Vt2 = (double)Vt/i;
     if(Vt2 <= V0) break;
     double l = i*(0.3*( sqrt(Vt2  - V0)));
     if( maxv <= l)
     {
        if( fabs(l - maxv) < 1e-12)
        {
           numberd = 0;
           break;
    	}	
        numberd = i;
        maxv = l;
     }
   }
   printf("%d\n", numberd);
 ///////////////the second way...
//    //optimal point... n = VT/(2.0*V0);
//    double optimal = Vt/(2.0*V0);
//    if( Vt <= V0 ) printf("0\n");
//    else if( Vt <= 2*V0 ) printf("1\n");
//    else if( optimal - (int)optimal == 0.5) printf("0\n");
//    else if( optimal - (int)optimal < 0.5 ) printf("%d\n", (int)optimal);
//    else if( optimal - (int)optimal > 0.5 ) printf("%d\n", (int)optimal +1);

 }
  return 0;
}

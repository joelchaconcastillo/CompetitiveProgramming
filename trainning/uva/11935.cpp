#include <bits/stdc++.h>
using namespace std;
#define LEAK 1
#define MEC 2
#define GAS 3
#define FUEL 4
#define GOAL 5


vector<double> D, FC, S;
char line[1000];
int location, consumption;

double sim(double sizeTank)
{
   double TotalConsumption = sizeTank, L = 0;
   double res = 0;
   for(int i = 1; i < D.size(); i++)
   {
     double length = D[i] - D[i-1];
     TotalConsumption -= (length*FC[i-1])/100.0;
     TotalConsumption -= L*length;
     if(TotalConsumption < 0) return -1; //it is important...i.e. interrupt if the tank is empty..
     //res = max(res, TotalConsumption);

//		cout << i << ": "<< length*L <<endl;
     if(S[i] == LEAK) L++; 
     else if(S[i] == MEC) L = 0;
     else if(S[i] == GAS ) TotalConsumption = sizeTank;
   }
   return 1;
//   return res;
   return TotalConsumption;
}
int main()
{
   while(true)
   {
	 D.clear();
	 FC.clear();
	 S.clear();
	do
	{
	     scanf("%d", &location);
	     scanf(" %s", line);
	     D.push_back(location);
	     if(line[0]=='F')
	     {
		char tt[20];
	        scanf(" %s ", tt);
	        scanf("%d\n", &consumption);
		S.push_back(FUEL);
	     }
	     if( line[0] == 'G' && line[1] == 'a')
	     {
		     S.push_back(GAS);
		     char tt[20];
	             scanf(" %s\n", tt);
	     }
	     FC.push_back(consumption);
	     if( line[0] == 'L') S.push_back(LEAK);
	     else if( line[0] == 'M') S.push_back(MEC);
	     else if(line[0] == 'G' && line[1] == 'o')
	     {
		S.push_back(GOAL);	    
	     	 break;
	     }
	        if(consumption == 0) break;
	}while(true);
	if(consumption == 0) break;

//	printf("%.3f\n", sim(0));
//	continue;
//	exit(0);
	//bisection method....
	//
	double L = 0, U=1e4, M;
	while(fabs(U-L) > 0.0000001)
	{
	   M = (U+L)/2.0;
	   if(sim(M) >= 0)U = M;
	   else L=M;

//	printf("-----%.3lf  %f\n", M, sim(M));
	}
	printf("%.3f\n", M);
   }
}

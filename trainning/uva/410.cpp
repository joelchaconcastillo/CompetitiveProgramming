#include <bits/stdc++.h>
using namespace std;
int main()
{
   int C, S;
   double M[50];
   int cont = 1;
   while(scanf("%d %d\n", &C, &S) != EOF)
   {
	double AM = 0;
	for(int i = 0; i < 2*C; i++)	
	{
	   if(i < S)
		scanf("%lf ", M+i);
	   else M[i]=0;
	   AM += M[i];
	}
	AM /=C;
	sort(M, M+(2*C), greater<double>());
	printf("Set #%d", cont++);
	double IMB = 0;
	for(int i = 0; i < C; i++)
	{
	   printf("\n %d:",i);
	   if(M[i]) printf(" %.0lf", M[i]);
	   if(M[2*C-i-1]) printf(" %.0lf", M[2*C-i-1]);
	   IMB +=  abs(( M[i] + M[2*C-i-1]) - AM);
	}
	printf("\nIMBALANCE = %.5lf\n\n", IMB);
   }
}

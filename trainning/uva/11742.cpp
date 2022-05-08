#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n, m;
   while( scanf("%d %d\n", &n, &m))
   {
	   if( n == 0 && m == 0) break;

	vector<int> P(n);
	vector<int> a(m), b(m), c(m);
	for(int i = 0; i < n; i++) P[i] = i;
	for(int i = 0; i < m; i++) scanf( "%d %d %d\n", &(a[i]), &(b[i]), &(c[i]));

	int cont = 0;
	do{
		bool flag = true;
		for(int i = 0 ; i < m; i++){
		   int diff = abs( P[a[i]] - P[b[i]] );
		   if(c[i] < 0 && diff < abs(c[i])){ flag = false; break;}
		   else if(c[i] >0 && diff > abs(c[i])){ flag = false; break;}
		}
		if( flag)
		   cont++;
	}
	while(next_permutation(P.begin(), P.end()));
	printf("%d\n", cont);
   }
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   while(cin >> n)
   {
   
    int cont = 0, k1=0, k2=1, z1 = 0, z2 = k1*4, h1 = 0, h2=k2*4-2, row, col;
    while(cont < n)
    {
	row = min(z1, z2), col = min(h1, h2);
	 z1++; z2--;
	 h1++; h2--;
	if( z1 >= 4*k1+1){ k1++, z1=0, z2 = k1*4;}
	if( h1 >= 4*k2-1){ k2++, h1=0, h2 = k2*4-2;}
	cont++;
    }   
    row++;col++;
    cout <<"TERM "<<n<<" IS "<< row << "/"<<col<<endl;
    
   }
   return 0;
}

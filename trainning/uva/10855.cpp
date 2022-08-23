#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N, n;
  while(cin >> N >> n && N !=0 && n !=0)
  {
     vector< vector< char > > data1(N, vector<char> (N));
     vector< vector< char > > data2(n, vector<char> (n));
     for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++)
	   cin >> data1[i][j];

     for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)
	   cin >> data2[i][j];
     int cont1=0, cont2=0, cont3=0, cont4=0;
     for(int i = 0; i <= N-n; i++)
     {
        for(int j = 0; j <= N-n; j++)
	{
	   bool f1=true, f2=true, f3=true, f4=true;
	   for(int a = 0; a < n; a++)
	   {
	      for(int b = 0; b < n; b++)
	      {
		if(data1[i+a][j+b] != data2[a][b]) f1=false;
		if(data1[i+a][j+b] != data2[( n-(b+1))][a]) f2=false;
		if(data1[i+a][j+b] != data2[(n-(a+1))][(n-(b+1))]) f3=false;
		if(data1[i+a][j+b] != data2[b][(n-(a+1))]) f4=false;
		if( !f1 && !f2 && !f3 && !f4) break;
	      }
	      if( !f1 && !f2 && !f3 && !f4) break;
	   }
	   if( f1)cont1++;
	   if( f2)cont2++;
	   if( f3)cont3++;
	   if( f4)cont4++;
	}
     }
     cout << cont1<<" "<<cont2<<" " <<cont3<<" "<<cont4<<endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int f(int N)
{
   if((N/10) == 0)
	   return N;
   int sum = 0;
   while(N != 0){ sum+=N%10; N/=10;  }
   return f(sum);
}


int main()
{
   int N;
   while(cin >>N , N){
      cout << f(N) <<endl;
   }
}

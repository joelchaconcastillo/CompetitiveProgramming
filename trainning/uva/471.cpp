#include <bits/stdc++.h>

using namespace std;
bool check(long long n)
{
   long long s = n;
   int mask = 0;
   while(s)
   {
	if(mask & (1<<(s%10))) return false;
	mask |= (1<<(s%10));
	s /=10;
   }
   return true;
}
int main()
{
  int T;
  scanf("%d\n\n", &T);
  for(int i = 0; i < T; i++)
  {
    
     long long N;
     scanf("%lld\n\n", &N);

     if(i>0) 
     printf("\n");
     for(long long  s2 = 1 ;  s2*N <=9999999999; s2++)
     {
           if( !check(s2)) continue;
           long long s1 = s2*N;
           if( !check(s1)) continue;
//   	cout << s1 << " " <<s2<<endl;
           printf("%lld / %lld = %lld\n", s1, s2, N);
           if(s1 > 9999999999) break;
     }
  }
  return 0;
}

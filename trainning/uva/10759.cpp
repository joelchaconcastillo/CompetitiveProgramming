#include <bits/stdc++.h>
#define MAX_N 25
using namespace std;
long memo[MAX_N*MAX_N*6];
int n, x;
long gcd(long a, long b){ return (b==0)?a:gcd(b, a%b);}
long throwdice(int dice, long score)
{
   if(dice == 0) return (score<x)?0:1;
   if(memo[dice*MAX_N*6 + score]!=-1) return memo[dice*MAX_N*6 + score];
   long sum = 0;
   for(int i =1 ; i <=6; i++) sum += throwdice(dice-1, score+i);
   return memo[dice*MAX_N*6 + score] = sum;
}
int main()
{
  while(cin >> n>> x)
  {
     if( n == 0 && x==0) break;
     memset(memo, -1, sizeof memo);
     long num = throwdice(n, 0);
     if(num==0) cout <<"0"<<endl;
     else 
	{
 	  long g = gcd(num, pow(6, n));
          if( num/g == 1 && pow(6,n)/g == 1) cout <<"1"<<endl;
	  else
	  cout << fixed << num/g << "/"<<(long)pow(6, n)/g <<endl;
	}
  }
  return 0;
}

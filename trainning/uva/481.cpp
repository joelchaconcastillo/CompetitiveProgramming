#include <bits/stdc++.h>
using namespace std;
int dp[100000];
int preva[100000];
int data[100000];
int i = 0, size_dp = 0;
void DC(int L, int R, int value) //like segment tree fashion..
{
  if(L == R)
  {
   if( data[dp[L]] > value)
    {
     dp[L] = i;
     preva[i] = dp[L-1];
    }
   else if( data[dp[L]] < value)
    {
     preva[i] = dp[size_dp-1];
     dp[size_dp++] = i;
    }
   return;
  }
  int m = (L+R)/2;
  if(data[dp[m]] < value) DC(m+1, R, value);
  else if(data[dp[m]] > value) DC(L, m, value);
}
int main()
{
 int value;
 scanf("%d", &data[i++]);
 dp[size_dp++] = 0;
 preva[0]=-1;
 while(scanf("%d", &value) != EOF)
 {
   DC(0, size_dp-1, value);
   data[i++] = value;
 }
  printf("%d\n-\n", size_dp);
 stack<int> st;
 int prevv = dp[size_dp-1];
// while(prevv != -1)
 for(int k = 0; k < size_dp; k++)
 {
    st.push(data[prevv]);
    prevv = preva[prevv];
 }
 while(!st.empty())
{
    printf("%d\n", st.top());
    st.pop();
}
  return 0;
}

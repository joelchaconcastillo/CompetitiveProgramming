#include <bits/stdc++.h>
#define C 0
#define J 1
using namespace std;

int v_start[1000], v_end[1000];
int opc[1000];
int T, N;
bool bk(int cu_act, int id_C, int id_J, int v)
{
   opc[cu_act] = v;
   if(cu_act > N-1) return true;
   if(v_end[id_C] >= v_start[cu_act]) return false;
   if(v_end[id_C] >= v_start[cu_act]) return false;

   if(bk(cu_act+1, cu_act, id_J, C)) return true;
   else if(bk(cu_act+1, id_C, cu_act, J)) return true;
   return false;
}
int main()
{
 scanf("%d\n", &T);
 for(int t = 0; t < T; t++)
 {
   scanf("%d\n", &N);
   for(int i =0 ; i < N; i++)
   {
     scanf("%d %d\n", &v_start[i], &v_end[i]);
   }
   if(bk(0,-1 ,-1, C))
   {
	printf("Case #%d: ", t+1);
        for(int i = 0; i < N; i++)
          printf("%d ", opc[i]); printf("\n");
   }
   else
   {
	printf("Case #%d: IMPOSSIBLE\n", t+1);
   }
 }
 return 0;
}

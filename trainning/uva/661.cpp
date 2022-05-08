#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  long long limit, max_used=-1000000000;
  int costs[20] = {0}, cont=1;
  bool state[20] = {false};
  while(scanf("%d %d %lld", &n, &m, &limit), n && m && limit)
  {
    memset(state, false, sizeof(bool)*20);
    long long max_used=-1000000000, current_voltage = 0;
    for(int i = 0; i < n; i++) scanf("%d", costs+i);
    for(int i = 0; i < m; i++)
    {
       int id_device;
       scanf("%d\n", &id_device);
       if(!state[id_device-1]) //positive..
       {
          current_voltage += costs[id_device-1];
	  state[id_device-1] = true;
       }
	else
	{
          current_voltage -= costs[id_device-1];
	  state[id_device-1] = false;
        }
	max_used = max(max_used, current_voltage);
    }    
    printf("Sequence %d\n", cont++);
    if( max_used <= limit)
       printf("Fuse was not blown.\nMaximal power consumption was %lld amperes.\n\n", max_used);
    else
       printf("Fuse was blown.\n\n");
  }
  return 0;
}

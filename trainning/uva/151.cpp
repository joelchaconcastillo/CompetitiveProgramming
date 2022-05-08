#include <bits/stdc++.h>
using namespace std;
void next(list<int> &ml, list<int>::iterator &current)
{
    current++;
  if( current == ml.end()) current = ml.begin();
}
bool turning_off(list<int> cities, int m)
{
  auto current = cities.begin(); 
  while(!cities.empty())
  {
    if((*current) == 13 && cities.size() == 1) return true;
    else if((*current) == 13 && cities.size() != 1) return false;
    auto prev = current;
    next(cities, current);
    cities.erase(prev);
    for(int i = 0; i < m-1; i++) 
       next(cities, current);
  }
  return false;
}
int main()
{
  int N;
  while(scanf("%d\n", &N) != EOF && N!=0)
  {
    list<int> cities;
    for(int i = 1; i <=N; i++) cities.push_back(i);
   for(int i = 1; i<=N*N; i++)
   {
      if( turning_off(cities, i))
	{
	  printf("%d\n", i); break;
	}

   }
  }
  return 0;
}

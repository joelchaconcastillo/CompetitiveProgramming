#include <bits/stdc++.h>
#define MAX 21

using namespace std;

int cost[MAX];
int T;
pair<int, vector<int> > bk(int rem, int current, vector<int> selected)
{
  if(rem < 0) return make_pair(INT_MAX, selected);
  if(current == T-1) return make_pair(rem, selected);
  pair<int, vector< int > > best;
  best.first=INT_MAX;
  for(int i = current+1; i < T; i++)
  {
     selected.push_back(cost[i]);
     pair<int, vector<int> > cur_rem = bk(rem-cost[i], i, selected);
     if( cur_rem.first < best.first) best = cur_rem;
     selected.pop_back();
  } 
  if( best.first == INT_MAX) return make_pair(rem, selected);
  return best;
}
int main()
{
  int N;
  while(scanf("%d ", &N) != EOF)
  {
    scanf("%d ", &T);	
    for(int i = 0; i < T; i++)
      scanf("%d", cost+i);
    vector<int> selected;
    pair<int, vector<int> > best_costs = bk(N, -1, selected); 
    for(int i = 0; i < best_costs.second.size(); i++) printf("%d ", best_costs.second[i]);
    printf("sum:%d\n", N-best_costs.first);
  }
  return 0;
}

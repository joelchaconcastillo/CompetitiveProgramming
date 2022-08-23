#include <bits/stdc++.h>
<<<<<<< HEAD
using namespace std;
const int MAX_N = 1e5+5;
const int MAX_Q= 1e5+5;
tuple<int, int, long long> p[MAX_N];
vector<tuple<int, int, long long> > adj[MAX_N]; //id, Limit, charge
//map<int,  vector< tuple<long long, int> > >queries; //node, weight, day
vector< tuple<long long, int> > queries[MAX_N];
pair<int, long long> path[MAX_N];
void build_tree(int current, int prev)
{
  if(current == 0) p[0]={0,0,0};
  for(auto i:adj[current])
  {
     int next=get<0>(i);
     if(next==prev)continue;
     p[next]=i;
     get<0> (p[next]) = current;
     build_tree(next, current);
  } 
}
long long gcd(long long a, long long b){return (b==0)?a:gcd(b, a%b);}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
=======
const int MAX_N = 1e5+5;
using namespace std;
int p[MAX_N];
vector<int> tree[MAX_N];
vector<tuple<int, int, long long> > adj[MAX_N]; //id, Limit, charge
vector<tuple<int, int, int> >queries; //node, weight, day
void build_tree(int current, int prev)
{
  p[current]=prev;
  for(auto i:adj[current])
  {
     if(get<0>(i)==prev)continue;
     tree[current].push_back(get<0>(i));
     build_tree(get<0>(i), current);
  } 
}
int main()
{
>>>>>>> 56f4b95dde047cbd01b2ae64a4b845bac31963e4
  int ite;
  cin>>ite;
  for(int t = 1; t <= ite;t++)
  {
<<<<<<< HEAD
	  cerr<<t<<endl;
    int N, Q;
    cin>>N >>Q;
    for(int i = 0; i < N-1; i++)
    {
	int X, Y, L;
	long long A;
=======
    int N, Q;
    cin>>N >>Q;
//    p.assign(N, 0);
//    Li.assign(N, 0);
//    Ai.assign(N, 0);
//    adj.assign(N, vector<int>());
//    tree.assign(N, vector<int>());
    for(int i = 0; i < N-1; i++)
    {
	int X, Y, L, A;
>>>>>>> 56f4b95dde047cbd01b2ae64a4b845bac31963e4
	cin>>X>>Y>>L>>A;
	X--, Y--;
	adj[X].push_back({Y, L, A});
	adj[Y].push_back({X, L, A});
    }
    build_tree(0, 0);
<<<<<<< HEAD
    fill_n(adj, N, vector<tuple<int, int, long long> >());
    fill_n(queries, N, vector< tuple<long long, int> >());
    for(int i = 0; i < Q; i++)
    {
	int node; long long W;
	cin>>node>>W;
	node--;
	queries[node].push_back({W, i});
    }
    vector<long long>outcome(Q);
//    for(auto &node_queries:queries) //check each node..
    for(int ii = 0; ii < N; ii++)
    {
      if(queries[ii].empty())continue;
      long long rem_gcd = 0;
      auto &node_q = queries[ii];
      int current_node = ii;//node_queries.first;
      int idx=0;
      while(current_node != 0) path[idx++]={get<1>(p[current_node]), get<2>(p[current_node])}, current_node = get<0> (p[current_node]);
      sort(node_q.begin(), node_q.end());
      sort(path, path + idx);
      cerr<<ii<< "__"<< N<<endl;
      int sno=node_q.size();
      for(int i=0, j = 0; i < sno; i++)
      {
         int weight, day;
         tie(weight, day) = node_q[i];
  	while(j < idx && get<0> (path[j]) <= get<0>(node_q[i]))
  	{
	   if(!rem_gcd) rem_gcd = get<1>(path[j]);
	   else rem_gcd = gcd(rem_gcd, get<1>(path[j]));
  	   j++;	
  	}
	outcome[day] = rem_gcd;
      }
    }
    cout <<"Case #"<<t<<":";
    for(auto qidx:outcome)
	   cout << " "<<qidx;
	cout <<endl;
=======
    queries.clear();
    for(int i = 0; i < Q; i++)
    {
	int node, W;
	cin>>node>>W;
	node--;
	queries.push_back({node, W, i});
    }
    sort(edges, edges+N-1);
    sort(queries.begin(), queries.end());
    for(auto i:adj) cout << get<0>  
   exit(0);
>>>>>>> 56f4b95dde047cbd01b2ae64a4b845bac31963e4
  }
  return 0;
}

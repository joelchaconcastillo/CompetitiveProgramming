/********************************************************************************
  Authors: Carlos Segura, Emmanuel Romero Ruíz, Gabriel Tadeo Vazquez Ballesteros 
	and Mario Guzman Silverio

	Description: class to represent a new algorithm which is a variation of Dinic
	that tries to solve heuristically a matching problem with a special structure.
	The underlying graph is bipartite and can be seen as tasks and agents. Each
	agent i can perform T_i tasks, and each task j has an associated score S_j.
	We want to maximize the scores of the tasks performed with the contraints that 
	each agent does not develop more than T_i tasks.
	This problem can be solved with minimum-cost maximum flow but it is costly.
	This algorithm is a variation of Dinic with that work as follows.
	First, it create a graph with the following structure:
	- There is a node for each task and agent as well as a source and a sink.
	- Each edge has two features: capacity and priority.
	- The source is joined to each task by creating nodes with capacity one
	and priority the score of the task. The inverted edge that might appear
	in the residual graph has priority equal to the negative of the score.
	- Each task is joined to the agents that can perform that task with
	capacity one and priority equal to the score of the task. The inverted
	edge that might appear in the residual graph has priority equal to the negative
	of the score.
	- Each agent is joined to the sink with capacity equal to the number of
	tasks that be done by the agent and with priority Infinity. The iverted
	edge that might appear in the residual graph has priority equal to minus
	infinity.
	- The list of edges that go out from each node are sorted by the 
	priority. 
	- The Dinic algorithm is applied by considering such an order of the edges
	and considering N phases, where in the phase i, only the edges with an 
	absolute value of the priority larger or equal to 
	(Max_Value) / (i * MaxValue / N)) are taken into account. Note that this
	is somewhat similar to the Dinic approach based on scaling but the 
	activation of edges is made by priority instead of by remaining capacity.
********************************************************************************/

const int MAXV = 1000000;

template <class T = long long> struct AMC_Dinic {
	AMC_Dinic(vector<int> &taskScores, vector < long long > &agentsCap, vector< vector < int > > &agentsToTasks, int steps){ 
		//Initialize number of stages of Dinic and number of vertexes
		divSteps = steps;
		V = taskScores.size() + agentsCap.size() + 2;
		if (V > MAXV){ 
			cout << "Error - The graph is too large"; 
			exit(0); 
		}

		//Get the maximum score and establish all tasks as not doable.
		bool doableTasks[taskScores.size()];
		for (int i = 0; i < taskScores.size(); i++){
			doableTasks[i] = false;
			maxScore = max(maxScore, taskScores[i]);
		}


		//Create underlying graph as explained in the description
		//Edges from active agents to tasks (and mark task as doable)
		for (int i = 0; i < agentsCap.size(); i++){
			if (agentsCap[i]){
				for (auto task : agentsToTasks[i]){
					addEdge(1 + task, 1 + taskScores.size() + i, 1, true, taskScores[task], -taskScores[task]);
					doableTasks[task] = true;
				}
			}
		}
		//source to doable tasks 
		for (int i = 0; i < taskScores.size(); i++){
			if (doableTasks[i]){
				addEdge(0, 1 + i, 1, true, taskScores[i], -taskScores[i]);//TODO: check. Changed from original code
			}
		}
		//agents with capacity to sink
		for (int i = 0; i < agentsCap.size(); i++){
			if (agentsCap[i]){
				addEdge(1 + taskScores.size() + i, 1 + taskScores.size() + agentsCap.size(), agentsCap[i], true, 1e9, 1e9);
			}
		}
	}
	
	int divSteps;//Number of stages in AMC-Dinic
	int maxScore;//Maximum score: used to establish the maximum value of each stage
	int s;//source
	int t;//sink
	int V;//Number of vertexes
	int threshold;//Priority required by an edge to be considered active
	int level[MAXV];//Distance of the source to each node 
	int ptr[MAXV];//Next edge to explore in this vertex 

	struct edge {
		int to, rev;//Destination of the edge, and index of the reversed edge in the residual graph
		T cap, flow, mcap;//Capacity, Flow, Maximum capacity that this edge might get
		int priority;//Priority: one of the novelties of the algorithm as explained in the description
		bool operator<(const edge &e2) const { return ((priority) > (e2.priority)); }
	};

	vector< edge > adj[MAXV];//All edges going out from a node
	vector < int > adjCurrent[MAXV];//Indexes of active edges, i.e. those that have enough priority, have remaining capacity and belong to the level graph

	//From, to, capacity, directed? and priority in each direction
	void addEdge(int a, int b, T cap, bool isDirected, int p1, int p2) {
		if (a == b) return;
		adj[a].push_back({b, (int )adj[b].size(), cap, 0, cap + (isDirected?(0):(cap)), p1});
		adj[b].push_back({a, (int)(adj[a].size() - 1), isDirected ? 0 : cap, 0, cap + (isDirected?(0):(cap)), p2});
	}

	//Sort the edges in each node by priority. The order of edges with equal priority is not important
	void mysort(){
		for (int i = 0; i < V; i++){
			sort(adj[i].begin(), adj[i].end());
			for (int j = 0; j < adj[i].size(); j++){
				adj[adj[i][j].to][adj[i][j].rev].rev = j;
			}
		}
	}

	//Create the level graph, taking into account that only edges with enough priority must be considered
	bool bfs() {
		//Reset
		for (int i = 0; i < V; i++){ adjCurrent[i].clear(); adjCurrent[i].reserve(adj[i].size()); }
		//Do bfs from the source
		queue<int> q;
		q.push(s);
		fill(level, level + V, -1);
		level[s] = 0;
 		while (!q.empty()) {
			int v = q.front();
			if (v == t)	return true;//No need to continue, remaining ones are not in the level graph to t
			q.pop();
			if (level[v] == level[t]) continue;
			for (int i = 0; i < (int)(adj[v].size()); i++){
				edge &e = adj[v][i];
				if ((level[e.to] == -1) && (abs(e.priority) >= threshold) && (e.cap - e.flow >= 1)){
					level[e.to] = level[v] + 1;
					adjCurrent[v].push_back(i);
					q.push(e.to);
					if (e.to == t){//No need to check other edges going out from v: they will not belong to the level graph to t
						break;
					}
				} else if ((level[e.to] == level[v] + 1) && (abs(e.priority) >= threshold) && (e.cap-e.flow != 0)){
					adjCurrent[v].push_back(i);
					if (e.to == t){//No need to check other edges going out from v: they will not belong to the level graph to t
						break;
					}

				}
			}
		}
		return false;
	}

	//Find a path from v to t and modify the residual graph
	//by considering the found path
	int path[MAXV];//used to avoid recursive algorithm
	T dfs(int v) {
		int visited = 0;
		int current = v;
		path[visited] = current;
		if (adjCurrent[current].size() == ptr[current]) return 0;//There are not paths from v
		while(true){
			//Visit next one
			edge &e = adj[current][adjCurrent[current][ptr[current]]];
			current = e.to;
			visited++;
			path[visited] = current;
			if (current == t) break;//A path was found. Finish
			while(adjCurrent[current].size() == ptr[current]){//While there are no additional edges
				//Go back
				visited--;
				//No path found
				if (visited == -1) return 0;
				current = path[visited];
				//Advance to the next edge
				ptr[current]++;
			}
		}
		//Recover the path and modify the flow in the edges and reverse edges
		for (int i = 0; i < visited; i++){
			int v = path[i];
			edge &e = adj[v][adjCurrent[v][ptr[v]]];
			e.flow++; 
			adj[e.to][e.rev].flow--;
			if ((e.cap - e.flow) == 0){//Advance the edge in the list of nodes if it gets empty
				ptr[v]++;
			}
		}
		return 1;
 	}

	//Calculate a maximum flow from source to sink and heuristically
	//optimize the sum of the scores
	long long calc(int source, int sink) {
		s = source;
		t = sink;
		mysort();
		long long flow = 0;
		//Calculate the change required at each step, so that we perform
		//divSteps phases to reach a threshold equal to one
		threshold = maxScore;
		int divChange = round((double)(threshold - 1) / divSteps);
		divChange = max(divChange, 1);
		while(threshold != 1){
			threshold -= divChange;
			threshold = max(threshold, 1);
			while (bfs()) {//While there is a path from source to sink
				fill(ptr, ptr + V, 0);//Reset the already explored edges
				while (T pushed = dfs(s)){ flow += pushed; }//Find path and block it
			}
		}
		return flow;
	}
};


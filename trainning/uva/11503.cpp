#include <bits/stdc++.h>
using namespace std;

map<string, string> parent;
map<string, int> Rank;
map<string, int> size;

string find(string node)
{
	if( parent[node] == node) return node;
	else
	   return (parent[node] =find(parent[node]));
}
int unionSet(string A, string B)
{
	string rootA = find(A);
	string rootB = find(B);
        if( rootA == rootB ) return size[rootA];
        if( Rank[rootA] < Rank[rootB] )
	{
	   parent[rootA] = rootB; 
	   size[rootB] += size[rootA];
	    return size[rootB];
	  
	}
	else
	{
	   parent[rootB] = rootA; 
	   if( Rank[rootA] == Rank[rootB] ) Rank[rootA]++;
	   size[rootA] += size[rootB];
	   return size[rootA];
	}
}

int main()
{
 int n, F;
 char nameA[21], nameB[21];
 scanf("%d\n", &n);
 for(int i = 0; i < n; i++)
    {
	    scanf("%d\n", &F);
	    parent.clear();
	    Rank.clear();

	    for(int j = 0; j < F; j++)
            {
	       scanf("%s %s\n", nameA, nameB);
		if(!parent.count(nameA))
		{
		 parent[nameA]=nameA;
		 Rank[nameA]=0;
		 size[nameA]=1;
		}
		if(!parent.count(nameB))
		{
		 parent[nameB]=nameB;
		 Rank[nameB]=0;
		 size[nameB]=1;
		}
	        cout << unionSet(nameA, nameB) << endl;
	    }
	    
    }

}

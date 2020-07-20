#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // Pointer to an array containing adjacency lists 
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic() 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // to add an edge to graph 
    void clearEdges();
    bool isCycle();    // returns true if there is a cycle in this graph 
    void topologicalSort();
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
void Graph::clearEdges() {
	for (int i = 0; i < this->V; i++) adj[i].clear();
}
// Returns true if the graph contains a cycle, else false. 
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCycle() 
{ 
    // Create a vector to store indegrees of all 
    // vertices. Initialize all indegrees as 0. 
    vector<int> in_degree(V, 0); 
  
    // Traverse adjacency lists to fill indegrees of 
    // vertices. This step takes O(V+E) time 
    for (int u = 0; u < V; u++) { 
        for (auto v : adj[u]) 
            in_degree[v]++; 
    } 
  
    // Create an queue and enqueue all vertices with 
    // indegree 0 
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 
  
    // Initialize count of visited vertices 
    int cnt = 0; 
  
    // Create a vector to store result (A topological 
    // ordering of the vertices) 
    vector<int> top_order; 
  
    // One by one dequeue vertices from queue and enqueue 
    // adjacents if indegree of adjacent becomes 0 
    while (!q.empty()) { 
  
        // Extract front of queue (or perform dequeue) 
        // and add it to topological order 
        int u = q.front(); 
        q.pop(); 
        top_order.push_back(u); 
  
        // Iterate through all its neighbouring nodes 
        // of dequeued node u and decrease their in-degree 
        // by 1 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) 
  
            // If in-degree becomes zero, add it to queue 
            if (--in_degree[*itr] == 0) 
                q.push(*itr); 
  
        cnt++; 
    } 
  
    // Check if there was a cycle 
    if (cnt != V)  
        return true; 
    else
        return false; 
} 

void Graph::topologicalSort() 
{ 
    // Create a vector to store indegrees of all 
    // the vertices 
    // Initialize all indegrees to 0 
    vector<int> in_degree(V, 0); 
  
    // Traverse adjacency lists to fill indegrees of 
    // vertices 
    // This step takes O(V+E) time 
    for (int u = 0; u < V; u++) { 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) 
            in_degree[*itr]++; 
    } 
  
    // Create a set and inserting all vertices with 
    // indegree 0 
    multiset<int> s; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            s.insert(i); 
  
    // Initialize count of visited vertices 
    int cnt = 0; 
  
    // Create a vector to store result (A topological 
    // ordering of the vertices) 
    vector<int> top_order; 
  
    // One by one erase vertices from setand insert 
    // adjacents if indegree of adjacent becomes 0 
    while (!s.empty()) { 
  
        // Extract vertex with minimum number from multiset 
        // and add it to topological order 
        int u = *s.begin(); 
        s.erase(s.begin()); 
        top_order.push_back(u); 
  
        // Iterate through all its neighbouring nodes 
        // of erased node u and decrease their in-degree 
        // by 1 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) 
  
            // If in-degree becomes zero, add it to queue 
            if (--in_degree[*itr] == 0) 
                s.insert(*itr); 
  
        cnt++; 
    } 
  
    // Check if there was a cycle 
    if (cnt != V) { 
        cout << -1; 
        return; 
    } 
  
    // Print topological order 
    for (int i = 0; i < (int) top_order.size(); i++) 
        cout << top_order[i] + 1 << (i == (int) top_order.size() - 1 ? '\n' : ' '); 
}

const int mxN = 1e5 + 5, mxM = 5e4 + 5;

int N, M;
vii edges[mxM];
 
inline int bin() {
	int mid;
	int low = 0, up = M;
	Graph g(N);
	while (low < up - 1) {
		mid = low + (up - low) / 2;
		g.clearEdges();
		for (int i = 0; i < mid; i++) {
			for (auto edge : edges[i]) {
				g.addEdge(edge.first, edge.second);
			}
		}
		if (!g.isCycle()) 
			low = mid;
		else
			up = mid;
	}
	g.clearEdges();
	for (int i = 0; i < low; i++) {
		for (auto edge : edges[i]) {
			g.addEdge(edge.first, edge.second);
		}
	}
	if (!g.isCycle()) return low;
	else return up;
}

int main() {
	setIO("milkorder");
	cin >> N >> M;
	int mi, a, b;
	for (int i = 0; i < M; i++) {
		cin >> mi >> a;
		a--;
		for (int j = 0; j < mi - 1; j++) {
			cin >> b;
			b--;
			edges[i].pb(ii(a, b));
			a = b;
		}
	}
	int X = bin();
	Graph g2(N);
	for (int i = 0; i < X; i++) {
		for (auto edge : edges[i]) {
			g2.addEdge(edge.first, edge.second);
		}
	}
	g2.topologicalSort();
}

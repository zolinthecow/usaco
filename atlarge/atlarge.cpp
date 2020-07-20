#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 252645135
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e5 + 5;

int N, K;

vi adjList[mxN];

int bDist[mxN];
int distToLeaves[mxN];

unordered_set<int> leaves;

int ans = 0;

void bfs1() {
	queue<int> q; q.push(K);
	bDist[K] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if (adjList[u].size() == 1) leaves.insert(u);
		for (auto v : adjList[u]) {
			if (bDist[v] == INF) {
				bDist[v] = bDist[u] + 1;
				q.push(v);
			}
		}
	}
}

void bfs2() {
	queue<int> q;
	for (auto it : leaves) {
		q.push(it);
		distToLeaves[it] = 0;
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : adjList[u]) {
			if (distToLeaves[v] == INF) {
				distToLeaves[v] = distToLeaves[u] + 1;
				q.push(v);
			}
		}
	}
}

void bfs3() {
	queue<int> q; q.push(K);
	int visited[mxN];
	memset(visited, 0, sizeof(visited));
	visited[K] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (leaves.find(u) != leaves.end()) {
			ans++;
		}
		for (auto v : adjList[u]) {
			if (!visited[v] && bDist) {
				
				q.push(v);
				visited[v] = 1;
			} else {
				if (bDist[v] < bDist[u] && bDist[v] < distToLeaves[v]) {
					q.push(v);
					visited[v] = 1;
				}
			}
		}
	}
}

int main() {
	setIO("atlarge");
	memset(distToLeaves, 0xF, sizeof(distToLeaves));
	memset(bDist, 0xF, sizeof(bDist));
	cin >> N >> K;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	bfs1();
	bfs2();
	bfs3();
	cout << ans << endl;
}

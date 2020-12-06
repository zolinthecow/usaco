#include <bits/stdc++.h>
using namespace std;

const int INF = 1061109567;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
}

const int mxN = 1e5 + 5;

int N, Q;
int vals[mxN];
vector<int> adjList[mxN];

int timer = 0, tin[mxN], tout[mxN];
int anc[mxN][18];

void dfs(int node = 1, int parent = 1) {
	tin[node] = ++timer;
	anc[node][0] = parent;
	for (int i = 1; i < 18; i++)
		anc[node][i] = anc[anc[node][i - 1]][i - 1];
	
	for (int i : adjList[node]) if (i != parent) dfs(i, node);
	tout[node] = ++timer;
}

bool is_anc(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (is_anc(u, v))
		return u;
	if (is_anc(v, u))
		return v;
	for (int i = 17; i >= 0; i--) 
		if (!is_anc(anc[u][i], v))
			u = anc[u][i];
	return anc[u][0];
}

int bit[2 * mxN];

void update(int pos, int val) { for (; pos <= 2 * N; pos += (pos & (-pos))) bit[pos] ^= val; }

int query(int pos) {
	int ans = 0;
	for (; pos; pos -= (pos & (-pos))) ans ^= bit[pos];
	return ans;
}

int range(int u, int v, int lca) {
	return query(u) ^ query(v) ^ vals[lca];
}

int main () {
	setIO("cowland");
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> vals[i];
	int u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	dfs();
	for (int i = 1; i <= N; i++) update(tin[i], vals[i]), update(tout[i], vals[i]);
	while (Q--) {
		int t, i, j;
		cin >> t >> i >> j;
		if (t == 1) {
			update(tin[i], vals[i]);
			update(tout[i], vals[i]);
			vals[i] = j;
			update(tin[i], j);
			update(tout[i], j);
		} else {
			cout << range(tin[i], tin[j], lca(i, j)) << endl;
		}
	}
}

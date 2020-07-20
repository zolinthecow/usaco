#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	//freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e5 + 5;

int N;
int timer = 0, tin[mxN], tout[mxN];

void dfs(int node = 1, int parent = 1) {
	tin[node] = ++timer;
    anc[node][0] = parent;
    for (int i = 1; i < 18; i++)
        anc[node][i] = anc[anc[node][i - 1]][i - 1];

    for (int i : adjList[node]) if (i != parent) dfs(i, node);
    tout[node] = ++timer;
}

bool is_anc(int u, int v) {
	return tin2[u] <= tin2[v] && tout2[u] >= tout2[v];
}

int lca(int u, int v) {
    if (is_anc(u, v))
		return u;
	if (is_anc(v, u)) 
		return v;
	for (int i = 17; i >= 0; i--) {
		if (!is_anc(anc[u][i], v))
			u = anc[u][i];
	}
	return anc[u][0];
}

void preprocess() {
	dfs();
}

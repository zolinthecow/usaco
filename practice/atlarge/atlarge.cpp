#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define mp make_pair

#define LSOne(S) (S & (-S))

const int INF = 1061109567;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
}

const int mxN = 1e5 + 5;

int N, K;
vi adjList[mxN];

int bDist[mxN];
int fDist[mxN];

//calc bdist
void dfs1(int u, int p = -1) {
	for (auto v : adjList[u]) {
		if (v == p) continue;
		bDist[v] = bDist[u] + 1;
		dfs1(v, u);
	}
}

//calc closest leaf
int dfs2(int u, int p = -1) {
	int l = u, best = INF;
	for (auto v : adjList[u]) {
		if (v == p) continue;
		int vLeaf = dfs2(v, u);
		if (bDist[vLeaf] - bDist[u] < best) {
			best = bDist[vLeaf] - bDist[u];
			l = vLeaf;
		}
	}
	fDist[u] = (best == INF) ? 0 : best;
	return l;
}

int dfs3(int u, int p = -1) {
	if (adjList[u].size() == 1) return 1;
	else if (adjList[u].size() == 2 && p != -1) {
		int ret;
		for (auto v : adjList[u]) {
			if (v == p) continue;
			ret = dfs3(v, u);
		}
		return ret;
	} else {
		if (bDist[u] < fDist[u]) {
			int ret = 0;
			for (auto v : adjList[u]) {
				if (v == p) continue;
				ret += dfs3(v, u);
			}
			return ret;
		} else {
			int ret = INF;
			for (auto v : adjList[u]) {
				if (v == p) continue;
				ret = min(ret, dfs3(v, u));
			}
			return ret;
		}
	}
}

int main () {
    setIO("atlarge");	
	cin >> N >> K;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	dfs1(K);
	dfs2(K);
	cout << dfs3(K) << '\n';
}

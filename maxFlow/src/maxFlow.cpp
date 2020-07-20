#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ii pair<ll, ll>
#define dd pair<double, double>
#define vi vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vdd vector<dd>
#define vs vector<string>
#define ll long long
#define INF 10000000
#define MOD 10000000
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 5e4, mxK = 1e5;

vi adj[mxN + 1];

vi decDepth;

int p[mxN + 1], depth[mxN + 1], anc[mxN + 1][17];

int ans[mxN + 1];

int N, K;

int getP(int curr, int wantedD) {
	for (int k = 16; depth[curr] != wantedD; k--) {
		while(depth[curr] - (1 << k) >= wantedD) {
			curr = anc[curr][k];
		}
	}
	return curr;
}

void genLCA() {
	for (int i = 1; i <= N; i++) {
		anc[i][0] = p[i];
	}
	for (int j = 1; j < 17; j++) {
		for (int i = 1; i <= N; i++) {
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
		}
	}
}

int lca(int a, int b) {
	if (depth[a] > depth[b]) {
		return lca(b, a);
	}
	if (depth[a] < depth[b]) {
		b = getP(b, depth[a]);
	}
	for (int k = 16; k > 0; k--) {
		while(anc[a][k] != anc[b][k]) {
			a = anc[a][k];
			b = anc[b][k];
		}
	}
	while (a != b) {
		a = p[a];
		b = p[b];
	}
	return a;
}

void dfs1(int on = 1, int par = -1) {
	decDepth.pb(on);
	for (auto v : adj[on]) {
		if (v == par) continue;
		p[v] = on;
		depth[v] = depth[on] + 1;
		dfs1(v, on);
	}
}

int main() {
	setIO("maxflow");
	cin >> N >> K;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i = 0; i <= mxN; i++) {
		p[i] = -1;
	}
	p[1] = 0;
	p[0] = 0;
	dfs1();
	genLCA();
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		ans[a]++;
		ans[b]++;
		int l = lca(a,b);
		ans[l]--;
		ans[p[l]]--;
	}
	while (decDepth.size()) {
		int on = decDepth.back();
		decDepth.pop_back();
		ans[p[on]] += ans[on];
	}
	int res = 0;
	for (int i = 1; i <= N; i++) {
		res = max(res, ans[i]);
	}
	cout << res << "\n";
}

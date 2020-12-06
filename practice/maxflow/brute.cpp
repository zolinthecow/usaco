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
    freopen((name).c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

const int mxN = 10;

int N, K;
vi adjList[mxN];

int nums[mxN];

void dfs(int u, int en, vi path, int p = -1) {
	if (u == en) {
		for (auto v : path) {
			nums[v]++;
		}
	}
	for (auto v : adjList[u]) {
		if (v == p) continue;
		path.pb(v);
		dfs(v, en, path, u);
		path.pop_back();
	}
}

int main () {
	//setIO("int");
	cin >> N >> K;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		dfs(a, b, vi{a});
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, nums[i]);
	}
	cout << ans << '\n';
}

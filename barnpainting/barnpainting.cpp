#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define LSOne(S) (S & (-S))
#define MOD 1000000007

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const ll mxN = 1e5 + 5, mxK = 1e5 + 5;

ll N, K;
vi adjList[mxN];
ll colors[mxN];

ll memo[mxN][4];

ll dfs(ll on, ll p, ll c, ll pc) {
	if (c == pc || (colors[on] > 0 && c != colors[on])) return 0;
	if (memo[on][c] != -1) return memo[on][c];
	ll ans = 1;
	for (auto v : adjList[on]) {
		if (v == p) continue;
		ll branch = 0;
		for (ll i = 1; i <= 3; i++) {
			branch += dfs(v, on, i, c);
			branch %= MOD;
		}
		ans *= branch;
		ans %= MOD;
	}
	memo[on][c] = ans;	
	return ans;
}

int main() {
	setIO("barnpainting");
	memset(memo, -1, sizeof(memo));
	cin >> N >> K;
	ll a, b;
	for (ll i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	for (ll i = 0; i < K; i++) {
		cin >> a >> b;
		colors[a] = b;
	}
	ll ans = dfs(1, -1, 1, -1) + dfs(1, -1, 2, -1) + dfs(1, -1, 3, -1);
	cout << ans % MOD << endl;
}

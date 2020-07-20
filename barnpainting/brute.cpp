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
	//freopen((s + ".in").c_str(), "r", stdin);
	//freopen((s + ".out").c_str(), "w", stdout);
}

const ll mxN = 1e5 + 5, mxK = 1e5 + 5;

ll N, K;
vi adjList[mxN];
ll colors[mxN];

vector< vi > combos;

ll dfs(ll on, ll combo, ll p, ll pc) {
	ll c = combos[combo][on - 1];
	if (c == pc || (colors[on] > 0 && c != colors[on])) return 0;
	for (auto v : adjList[on]) {
		if (v == p) continue;
		ll check = dfs(v, combo, on, c);
		if (check == 0) return 0;
	}
	return 1;
}

int main() {
	setIO("barnpainting");
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
	queue< vi > q;
	q.push(vi{1}); q.push(vi{2}); q.push(vi{3});
	while (!q.empty()) {
		vi on = q.front(); q.pop();
		if ((ll) on.size() == N) {
			combos.pb(on);
			continue;
		}
		for (ll i = 1; i <= 3; i++) {
			on.pb(i);
			q.push(on);
			on.pop_back();
		}
	}
	ll ans = 0;
	for (ll i = 0; i < (ll) combos.size(); i++) {
		ans += dfs(1, i, -1, -1);
		ans %= MOD;
	}
	cout << ans << endl;
}
